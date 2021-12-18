/*----------------------------------------------------------------------------------------
  Platforms: ESP8266
  Language: C/C++/Arduino
  File: EEPROMHandler.h
  Parent: 2018_Scrolling_Message_v3.ino
  ----------------------------------------------------------------------------------------
  Description:
  ESP8266 Emulates EEPROM
  Simple read and write string to EEPROM
----------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include <EEPROM.h>

void eepromWriteString(char address,String data){
  int _size = data.length();
  int i;
  for(i=0;i<_size;i++){
    EEPROM.write(address+i,data[i]);
  }
  EEPROM.write(address+_size,'\0');           // Add termination null character for String Data
  EEPROM.commit();                            // save to EEPROM flash
  delay(100);
}

String eepromReadString(char address, int16_t buffer_size){
  char data[buffer_size];
  int len=0;
  unsigned char k;
  k=EEPROM.read(address);
  while(k != '\0' && len<buffer_size){         // Read until null character
    k=EEPROM.read(address+len);
    data[len]=k;
    len++;
  }
  data[len]='\0';
  return String(data);
}

void eepromWriteChar(char address,char data){
  EEPROM.write(address,data);
  EEPROM.commit();                            // save to EEPROM flash
  delay(100);
}

char eepromReadChar(char address){
  return EEPROM.read(address);
}
