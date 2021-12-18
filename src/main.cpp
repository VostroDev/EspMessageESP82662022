#include <Arduino.h>

/*----------------------------------------------------------------------------------------
  17/07/2019
  Author: R WILSON
  Platforms: ESP8266 NODEMCU V1.0
  Version: 3.1.0 - 14 DEC 2021
  Language: C/C++/Arduino
  File: 2018_Scrolling_Message_v3.1.ino
  ----------------------------------------------------------------------------------------
  Description:
  ESP8266 connected to MAX7219 LED matrix displays using Hardware SPI
  HARDWARE_TYPE MD_MAX72XX::FC16_HW
  MAX_DEVICES 4
  CLK_PIN  D5  ESP8266 SCK  (green)
  DATA_PIN D7  ESP8266 MOSI (orange)
  CS_PIN   D6  ESP8266 SS   (yellow)
  RTC DS3231 I2C - SDA(D3) and SCL(D4)
  TEMP SENSOR BUILD INTO DS3231
  ----------------------------------------------------------------------------------------
  Libraries:
  Boards URL for ESP8266 http://arduino.esp8266.com/stable/package_esp8266com_index.json
  MAX7219 Dot matrix lib https://github.com/MajicDesigns/MD_MAX72xx (lib version 3.3.0)
  MAX7219 Effects lib https://github.com/MajicDesigns/MD_Parola     (lib version 3.5.6)
  Adafruit RTC Lib: https://github.com/adafruit/RTClib              (lib version 2.0.1)
  ArduinoJson Benoit Blanchon: https://arduinojson.org              (lib version 6.18.5)
  MTR Datepicker: http://mtrdesign.github.io/mtr-datepicker/
  
  Connect to ESPMessageBoard WIFI AP created by ESP8266  
  Open browser to http://192.168.4.1/ or www.message.com
  password password or 12345678 or 123456
  Enter message to be displayed on the MAX7219 scrolling display
----------------------------------------------------------------------------------------*/

#include <Arduino.h>
#include <SPI.h>
#include "EEPROMHandler.h"                    // Storing message into permanent memory 
#include "index.h"                            // HTML message webpage with javascript
#include "settings.h"                         // HTML settings webpage with javascript
#include "timehtml.h"                         // HTML settings webpage with javascript
#include "timepicker.h"                       // HTML settings webpage with javascript

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>
#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include "RTClib.h"

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 8
#define CLK_PIN  D5
#define DATA_PIN D7
#define CS_PIN   D6
#define P_CHAR   '`'
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

//char* ssid = "ESPMessageBoard";                 // Change to your name
//char* password = "12345678";
char ssid[] = "ESPMessageBoard";
char password[] = "12345678";

uint8_t degC[]   = {6, 3, 3, 56, 68, 68, 68 };  // Deg C (Custom Char)
uint8_t dotF[]   = {2, 60, 60};                 // dot
uint8_t colonF[] = {2, 102, 102};               // colon
uint8_t dashF[]  = {3, 8, 8, 8};                // short dash

uint16_t h = 0;
uint16_t m = 0;
RTC_DS3231 RTC;

const byte DNS_PORT = 53;

IPAddress ip(192,168,4,1);
IPAddress subnet(255,255,255,0);

DNSServer dnsServer;
ESP8266WebServer server(80);

#define INTENSITY   3                         // intensity of the display
#define SPEED_TIME  25
#define PAUSE_TIME  0

#define BUF_SIZE    400                       // 400 out of 512 used
#define PASS_BSIZE  40                        // 40 out of 512 used
#define PASS_EXIST  450                       // password $ address
#define PASS_BEGIN  460                       // password value stored

DateTime now;                                 // Decalre global variable for time
char szTime[14];                              // hh:mm\0
char szMesg[BUF_SIZE] = "";
char daysOfTheWeek[7][4] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

char curMessage[BUF_SIZE] = "Vostro Message Board ";
char newMessage[BUF_SIZE] = "Vostro Message Board";
char newTime[6] = "00:00";
bool newMessageAvailable = true;
bool newTimeAvailable = false;

void handleTimeUpdate(){
  String data = server.arg("plain");
  server.send(200, "text/json", "{\"status\" : \"ok\", \"time\" : \"" + data + "\"}");  // log to console
  delay(100);

  //int yr, mnth, d, h, m, s;
  
  data.toCharArray(newTime, data.length() + 1);                   // read new time
  newTimeAvailable = (strlen(newTime) != 0);                      // if not a blank field
  
  Serial.print("new time: ");
  Serial.println(data);  
}

void handleMessageUpdate(){
  String data = server.arg("plain");
  server.send(200, "text/json", "{\"status\" : \"ok\", \"message\" : \"" + data + "\"}");  // log to console
  delay(100);
  data.toCharArray(newMessage, data.length() + 1);                // read new message
  newMessageAvailable = true;
  
  Serial.print("new message: ");
  Serial.println(data);  
}

void handleSettingsUpdate(){
  String json = server.arg("plain");
  const size_t bufferSize = JSON_OBJECT_SIZE(3) + 130;            // 130 XLarge buffer twice needed
  
  DynamicJsonDocument doc(bufferSize);
  DeserializationError error = deserializeJson(doc, json);        // Deserialize the JSON document

  if (error) {                                                    // Test if parsing succeeds.
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  
  const char* oldpassword = doc["oldpassword"];
  const char* newpassword = doc["newpassword"];
  const char* renewpassword = doc["renewpassword"];
   
  if(String(oldpassword) == String(password) && String(newpassword) == String(renewpassword)){
    server.send(200, "text/plain", "password:" + String(password) + " newpassword:" + String(newpassword) + " renewpassword:" + String(renewpassword)); // log OK to console
    delay(100);
    Serial.print("password handle: ");
    Serial.println(json); 
    eepromWriteChar(BUF_SIZE, '\0');              // wall so message doesnt display password at max buffer pos
    eepromWriteChar(PASS_EXIST, P_CHAR);          // user password now exists
    eepromWriteString(PASS_BEGIN, String(newpassword));
    Serial.println("new password saved");
    Serial.println(eepromReadChar(PASS_BEGIN));
    WiFi.softAPdisconnect();
    delay(8000);
    ESP.restart();
    
  }else{
    server.send(200, "text/plain", "error, passwords don't match");  // log error to console
    delay(100);
    Serial.print("password handle error: ");
    Serial.println(json); 
    Serial.println("\nerror, passwords don't match\n");
    delay(1000);
  }
}

void updateDefaultAPPassword(){
  if (eepromReadChar(PASS_EXIST) == P_CHAR){
    delay(200);
    Serial.print("user pwd found: \"");
  }else{
    delay(200);
    Serial.println("\nuser pwd is not found\nrestoring default pwd to ");
    
    eepromWriteChar(BUF_SIZE, '\0');              // wall so message doesnt display password at max buffer pos
    eepromWriteChar(PASS_EXIST, P_CHAR);          // user password now exists
    eepromWriteString(PASS_BEGIN, "password");    // default password is "password"
  }

    String eeString = eepromReadString(PASS_BEGIN, PASS_BSIZE);
    eeString.toCharArray(password, eeString.length() + 1);

    Serial.print(eeString);
    Serial.print("\" from EEPROM.\n\"");
    Serial.print(password);
    Serial.println("\" is used as the WIFI pwd");
    delay(1000);
}

void setup(){
  Serial.begin(115200);
  Serial.println("");
  Serial.println("\n\nScrolling display from your Internet Browser");

  Wire.begin(0, 2);                           // DS3231 RTC I2C - SDA(D3) and SCL(D4)

  Serial.print("\nRTC STARTING >>> ");
  if (! RTC.begin()) {
    Serial.println("RTC NOT FOUND");
    while (1);
  }
  //////////////////////////////////////DateTime mynow = RTC.now();
  Serial.println("RTC STARTED");

  pinMode(LED_BUILTIN, OUTPUT);               // Heartbeat
  digitalWrite(LED_BUILTIN, LOW);

  EEPROM.begin(512);                          // Start ESP8266 EEPROM Emulation

  Serial.println("\n\nEEPROM STARTED");
  
  P.begin(2);
  P.setInvert(false);
  P.setZone(0, 0, MAX_DEVICES-5);
  P.setZone(1, MAX_DEVICES-4, MAX_DEVICES-1);
  //P.displayZoneText(1, szTime, PA_CENTER, SPEED_TIME, PAUSE_TIME, PA_PRINT, PA_NO_EFFECT);
  P.displayZoneText(0, szMesg, PA_CENTER, SPEED_TIME, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
  P.addChar('-', dashF);                      // short dash for date separator
  P.addChar('^', degC);
  P.addChar('|', dotF);
  P.addChar('~', colonF);
  P.setPause(3000);

  curMessage[0] = newMessage[0] = '\0';

  Serial.print("Connecting to ");
  Serial.println(ssid);  

  updateDefaultAPPassword();                  // get Wifi password from EEPROM

  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(ip, ip, subnet);
  WiFi.softAP(ssid, password);

  server.on("/",[](){server.send_P(200,"text/html", indexpage);});
  server.on("/message", HTTP_POST, handleMessageUpdate);

  server.on("/settings",[](){server.send_P(200,"text/html", settingspage);});
  server.on("/settings/send", HTTP_POST, handleSettingsUpdate);

  server.on("/time",[](){server.send_P(200,"text/html", timesetpage);});
  server.on("/time/send", HTTP_POST, handleTimeUpdate);

  server.on("/timepicker",[](){server.send_P(200,"text/html", timepickerpage);});
  server.on("/timepicker/send", HTTP_POST, handleTimeUpdate);

  dnsServer.setTTL(300);
  dnsServer.setErrorReplyCode(DNSReplyCode::ServerFailure);
  dnsServer.start(DNS_PORT, "www.message.com", ip);
  Serial.println("DNS PORT: www.message.com");
  
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  
  server.begin();
  Serial.println("Server started");

  eepromReadString(0,BUF_SIZE).toCharArray(curMessage,BUF_SIZE);  // Read stored msg from EEPROM address 0
  newMessageAvailable = false;
  Serial.print("Message: ");
  Serial.println(curMessage);

  now = RTC.now(); 
  sprintf(szTime, "Time: %02d:%02d", now.hour(), now.minute());
  Serial.println(szTime);

  P.setIntensity(INTENSITY);                  // can set zones seperately
}

void loop(){
  static uint32_t timeLast = 0;               // Heartbeat
  static uint8_t  display = 0;                // current display mode
  static uint8_t t = 0;
  
  if (millis() - timeLast >= 1000){
    digitalWrite(LED_BUILTIN, !digitalRead(LED_BUILTIN));
    timeLast = millis();

    now = RTC.now();                          // Update the global var with current time 
    m = now.minute();  
    h = now.hour();
  }

  dnsServer.processNextRequest();             // dns server
  server.handleClient();                      // WIFI

  if (newMessageAvailable){
    strcpy(curMessage, newMessage);           // Copy new message to display
    eepromWriteString(0, newMessage);         // Write String to EEPROM Address 0
    newMessageAvailable = false;
    Serial.println("new message received, updated EEPROM");
  }

  if (newTimeAvailable){
    int tY, tM, tD, th, tm;
    sscanf(newTime, "%2d.%2d.%4d %2d:%2d", &tD, &tM, &tY, &th, &tm); // format received dd.mm.yyy hh:ss
    RTC.adjust(DateTime(tY, tM, tD, th, tm, 30));                    // rtc.adjust(DateTime(yyyy, m, d, h, m, s));
    newTimeAvailable = false;
    Serial.println(newTime);
    Serial.println("new time received, updated RTC");
  }

  P.displayAnimate();

  if (P.getZoneStatus(0)){   // <<<< UPDATE ZONE 0 (RHS) MESSAGES >>>>
    switch (display){
      case 0: // Time 1/4
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_NO_EFFECT);
        P.setPause(1000);
        display++;
        sprintf(szMesg, "%02d%c%02d", h, '~', m);  // ~| dot and colon
        break;

      case 1: // Time 2/4
        P.setTextEffect(0, PA_PRINT, PA_NO_EFFECT);
        display++;
        sprintf(szMesg, "%02d%c%02d", h, '|', m);  // ~| dot and colon
        break;

      case 2: // Time 3/4
        P.setTextEffect(0, PA_PRINT, PA_NO_EFFECT);
        display++;
        sprintf(szMesg, "%02d%c%02d", h, '~', m);  // ~| dot and colon
        break;

      case 3: // Time 4/4
        P.setTextEffect(0, PA_PRINT, PA_SCROLL_LEFT);
        display++;
        sprintf(szMesg, "%02d%c%02d", h, '|', m);  // ~| dot and colon
        break;
        
      case 4:  // Temp
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        P.setPause(3000);
        display++;
        t = RTC.getTemperature();
        sprintf(szMesg, "%02d%c", t-3, '^');         // ^ degC sign
        break;

      case 5:  // Date
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        P.setPause(3000);
        display++;
        sprintf(szMesg, "%02d%c%02d", now.day(), '-', now.month());
        break;

      case 6:  // Day of week
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        P.setPause(3000);
        display++;
        sprintf(szMesg, "%s", daysOfTheWeek[now.dayOfTheWeek()]);
        break;
       
      default:  // Message
        P.setTextEffect(0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
        P.setPause(0);
        display = 0;
        sprintf(szMesg, "%s", curMessage);  
        break;
    }
    
    P.displayReset(0); 
  }
  
}
