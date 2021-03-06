// Parent: 2018_Scrolling_Message_v3.ino
#include <pgmspace.h>

const char timepickerpage[] PROGMEM = R"=====(
  
  <!DOCTYPE html>
  <html lang="en">
    <head>
      <meta charset="utf-8">
      <meta http-equiv="X-UA-Compatible" content="IE=edge">
      <meta name="viewport" content="width=device-width, initial-scale=1, user-scalable=no">
  
      <title>Message Board Time</title>
  
        <style>
        #snackbar {
          visibility: hidden;
          min-width: 280px;
          background-color: #333;
          color: #fff;
          text-align: center;
          border-radius: 4px;
          padding-top: 12px;
          padding-bottom: 12px;
          position: fixed;
          z-index: 1;
          bottom: 30px;
          font-size: 17px;
        }
  
        #snackbar.show {
          visibility: visible;
          -webkit-animation: fadein 0.5s, fadeout 0.5s 2.5s;
          animation: fadein 0.5s, fadeout 0.5s 2.5s;
        }
  
        @-webkit-keyframes fadein {
          from {bottom: 0; opacity: 0;} 
          to {bottom: 30px; opacity: 1;}
        }
  
        @keyframes fadein {
          from {bottom: 0; opacity: 0;}
          to {bottom: 30px; opacity: 1;}
        }
  
        @-webkit-keyframes fadeout {
          from {bottom: 30px; opacity: 1;} 
          to {bottom: 0; opacity: 0;}
        }
  
        @keyframes fadeout {
          from {bottom: 30px; opacity: 1;}
          to {bottom: 0; opacity: 0;}
        }
      h3{padding-top: 5px}
      input{width:250px;padding:5px;font-size:1em;}
      body{text-align: center;font-family:verdana;}
      button{border:0;border-radius:0.3rem;
          background-color:#1fa3ec;
          color:#fff;
          line-height:2.4rem;
          font-size:1.2rem;
          width:265px;}
      </style>
  
      <style>
        ul {
          list-style-type: none;
          margin: 0;
          padding: 0;
          overflow: hidden;
          background-color: #333;
        }
  
        li {
          float: left;
        }
  
        li a {
          display: block;
          color: white;
          text-align: center;
          padding: 14px 16px;
          text-decoration: none;
        }
  
        li a:hover:not(.active) {
          background-color: #111;
        }
  
        .active {
          background-color: #1fa3ec;
        }
      </style>
  
      <style>
      .mtr-datepicker 
      .mtr-input-radio,
      .mtr-datepicker 
      .mtr-input-radio label span,
      .mtr-datepicker 
      .mtr-input-slider,
      .mtr-datepicker 
      .mtr-row{position:relative!important;float:left!important}
      .mtr-datepicker *{-webkit-touch-callout:none!important;-webkit-user-select:none!important;-khtml-user-select:none!important;-moz-user-select:none!important;-ms-user-select:none!important;user-select:none!important;box-sizing:border-box}
      .mtr-datepicker 
      .mtr-input-slider{width:50px!important;height:85px!important;overflow:hidden!important;margin:14px 6px!important;text-align:center!important;vertical-align:middle!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-arrow{height:20px!important;line-height:20px!important;cursor:pointer!important;z-index:0!important;position:relative!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-arrow span{display:block!important;margin:0 auto!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content{overflow:hidden!important;height:45px!important;z-index:1!important;position:relative!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-input{width:100%!important;margin:0!important;padding:0!important;border:none!important;height:45px!important;line-height:45px!important;text-align:center!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content input{border:none!important;height:45px!important;font-size:15px!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-values 
      .mtr-default-value,
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-values 
      .mtr-default-value-holder{height:45px!important;line-height:45px!important;font-size:15px!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-values 
      .mtr-default-value-name,
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-values 
      .mtr-default-value.has-name{height:inherit!important;line-height:22.5px!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-values 
      .mtr-default-value.has-name{height:22.5px!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content 
      .mtr-values 
      .mtr-default-value-name{font-size:10px!important}
      .mtr-datepicker 
      .mtr-input-slider 
      .mtr-content::-webkit-scrollbar{display:none!important}
      .mtr-datepicker 
      .mtr-input-radio{margin:20px 10px!important;padding-top:20px!important;font-size:13px!important}
      .mtr-datepicker 
      .mtr-input-radio label{position:relative!important}
      .mtr-datepicker .mtr-clearfix{clear:both!important}
      .mtr-datepicker 
      .mtr-error-message{width:80%!important;position:absolute!important;top:20%;left:10%;text-align:center!important;padding:10px!important;z-index:100000!important}
  
      .mtr-datepicker{font-family:Helvetica;background:#fff}.mtr-datepicker .mtr-arrow span{background:url(data:image/png;base64,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) no-repeat!important;width:13px;height:8px}.mtr-datepicker .mtr-arrow.up{padding-top:6px;margin-bottom:1px}.mtr-datepicker .mtr-arrow.up span{background-position:top center}.mtr-datepicker .mtr-arrow.down{margin-top:1px;padding-top:6px}.mtr-datepicker .mtr-arrow.down span{background:url(data:image/png;base64,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) 0 -8px no-repeat!important}.mtr-datepicker .mtr-arrow:hover{background:#ccd8df}.mtr-datepicker .mtr-arrow:hover.up span{background-position:-13px 0!important}.mtr-datepicker .mtr-arrow:hover.down span{background-position:-13px -8px!important}.mtr-datepicker .mtr-content{background:#bdc3c7;color:#fff}.mtr-datepicker .mtr-content input,.mtr-datepicker .mtr-content input .mtr-values .mtr-default-value,.mtr-datepicker .mtr-content input .mtr-values .mtr-default-value-name,.mtr-datepicker .mtr-content input .mtr-values .mtr-default-value.has-name,.mtr-datepicker .mtr-content.mtr-active,.mtr-datepicker .mtr-content.mtr-active .mtr-values .mtr-default-value,.mtr-datepicker .mtr-content.mtr-active .mtr-values .mtr-default-value-name,.mtr-datepicker .mtr-content.mtr-active .mtr-values .mtr-default-value.has-name,.mtr-datepicker .mtr-content:hover,.mtr-datepicker .mtr-content:hover .mtr-values .mtr-default-value,.mtr-datepicker .mtr-content:hover .mtr-values .mtr-default-value-name,.mtr-datepicker .mtr-content:hover .mtr-values .mtr-default-value.has-name{background:#1fa3ec}.mtr-datepicker .mtr-content.mtr-error,.mtr-datepicker .mtr-content.mtr-error .mtr-values .mtr-default-value,.mtr-datepicker .mtr-content.mtr-error .mtr-values .mtr-default-value-name,.mtr-datepicker .mtr-content.mtr-error .mtr-values .mtr-default-value.has-name{background:#2c3e50}.mtr-datepicker .mtr-content .mtr-input,.mtr-datepicker .mtr-content input{background:#1fa3ec}.mtr-datepicker .mtr-content .mtr-values .mtr-default-value,.mtr-datepicker .mtr-content .mtr-values .mtr-default-value-name,.mtr-datepicker .mtr-content .mtr-values .mtr-default-value.has-name{background:#333333}.mtr-datepicker .mtr-content .mtr-values .mtr-default-value.has-name{padding-top:10px}.mtr-datepicker .mtr-content .mtr-values .mtr-default-value-name{padding-top:2px}.mtr-datepicker .mtr-input-radio label{color:#1fa3ec}.mtr-datepicker .mtr-input-radio label span.value{width:20px}.mtr-datepicker .mtr-input-radio input[type=radio]{display:none}.mtr-datepicker .mtr-input-radio input[type=radio]+label span.radio{width:26px;height:18px;display:inline-block;background:url(data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAE4AAAASCAYAAAD15uiRAAAACXBIWXMAAAsTAAALEwEAmpwYAAAKT2lDQ1BQaG90b3Nob3AgSUNDIHByb2ZpbGUAAHjanVNnVFPpFj333vRCS4iAlEtvUhUIIFJCi4AUkSYqIQkQSoghodkVUcERRUUEG8igiAOOjoCMFVEsDIoK2AfkIaKOg6OIisr74Xuja9a89+bN/rXXPues852zzwfACAyWSDNRNYAMqUIeEeCDx8TG4eQuQIEKJHAAEAizZCFz/SMBAPh+PDwrIsAHvgABeNMLCADATZvAMByH/w/qQplcAYCEAcB0kThLCIAUAEB6jkKmAEBGAYCdmCZTAKAEAGDLY2LjAFAtAGAnf+bTAICd+Jl7AQBblCEVAaCRACATZYhEAGg7AKzPVopFAFgwABRmS8Q5ANgtADBJV2ZIALC3AMDOEAuyAAgMADBRiIUpAAR7AGDIIyN4AISZABRG8lc88SuuEOcqAAB4mbI8uSQ5RYFbCC1xB1dXLh4ozkkXKxQ2YQJhmkAuwnmZGTKBNA/g88wAAKCRFRHgg/P9eM4Ors7ONo62Dl8t6r8G/yJiYuP+5c+rcEAAAOF0ftH+LC+zGoA7BoBt/qIl7gRoXgugdfeLZrIPQLUAoOnaV/Nw+H48PEWhkLnZ2eXk5NhKxEJbYcpXff5nwl/AV/1s+X48/Pf14L7iJIEyXYFHBPjgwsz0TKUcz5IJhGLc5o9H/LcL//wd0yLESWK5WCoU41EScY5EmozzMqUiiUKSKcUl0v9k4t8s+wM+3zUAsGo+AXuRLahdYwP2SycQWHTA4vcAAPK7b8HUKAgDgGiD4c93/+8//UegJQCAZkmScQAAXkQkLlTKsz/HCAAARKCBKrBBG/TBGCzABhzBBdzBC/xgNoRCJMTCQhBCCmSAHHJgKayCQiiGzbAdKmAv1EAdNMBRaIaTcA4uwlW4Dj1wD/phCJ7BKLyBCQRByAgTYSHaiAFiilgjjggXmYX4IcFIBBKLJCDJiBRRIkuRNUgxUopUIFVIHfI9cgI5h1xGupE7yAAygvyGvEcxlIGyUT3UDLVDuag3GoRGogvQZHQxmo8WoJvQcrQaPYw2oefQq2gP2o8+Q8cwwOgYBzPEbDAuxsNCsTgsCZNjy7EirAyrxhqwVqwDu4n1Y8+xdwQSgUXACTYEd0IgYR5BSFhMWE7YSKggHCQ0EdoJNwkDhFHCJyKTqEu0JroR+cQYYjIxh1hILCPWEo8TLxB7iEPENyQSiUMyJ7mQAkmxpFTSEtJG0m5SI+ksqZs0SBojk8naZGuyBzmULCAryIXkneTD5DPkG+Qh8lsKnWJAcaT4U+IoUspqShnlEOU05QZlmDJBVaOaUt2ooVQRNY9aQq2htlKvUYeoEzR1mjnNgxZJS6WtopXTGmgXaPdpr+h0uhHdlR5Ol9BX0svpR+iX6AP0dwwNhhWDx4hnKBmbGAcYZxl3GK+YTKYZ04sZx1QwNzHrmOeZD5lvVVgqtip8FZHKCpVKlSaVGyovVKmqpqreqgtV81XLVI+pXlN9rkZVM1PjqQnUlqtVqp1Q61MbU2epO6iHqmeob1Q/pH5Z/YkGWcNMw09DpFGgsV/jvMYgC2MZs3gsIWsNq4Z1gTXEJrHN2Xx2KruY/R27iz2qqaE5QzNKM1ezUvOUZj8H45hx+Jx0TgnnKKeX836K3hTvKeIpG6Y0TLkxZVxrqpaXllirSKtRq0frvTau7aedpr1Fu1n7gQ5Bx0onXCdHZ4/OBZ3nU9lT3acKpxZNPTr1ri6qa6UbobtEd79up+6Ynr5egJ5Mb6feeb3n+hx9L/1U/W36p/VHDFgGswwkBtsMzhg8xTVxbzwdL8fb8VFDXcNAQ6VhlWGX4YSRudE8o9VGjUYPjGnGXOMk423GbcajJgYmISZLTepN7ppSTbmmKaY7TDtMx83MzaLN1pk1mz0x1zLnm+eb15vft2BaeFostqi2uGVJsuRaplnutrxuhVo5WaVYVVpds0atna0l1rutu6cRp7lOk06rntZnw7Dxtsm2qbcZsOXYBtuutm22fWFnYhdnt8Wuw+6TvZN9un2N/T0HDYfZDqsdWh1+c7RyFDpWOt6azpzuP33F9JbpL2dYzxDP2DPjthPLKcRpnVOb00dnF2e5c4PziIuJS4LLLpc+Lpsbxt3IveRKdPVxXeF60vWdm7Obwu2o26/uNu5p7ofcn8w0nymeWTNz0MPIQ+BR5dE/C5+VMGvfrH5PQ0+BZ7XnIy9jL5FXrdewt6V3qvdh7xc+9j5yn+M+4zw33jLeWV/MN8C3yLfLT8Nvnl+F30N/I/9k/3r/0QCngCUBZwOJgUGBWwL7+Hp8Ib+OPzrbZfay2e1BjKC5QRVBj4KtguXBrSFoyOyQrSH355jOkc5pDoVQfujW0Adh5mGLw34MJ4WHhVeGP45wiFga0TGXNXfR3ENz30T6RJZE3ptnMU85ry1KNSo+qi5qPNo3ujS6P8YuZlnM1VidWElsSxw5LiquNm5svt/87fOH4p3iC+N7F5gvyF1weaHOwvSFpxapLhIsOpZATIhOOJTwQRAqqBaMJfITdyWOCnnCHcJnIi/RNtGI2ENcKh5O8kgqTXqS7JG8NXkkxTOlLOW5hCepkLxMDUzdmzqeFpp2IG0yPTq9MYOSkZBxQqohTZO2Z+pn5mZ2y6xlhbL+xW6Lty8elQfJa7OQrAVZLQq2QqboVFoo1yoHsmdlV2a/zYnKOZarnivN7cyzytuQN5zvn//tEsIS4ZK2pYZLVy0dWOa9rGo5sjxxedsK4xUFK4ZWBqw8uIq2Km3VT6vtV5eufr0mek1rgV7ByoLBtQFr6wtVCuWFfevc1+1dT1gvWd+1YfqGnRs+FYmKrhTbF5cVf9go3HjlG4dvyr+Z3JS0qavEuWTPZtJm6ebeLZ5bDpaql+aXDm4N2dq0Dd9WtO319kXbL5fNKNu7g7ZDuaO/PLi8ZafJzs07P1SkVPRU+lQ27tLdtWHX+G7R7ht7vPY07NXbW7z3/T7JvttVAVVN1WbVZftJ+7P3P66Jqun4lvttXa1ObXHtxwPSA/0HIw6217nU1R3SPVRSj9Yr60cOxx++/p3vdy0NNg1VjZzG4iNwRHnk6fcJ3/ceDTradox7rOEH0x92HWcdL2pCmvKaRptTmvtbYlu6T8w+0dbq3nr8R9sfD5w0PFl5SvNUyWna6YLTk2fyz4ydlZ19fi753GDborZ752PO32oPb++6EHTh0kX/i+c7vDvOXPK4dPKy2+UTV7hXmq86X23qdOo8/pPTT8e7nLuarrlca7nuer21e2b36RueN87d9L158Rb/1tWeOT3dvfN6b/fF9/XfFt1+cif9zsu72Xcn7q28T7xf9EDtQdlD3YfVP1v+3Njv3H9qwHeg89HcR/cGhYPP/pH1jw9DBY+Zj8uGDYbrnjg+OTniP3L96fynQ89kzyaeF/6i/suuFxYvfvjV69fO0ZjRoZfyl5O/bXyl/erA6xmv28bCxh6+yXgzMV70VvvtwXfcdx3vo98PT+R8IH8o/2j5sfVT0Kf7kxmTk/8EA5jz/GMzLdsAAAAgY0hSTQAAeiUAAICDAAD5/wAAgOkAAHUwAADqYAAAOpgAABdvkl/FRgAAA9RJREFUeNrsmG9IU2scx7/zxsr+revcWi7NtGWah9wduAzr9HcQBbGS231xR7VFUbA3vbggF9otuHAJFtGC/m5CglBRC7N/ZnUPhYu6IddjR9ZcTqe2TbNkVuS11osm6O6OO39Gr/zBXjwPv98+v3327Ox5HkksFsNU8I+MKQXCYhqXJIfLWQXAAmATgB/i0x4AtVaz5XQ6Gyo50sjKYmyGtLEI0sjKoSl3So5ksp+qw+VUADirUihKl2k0L5YvLerKyMiIAYCv89WCdp+vuKun5z2APVazxStSmALAWQDGSdI8APYwNoNXhDDOHJpye3mLi0trKSos7DGQaz1sb0A98WhbGaYcgN5qttAipLUAUHNI/whAz9gMtEBpvDg05ab5PuNqUkkDAHJlRUvZ8lIPgGsOl1MqcCHUcPwwAJAJ4FrJkUbp9+AQpFHKWZzD5SR/lMlWpJI2Fqv1+tbcnJxPAEwCVhsJYMuElaGWdZz6payOsRlOXN1f4awokLcllC3hyyJI4/85xZqOk39W19GU+8TlC3bnSt0Kzhy2Fbdz0cLcl3waK8zP9wGoErAKdiZKu7RX37C+SBkBgGLVnKjTpGuqXJL9b0JdlShOsaaj7syxhnWV5d84moLo+eN/NFWWazlx2MQRyuzsAT5d5anVYQA6Ic/r8QNjWU5bsqQDawpaEqZ0YjjbNq9Pytm/62dOHDZxs6dLpf/x6WpW5swRADIB4maPH6jmzviQLKlo/pxowpRMFEeRnZSztDCfE4dNXP/wh/eZfLp6OzQ0E0BIgLj+8YN/ut7OT5ZU39qXmzAVEsN53voiKedG49+cOGziHveFQmo+XQWC3WoAjwWIm1BzlwkTdO/Q3PFzo19ikotPusonq+PNedhM0O2+iZzRz5LaKzc4cdhODrVev/8wWbHq2XSpdJRLV16/vxTArwLE1QI4PLZ77333UWmqeWba8ZO6WZs7L9z+Oiq/2fZaG4l+ykqoOyeG0xeKKHdbfzdt37Kxuax0Wbjd90p++/4jbWRgkBNnsg2wfXFe3rqtGzdRqTq69eD+an8g8NRqthwUuAG2AzjEo+Q0YzPwZhGkkTeHptwH+W6Aqzu7u4PX797ZEAgGFckSosPDMxqa7pH+QAAAfhNx4qoGUM8x97kIVto4klTXSg6Xcx8Au1qlCsqzsiIqhTI8MPhG3j84qAz29pYA+AvAUavZMpKGA/4+APbEf8B4fB5jMTaDKBZBGjlxaMo9IlhcXJ4qfougi7+Y+Ddyz2q2dKb5doSVxdgMaWMRpJGVQ1PulBzJ1EWmsPg6AIb4dZbpnSLvAAAAAElFTkSuQmCC) no-repeat!important;line-height:18px;margin:0;margin-left:5px}.mtr-datepicker .mtr-input-radio input[type=radio]:checked+label span.radio{background:url(data:image/png;base64,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) -27px 0 no-repeat!important;background-position:-27px 0}.mtr-datepicker .mtr-input-radio input[type=radio].mtr-error+label span.radio{background:url(data:image/png;base64,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) -53px 0 no-repeat!important;background-position:-53px 0}.mtr-datepicker .mtr-error-message{background:#bdc3c7!important;color:#2c3e50!important;border:2px solid #1fa3ec!important}
      </style>
    </head>
  
    <body>
  
      <div style='display:inline-block;min-width:280px;'>
        <ul>
          <li><a href="/">Message</a></li>
          <li><a class="active" href="/time">Time</a></li>
          <li><a href="/settings">Settings</a></li>
        </ul>
    </div>
      <div>
        <h3>Set Current Time and Date:</h3>
            <form id="data_form" name="frmText">
              <div>
                <div style="display:inline-block;border-width: 2px;border-color: #333333;padding-left:35px;padding-right:35px;padding-bottom:5px;border-style: solid;border-radius:0.5rem;" id="scriptDatepicker"></div>  
              </div>
          </form>
        <br/>
        <button onclick="SendTime()">update time</button>
      </div>
      <div style='display:inline-block;min-width:280px;'>
        <div id="snackbar">Display by. R Wilson</div>
      </div>
  
      <script ype="text/javascript">
        function MtrDatepicker(a) {
        function b(a) {
            return document.getElementById(a);
        }
        function c(a, b) {
            return a ? a.querySelector(b) : null;
        }
        function d(a, b) {
            return a && b ? b.offsetTop - a.offsetTop : 0;
        }
        function e(a) {
            var b;
            if (null == a || "object" != typeof a) return a;
            if (a instanceof Array) {
                b = [];
                for (var c = 0, d = a.length; c < d; c++) b[c] = e(a[c]);
                return b;
            }
            if (a instanceof Object) {
                b = {};
                for (var f in a) a.hasOwnProperty(f) && (b[f] = e(a[f]));
                return b;
            }
            throw new Error("Unable to copy obj! Its type isn't supported.");
        }
        function f(a, b) {
            a && (a.className.indexOf(b) > -1 || (a.className += " " + b));
        }
        function g(a, b) {
            a && a.className.indexOf(b) !== -1 && (a.className = a.className.replace(new RegExp(b, "g"), ""));
        }
        function h(a) {
            return Number(a) === a && a % 1 == 0;
        }
        function i(a) {
            for (var b = a.min, c = a.max, d = a.step, e = [], f = b; f <= c; f += d) e.push(f);
            return e;
        }
        function j(a, b) {
            for (var c, d = new Date(b, a, 1), e = new Date(b, a + 1, 0), f = {
                values: [],
                names: [],
                min: d.getDate(),
                max: e.getDate(),
                step: 1
            }, g = d.getDate(); g <= e.getDate(); g++) c = new Date(b, a, g), f.values.push(g), 
            f.names[g] = o.daysNames[c.getDay()];
            return f;
        }
        function k(a) {
            fa = a.touches[0].clientX, ga = a.touches[0].clientY;
        }
        function l(a, b) {
            if (fa && ga) {
                var c = a.touches[0].clientX, d = a.touches[0].clientY, e = fa - c, f = ga - d;
                Math.abs(e) > Math.abs(f) || b(f > 0 ? 1 : -1), fa = null, ga = null;
            }
        }
        function m() {
            var a = {
                isChrome: !1,
                isSafari: !1,
                isFirefox: !1
            };
            return navigator.userAgent.search("Safari") >= 0 && navigator.userAgent.search("Chrome") < 0 && (a.isSafari = !0), 
            a;
        }
        var n, o = {
            targetElement: null,
            defaultValues: {
                hours: [],
                minutes: [],
                dates: [],
                datesNames: [],
                months: [],
                years: []
            },
            hours: {
                min: 1,
                max: 12,
                step: 1,
                maxlength: 2
            },
            minutes: {
                min: 0,
                max: 50,
                step: 10,
                maxlength: 2
            },
            months: {
                min: 0,
                max: 11,
                step: 1,
                maxlength: 2
            },
            years: {
                min: 2e3,
                max: 2030,
                step: 1,
                maxlength: 4
            },
            animations: !0,
            smartHours: !1,
            future: !1,
            disableAmPm: !1,
            validateAfter: !0,
            utcTimezone: 0,
            transitionDelay: 100,
            transitionValidationDelay: 500,
            references: {
                hours: null
            },
            monthsNames: {
                0: "Jan",
                1: "Feb",
                2: "Mar",
                3: "Apr",
                4: "May",
                5: "Jun",
                6: "Jul",
                7: "Aug",
                8: "Sep",
                9: "Oct",
                10: "Nov",
                11: "Dec"
            },
            daysNames: {
                0: "Sun",
                1: "Mon",
                2: "Tue",
                3: "Wed",
                4: "Thu",
                5: "Fri",
                6: "Sat"
            },
            timezones: null
        }, p = {
            date: null,
            timestamp: null,
            ampm: !0
        }, q = null, r = {
            all: [],
            time: [],
            date: [],
            hour: [],
            minute: [],
            ampm: [],
            day: [],
            month: [],
            year: []
        }, s = {
            onChange: e(r),
            beforeChange: e(r),
            afterChange: e(r)
        }, t = {}, u = null, v = {}, w = function(a) {
            if (q = m(), !y(a)) return void console.error("Initialization of the datepicker is blocked because of erros in the config.");
            x(a), n = b(o.targetElement), A(), B(), z();
        }, x = function(a) {
            o.targetElement = a.target, o.animations = void 0 !== a.animations ? a.animations : o.animations, 
            o.future = void 0 !== a.future ? a.future : o.future, o.validateAfter = void 0 !== a.validateAfter ? a.validateAfter : o.validateAfter, 
            o.smartHours = void 0 !== a.smartHours ? a.smartHours : o.smartHours, o.disableAmPm = void 0 !== a.disableAmPm ? a.disableAmPm : o.disableAmPm, 
            o.disableAmPm && (o.hours.min = 0, o.hours.max = 23), p.date = a.timestamp ? new Date(a.timestamp) : new Date(), 
            p.date.setSeconds(0), void 0 !== a.utcTimezone ? (t.timezones = new MtrDatepickerTimezones(), 
            o.utcTimezone = t.timezones.getTimezone(a.utcTimezone)) : o.utcTimezone = {
                offset: void 0 !== a.utcTimezone ? a.utcTimezone : p.date.getTimezoneOffset() / 60 * -1
            };
            var b = p.date.getTime() + 60 * p.date.getTimezoneOffset() * 1e3, c = b + 60 * o.utcTimezone.offset * 60 * 1e3;
            p.date = new Date(c), p.timestamp = p.date.getTime(), o.minutes.min = void 0 !== a.minutes && void 0 !== a.minutes.min ? parseInt(a.minutes.min) : o.minutes.min, 
            o.minutes.max = void 0 !== a.minutes && void 0 !== a.minutes.max ? parseInt(a.minutes.max) : o.minutes.max, 
            o.minutes.step = void 0 !== a.minutes && void 0 !== a.minutes.step ? parseInt(a.minutes.step) : o.minutes.step, 
            o.months.min = void 0 !== a.months && void 0 !== a.months.min ? parseInt(a.months.min) : o.months.min, 
            o.months.max = void 0 !== a.months && void 0 !== a.months.max ? parseInt(a.months.max) : o.months.max, 
            o.months.step = void 0 !== a.months && void 0 !== a.months.step ? parseInt(a.months.step) : o.months.step, 
            o.years.min = void 0 !== a.years && void 0 !== a.years.min ? parseInt(a.years.min) : o.years.min, 
            o.years.max = void 0 !== a.years && void 0 !== a.years.max ? parseInt(a.years.max) : o.years.max, 
            o.years.step = void 0 !== a.years && void 0 !== a.years.step ? parseInt(a.years.step) : o.years.step, 
            o.defaultValues.hours = i(o.hours), o.defaultValues.minutes = i(o.minutes), o.defaultValues.months = i(o.months), 
            o.defaultValues.years = i(o.years);
        }, y = function(a) {
            var c = !0;
            if (a.minutes && (void 0 === a.minutes.min || h(a.minutes.min) || (console.error("Invalid argument: minutes.min should be a number."), 
            c = !1), void 0 === a.minutes.max || h(a.minutes.max) || (console.error("Invalid argument: minutes.max should be a number."), 
            c = !1), void 0 === a.minutes.step || h(a.minutes.step) || (console.error("Invalid argument: minutes.step should be a number."), 
            c = !1), void 0 !== a.minutes.min && void 0 !== a.minutes.max && a.minutes.max < a.minutes.min && (console.error("Invalid argument: minutes.max should be larger than minutes.min."), 
            c = !1), void 0 !== a.minutes.min && void 0 !== a.minutes.max && void 0 !== a.minutes.step && a.minutes.step > a.minutes.max - a.minutes.min && (console.error("Invalid argument: minutes.step should be less than minutes.max-minutes.min."), 
            c = !1)), a.hours && (void 0 === a.hours.min || h(a.hours.min) || (console.error("Invalid argument: hours.min should be a number."), 
            c = !1), void 0 === a.hours.max || h(a.hours.max) || (console.error("Invalid argument: hours.max should be a number."), 
            c = !1), void 0 === a.hours.step || h(a.hours.step) || (console.error("Invalid argument: hours.step should be a number."), 
            c = !1), void 0 !== a.hours.min && void 0 !== a.hours.max && a.hours.max < a.hours.min && (console.error("Invalid argument: hours.max should be larger than hours.min."), 
            c = !1), void 0 !== a.hours.min && void 0 !== a.hours.max && void 0 !== a.hours.step && a.hours.step > a.hours.max - a.hours.min && (console.error("Invalid argument: hours.step should be less than hours.max-hours.min."), 
            c = !1)), a.dates && (void 0 === a.dates.min || h(a.dates.min) || (console.error("Invalid argument: dates.min should be a number."), 
            c = !1), void 0 === a.dates.max || h(a.dates.max) || (console.error("Invalid argument: dates.max should be a number."), 
            c = !1), void 0 === a.dates.step || h(a.dates.step) || (console.error("Invalid argument: dates.step should be a number."), 
            c = !1), void 0 !== a.dates.min && void 0 !== a.dates.max && a.dates.max < a.dates.min && (console.error("Invalid argument: dates.max should be larger than dates.min."), 
            c = !1), void 0 !== a.dates.min && void 0 !== a.dates.max && void 0 !== a.dates.step && a.dates.step > a.dates.max - a.dates.min && (console.error("Invalid argument: dates.step should be less than dates.max-dates.min."), 
            c = !1)), a.months && (void 0 === a.months.min || h(a.months.min) || (console.error("Invalid argument: months.min should be a number."), 
            c = !1), void 0 === a.months.max || h(a.months.max) || (console.error("Invalid argument: months.max should be a number."), 
            c = !1), void 0 === a.months.step || h(a.months.step) || (console.error("Invalid argument: months.step should be a number."), 
            c = !1), void 0 !== a.months.min && void 0 !== a.months.max && a.months.max < a.months.min && (console.error("Invalid argument: months.max should be larger than months.min."), 
            c = !1), void 0 !== a.months.min && void 0 !== a.months.max && void 0 !== a.months.step && a.months.step > a.months.max - a.months.min && (console.error("Invalid argument: months.step should be less than months.max-months.min."), 
            c = !1)), a.years && (void 0 === a.years.min || h(a.years.min) || (console.error("Invalid argument: years.min should be a number."), 
            c = !1), void 0 === a.years.max || h(a.years.max) || (console.error("Invalid argument: years.max should be a number."), 
            c = !1), void 0 === a.years.step || h(a.years.step) || (console.error("Invalid argument: years.step should be a number."), 
            c = !1), void 0 !== a.years.min && void 0 !== a.years.max && a.years.max < a.years.min && (console.error("Invalid argument: years.max should be larger than years.min."), 
            c = !1), void 0 !== a.years.min && void 0 !== a.years.max && void 0 !== a.years.step && a.years.step > a.years.max - a.years.min && (console.error("Invalid argument: years.step should be less than years.max-years.min."), 
            c = !1)), a.timestamp && a.future) {
                var d = new Date(a.timestamp), e = new Date();
                d.getTime() < e.getTime() && (console.error("Invalid argument: timestamp should be in the future if the future check is enabled."), 
                c = !1);
            }
            if (void 0 !== a.utcTimezone && "function" != typeof MtrDatepickerTimezones && (console.error("In order to use the timezones feature you should load the mtr-datepicker-timezones.min.js first."), 
            c = !1), !c) {
                for (n = b(a.target); n.firstChild; ) n.removeChild(n.firstChild);
                var g = document.createElement("div");
                f(g, "mtr-error-message"), g.appendChild(document.createTextNode("An error has occured during the initialization of the datepicker.")), 
                n.appendChild(g);
            }
            return c;
        }, z = function() {}, A = function(a, b) {
            a = void 0 !== a ? a : V(), b = void 0 !== b ? b : X();
            var c = j(a, b);
            o.dates = {
                min: c.min,
                max: c.max,
                step: c.step,
                maxlength: 2
            }, o.defaultValues.dates = c.values, o.defaultValues.datesNames = c.names;
        }, B = function() {
            for (g(n, "mtr-datepicker"), f(n, "mtr-datepicker"); n.firstChild; ) n.removeChild(n.firstChild);
            var a, b = C({
                name: "hours",
                values: o.defaultValues.hours,
                value: L()
            }), c = C({
                name: "minutes",
                values: o.defaultValues.minutes,
                value: N()
            });
            o.disableAmPm || (a = D({
                name: "ampm"
            }));
            var d = document.createElement("div");
            d.className = "mtr-row";
            var e = document.createElement("div");
            e.className = "mtr-clearfix", d.appendChild(b), d.appendChild(c), o.disableAmPm || d.appendChild(a), 
            n.appendChild(d), n.appendChild(e);
            var h = C({
                name: "months",
                values: o.defaultValues.months,
                valuesNames: o.monthsNames,
                value: V()
            }), i = C({
                name: "dates",
                values: o.defaultValues.dates,
                valuesNames: o.defaultValues.datesNames,
                value: T()
            }), j = C({
                name: "years",
                values: o.defaultValues.years,
                value: X()
            }), k = document.createElement("div");
            k.className = "mtr-row";
            var l = document.createElement("div");
            l.className = "mtr-clearfix", k.appendChild(h), k.appendChild(i), k.appendChild(j), 
            n.appendChild(k), n.appendChild(l), Z(p.timestamp);
        }, C = function(a) {
            function b() {
                var b = document.createElement("div");
                return b.className = "mtr-arrow up", b.appendChild(document.createElement("span")), 
                b.addEventListener("click", function() {
                    c(q, ".mtr-input");
                    f(q, "arrow-click"), f(p, "mtr-active"), v[a.name] && window.clearTimeout(v[a.name]), 
                    v[a.name] = setTimeout(function() {
                        g(q, "arrow-click"), g(p, "mtr-active");
                    }, 1e3);
                    var b, d = a.name;
                    switch (d) {
                      case "hours":
                        b = L();
                        break;
  
                      case "minutes":
                        b = N();
                        break;
  
                      case "dates":
                        b = T();
                        break;
  
                      case "months":
                        b = V();
                        break;
  
                      case "years":
                        b = X();
                    }
                    var e = o.defaultValues[d].indexOf(b);
                    switch (e++, e >= o.defaultValues[d].length && (e = 0), d) {
                      case "hours":
                        var h = o.defaultValues[d][e];
                        !o.disableAmPm && R() && 12 !== h && (h += 12), K(h);
                        break;
  
                      case "minutes":
                        M(o.defaultValues[d][e]);
                        break;
  
                      case "dates":
                        S(o.defaultValues[d][e]);
                        break;
  
                      case "months":
                        U(o.defaultValues[d][e]);
                        break;
  
                      case "years":
                        W(o.defaultValues[d][e]);
                    }
                }, !1), b;
            }
            function d() {
                var b = document.createElement("div");
                return b.className = "mtr-arrow down", b.appendChild(document.createElement("span")), 
                b.addEventListener("click", function(b) {
                    c(q, ".mtr-input");
                    f(q, "arrow-click"), f(p, "mtr-active"), v[a.name] && window.clearTimeout(v[a.name]), 
                    v[a.name] = setTimeout(function() {
                        g(q, "arrow-click"), g(p, "mtr-active");
                    }, 1e3);
                    var d, e = a.name;
                    switch (e) {
                      case "hours":
                        d = L();
                        break;
  
                      case "minutes":
                        d = N();
                        break;
  
                      case "dates":
                        d = T();
                        break;
  
                      case "months":
                        d = V();
                        break;
  
                      case "years":
                        d = X();
                    }
                    var h = o.defaultValues[e].indexOf(d);
                    switch (h--, h < 0 && (h = o.defaultValues[e].length - 1), e) {
                      case "hours":
                        var i = o.defaultValues[e][h];
                        !o.disableAmPm && R() && 12 !== i && (i += 12), K(i);
                        break;
  
                      case "minutes":
                        M(o.defaultValues[e][h]);
                        break;
  
                      case "dates":
                        S(o.defaultValues[e][h]);
                        break;
  
                      case "months":
                        U(o.defaultValues[e][h]);
                        break;
  
                      case "years":
                        W(o.defaultValues[e][h]);
                    }
                }, !1), b;
            }
            function e() {
                var b = document.createElement("input");
                return b.value = a.value, b.type = "text", b.className = "mtr-input " + a.name, 
                b.style.display = "none", b.addEventListener("blur", function(c) {
                    function d() {
                        if (n) {
                            var d = b.value, e = b.getAttribute("data-old-value");
                            if (c.target.className.indexOf("arrow-click") > -1) return void g(c.target, "arrow-click");
                            if (b.className.indexOf("months") > -1 && d--, H(a.name, d) === !1) return b.value = e, 
                            void b.focus();
                            var f = a.name.substring(0, a.name.length - 1);
                            if ("dates" === a.name && (f = "day"), o.future && !I(f, d, e)) return "months" === a.name && e++, 
                            b.value = e, void b.focus();
                            switch (b.style.display = "none", a.name) {
                              case "hours":
                                K(d);
                                break;
  
                              case "minutes":
                                M(d);
                                break;
  
                              case "dates":
                                S(d);
                                break;
  
                              case "months":
                                U(d);
                                break;
  
                              case "years":
                                W(d);
                            }
                        }
                    }
                    setTimeout(function() {
                        d();
                    }, 500);
                }, !1), b.addEventListener("wheel ", function(c) {
                    c.preventDefault(), c.stopPropagation();
                    var d, e = (c.target, c.wheelDeltaY ? c.wheelDeltaY : c.deltaY, parseInt(b.value)), f = o[a.name].min, g = o[a.name].max, h = o[a.name].step;
                    return "months" === a.name && (f++, g++), d = direction > 0 ? e < g ? e + h : f : e > f ? e - h : g, 
                    b.value = d, !1;
                }, !1), b;
            }
            function h(b) {
                var d = E(a);
                return d.addEventListener("touchstart", function(a) {
                    k(a);
                }, !1), d.addEventListener("touchmove", function(a) {
                    l(a, function(a) {
                        var b, e = d.parentElement.parentElement;
                        b = a > 0 ? c(e, ".mtr-arrow.up") : c(e, ".mtr-arrow.down"), b.click();
                    });
                }, !1), d;
            }
            var i = document.createElement("div");
            i.className = "mtr-input-slider", o.references[a.name] = o.targetElement + "-input-" + a.name, 
            i.id = o.references[a.name];
            var j = b(), m = d(), p = document.createElement("div");
            p.className = "mtr-content";
            var q = e(), r = h(q);
            return i.appendChild(j), p.appendChild(q), p.appendChild(r), i.appendChild(p), i.appendChild(m), 
            i;
        }, D = function(a) {
            function b(a, b, c) {
                var d = document.createElement("div"), e = document.createElement("label"), f = document.createElement("input"), g = o.targetElement + "-radio-" + a + "-" + c, h = document.createElement("span");
                h.className = "value", h.appendChild(document.createTextNode(c));
                var i = document.createElement("span");
                return i.className = "radio", e.setAttribute("for", g), e.appendChild(h), e.appendChild(i), 
                f.className = "mtr-input ", f.type = "radio", f.name = a, f.id = g, f.value = b, 
                d.appendChild(f), d.appendChild(e), f.addEventListener("change", function(a) {
                    if (!O(b) && o.future) return O(!b), a.preventDefault(), a.stopPropagation(), !1;
                }, !1), d;
            }
            var c = document.createElement("div");
            c.className = "mtr-input-radio", o.references[a.name] = o.targetElement + "-input-" + a.name, 
            c.id = o.references[a.name];
            var d = document.createElement("form");
            d.name = o.references[a.name];
            var e = b("ampm", 1, "AM"), f = b("ampm", 0, "PM");
            return d.appendChild(e), d.appendChild(f), d.ampm.value = Q() ? "1" : "0", c.appendChild(d), 
            c;
        }, E = function(a) {
            var b = document.createElement("div");
            b.className = "mtr-values", a.values.forEach(function(c) {
                var d = "months" === a.name ? c + 1 : c, e = document.createElement("div");
                e.className = "mtr-default-value-holder", e.setAttribute("data-value", c);
                var f = document.createElement("div");
                if (f.className = "mtr-default-value", f.setAttribute("data-value", c), "minutes" === a.name && 0 === c ? f.appendChild(document.createTextNode("00")) : f.appendChild(document.createTextNode(d)), 
                e.appendChild(f), a.valuesNames) {
                    var g = document.createElement("div");
                    g.className = "mtr-default-value-name", g.appendChild(document.createTextNode(a.valuesNames[c])), 
                    f.className += " has-name", e.appendChild(g);
                }
                b.appendChild(e);
            });
            var d = function() {
                var a = b.parentElement, d = c(a, ".mtr-input");
                d.className.indexOf("months") > -1 && (d.value = parseInt(d.value) + 1), d.style.display = "block", 
                d.focus();
            };
            return b.addEventListener("click", d, !1), b.addEventListener("touchstart", d, !1), 
            b.addEventListener("touchend", d, !1), b.addEventListener("wheel", function(a) {
                if (a.preventDefault(), a.stopPropagation(), u) return !1;
                var b, d = a.target, e = d.parentElement.parentElement.parentElement.parentElement, f = (c(e, ".mtr-values"), 
                c(e, ".mtr-input"), a.wheelDeltaY ? a.wheelDeltaY : a.deltaY * -1);
                return b = f > 0 ? c(e, ".mtr-arrow.up") : c(e, ".mtr-arrow.down"), u = setTimeout(function() {
                    J();
                }, 100), b.click(), !1;
            }, !1), b.addEventListener("touchstart", function(a) {
                return a.preventDefault(), a.stopPropagation(), !1;
            }, !1), b.addEventListener("touchmove", function(a) {
                return a.preventDefault(), a.stopPropagation(), !1;
            }, !1), b;
        }, F = function(a, d) {
            var e = b(a), f = c(e, ".mtr-content"), g = c(f, ".mtr-values");
            g.parentNode.removeChild(g);
            var h = E({
                name: d.name,
                values: d.values,
                valuesNames: d.valuesNames
            });
            f.appendChild(h);
        }, G = function(a, b) {
            a = void 0 !== a ? a : V(), b = void 0 !== b ? b : X(), A(a, b), F(o.references.dates, {
                name: "dates",
                values: o.defaultValues.dates,
                valuesNames: o.defaultValues.datesNames
            });
            var c = o.defaultValues.dates[o.defaultValues.dates.length - 1];
            T() > c && S(c);
        }, H = function(a, b) {
            return b = parseInt(b), o.defaultValues[a].indexOf(b) > -1;
        }, I = function(a, b, c) {
            if (o.future === !1) return !0;
            var d = new Date(), e = new Date(p.date.getTime());
            switch (a) {
              case "hour":
                Q() && 12 === b && (b = 0), e.setHours(b);
                break;
  
              case "minute":
                e.setMinutes(b);
                break;
  
              case "ampm":
                var f = e.getHours(), g = f;
                b != c && (1 == b && f > 12 ? g = f - 12 : 1 == b && 12 == f ? g = 0 : 0 == b && f < 12 ? g = f + 12 : 0 == b && 12 == f && (g = 12)), 
                e.setHours(g);
                break;
  
              case "day":
                e.setDate(b);
                break;
  
              case "month":
                e.setMonth(b);
                break;
  
              case "year":
                e.setFullYear(b);
            }
            return d.setSeconds(0), d.setMilliseconds(0), e.setSeconds(0), e.setMilliseconds(0), 
            !(e.getTime() < d.getTime());
        }, J = function() {
            u = null;
        }, K = function(a, b) {
            var c = p.date.getHours(), d = I("hour", a, c), e = Q();
            if (!o.disableAmPm && o.smartHours && 12 === a && e && (d = !0), !o.validateAfter && !d) return void aa(o.references.hours);
            ca("hour", "beforeChange", a, c);
            var f = a;
            !o.disableAmPm && a > 12 && (a -= 12), _(o.references.hours, a, b), o.validateAfter && !d ? (aa(o.references.hours), 
            setTimeout(function() {
                !o.disableAmPm && c > 12 && (c -= 12), _(o.references.hours, c, b), ca("hour", "onChange", a, c), 
                ca("hour", "afterChange", a, c);
            }, o.transitionValidationDelay)) : (p.timestamp = p.date.setHours(f), !o.disableAmPm && o.smartHours && 12 === f && e ? (p.timestamp = p.date.setHours(12), 
            O(!1)) : o.disableAmPm || !o.smartHours || 23 !== f && 11 !== f || 12 !== c || e ? o.disableAmPm || o.smartHours || 12 !== f || !e ? p.timestamp = p.date.setHours(f) : p.timestamp = p.date.setHours(0) : (f = 11, 
            p.timestamp = p.date.setHours(f), O(!0)), !o.disableAmPm && f > 12 && (f -= 12, 
            O(!1)), ca("hour", "onChange", a, c), ca("hour", "afterChange", a, c));
        }, L = function() {
            var a = p.date.getHours();
            if (o.disableAmPm) return a;
            var b = Q();
            return 12 === a || 0 === a ? 12 : a < 12 && b ? a : a - 12;
        }, M = function(a, b) {
            var c = p.date.getMinutes(), d = I("minute", a, c);
            if (!o.validateAfter && !d) return void aa(o.references.minutes);
            ca("minute", "beforeChange", a, c);
            o.defaultValues.minutes;
            _(o.references.minutes, a, b), o.validateAfter && !d ? (aa(o.references.minutes), 
            setTimeout(function() {
                _(o.references.minutes, c, b), ca("minute", "onChange", a, c), ca("minute", "afterChange", a, c);
            }, o.transitionValidationDelay)) : (p.timestamp = p.date.setMinutes(a), ca("minute", "onChange", a, c), 
            ca("minute", "afterChange", a, c));
        }, N = function() {
            return p.date.getMinutes();
        }, O = function(a) {
            if (!o.disableAmPm) {
                var b = Q();
                if (!I("ampm", a, b)) return ba(o.references.ampm, a), q.isSafari && setTimeout(function() {
                    P(o.references.ampm, b);
                }, 10), !1;
                ca("ampm", "beforeChange", a, b);
                var c = p.date.getHours();
                L();
                return Q() !== a && (1 == a && c >= 12 ? (c -= 12, p.timestamp = p.date.setHours(c)) : 0 == a && c < 12 && (c += 12, 
                p.timestamp = p.date.setHours(c))), p.ampm = a, P(o.references.ampm, a), ca("ampm", "onChange", a, b), 
                ca("ampm", "afterChange", a, b), !0;
            }
        }, P = function(a, d) {
            if (!o.disableAmPm) {
                var e = b(a), f = c(e, "form");
                f.ampm.value = d ? "1" : "0";
                var g = d ? "AM" : "PM", h = c(f, 'input.mtr-input[type="radio"][value="1"]'), i = c(f, 'input.mtr-input[type="radio"][value="0"]'), j = c(f, 'label[for="' + o.targetElement + "-radio-ampm-" + g + '"]');
                c(j, "checkbox");
                d ? (h.setAttribute("checked", ""), h.checked = !0, i.removeAttribute("checked")) : (i.setAttribute("checked", ""), 
                i.checked = !0, h.removeAttribute("checked"));
            }
        }, Q = function() {
            var a = p.date.getHours();
            return a >= 0 && a <= 11;
        }, R = function() {
            return !Q();
        }, S = function(a, b) {
            var c = p.date.getDate(), d = I("day", a, c);
            if (!o.validateAfter && !d) return void aa(o.references.dates);
            ca("day", "beforeChange", a, c), _(o.references.dates, a, b), o.validateAfter && !d ? (aa(o.references.dates), 
            setTimeout(function() {
                _(o.references.dates, c, b), ca("day", "onChange", a, c), ca("day", "afterChange", a, c);
            }, o.transitionValidationDelay)) : (p.timestamp = p.date.setDate(a), ca("day", "onChange", a, c), 
            ca("day", "afterChange", a, c));
        }, T = function() {
            return p.date.getDate();
        }, U = function(a, b) {
            var c = p.date.getMonth(), d = I("month", a, c);
            if (!o.validateAfter && !d) return void aa(o.references.months);
            ca("month", "beforeChange", a, c), _(o.references.months, a, b), o.validateAfter && !d ? (aa(o.references.months), 
            setTimeout(function() {
                _(o.references.months, c, b), ca("month", "onChange", a, c), ca("month", "afterChange", a, c);
            }, o.transitionValidationDelay)) : (p.timestamp = p.date.setMonth(a), G(a), ca("month", "onChange", a, c), 
            ca("month", "afterChange", a, c));
        }, V = function() {
            return p.date.getMonth();
        }, W = function(a, b) {
            var c = p.date.getFullYear(), d = I("year", a, c);
            if (!o.validateAfter && !d) return void aa(o.references.years);
            ca("year", "beforeChange", a, c), G(void 0, a), _(o.references.years, a, b), o.validateAfter && !d ? (aa(o.references.years), 
            setTimeout(function() {
                _(o.references.years, c, b), ca("year", "onChange", a, c), ca("year", "afterChange", a, c);
            }, o.transitionValidationDelay)) : (p.timestamp = p.date.setFullYear(a), ca("year", "onChange", a, c), 
            ca("year", "afterChange", a, c));
        }, X = function() {
            return p.date.getFullYear();
        }, Y = function() {
            return L() + ":" + N() + " " + (Q() ? "AM" : "PM");
        }, Z = function(a) {
            var b = ea(a);
            p.date = new Date(b), p.timestamp = b;
            var c = p.date.getHours(), d = N(), e = c >= 0 && c < 12, f = T(), g = V(), h = X();
            c = 0 === c ? 12 : c, K(c), M(d), U(g), W(h), S(f), O(e);
        }, $ = function() {
            return p.date.getTime();
        }, _ = function(a, e, f) {
            var g = b(a);
            if (f = f || !1, g) {
                var h = c(g, ".mtr-content"), i = c(g, '.mtr-values .mtr-default-value[data-value="' + e + '"]'), j = c(g, ".mtr-arrow.up"), k = c(g, ".mtr-input");
                scrollTo = d(h, i) + j.clientHeight, k.value = e, k.setAttribute("data-old-value", e), 
                o.animations === !1 || f ? i.scrollIntoView() : da(h, scrollTo, o.transitionDelay);
            }
        }, aa = function(a) {
            var d = b(a), e = c(d, ".mtr-content");
            f(e, "mtr-error"), setTimeout(function() {
                g(e, "mtr-error");
            }, o.transitionValidationDelay + 300);
        }, ba = function(a, d) {
            "boolean" == typeof d && (d = d === !0 ? 1 : 0);
            var e = b(a), h = c(e, '.mtr-input[value="' + d + '"]');
            f(h, "mtr-error"), setTimeout(function() {
                g(h, "mtr-error");
            }, o.transitionValidationDelay + 300);
        }, ca = function(a, b, c, d) {
            var e = function(b) {
                b(a, c, d);
            };
            switch (s[b][a].forEach(function(a) {
                e(a);
            }), s[b].all.forEach(function(a) {
                e(a);
            }), a) {
              case "hour":
              case "minute":
              case "ampm":
                s[b].time.forEach(function(a) {
                    e(a);
                });
                break;
  
              case "day":
              case "month":
              case "year":
                s[b].date.forEach(function(a) {
                    e(a);
                });
            }
        }, da = function(a, b, c) {
            if (b = Math.round(b), !((c = Math.round(c)) < 0)) {
                if (0 === c) return void (a.scrollTop = b);
                var d = Date.now(), e = d + c, f = a.scrollTop, g = b - f, h = function(a, b, c) {
                    if (c <= a) return 0;
                    if (c >= b) return 1;
                    var d = (c - a) / (b - a);
                    return d * d * (3 - 2 * d);
                }, i = a.scrollTop, j = function() {
                    if (a.scrollTop == i) {
                        var b = Date.now(), c = h(d, e, b), k = Math.round(f + g * c);
                        a.scrollTop = k, b >= e || a.scrollTop === i && a.scrollTop !== k || (i = a.scrollTop, 
                        setTimeout(function() {
                            j();
                        }, 0));
                    }
                };
                setTimeout(function() {
                    j();
                }, 0);
            }
        }, ea = function(a) {
            var b = 60 * o.minutes.step * 1e3, c = 0;
            return o.minutes.step > 1 && (c = (b - a % b) % a), a + c;
        }, fa = null, ga = null, ha = function() {
            return p.date.toDateString();
        }, ia = function() {
            return p.date.toGMTString();
        }, ja = function() {
            return p.date.toISOString();
        }, ka = function() {
            return p.date.toLocaleDateString();
        }, la = function() {
            return p.date.toLocaleString();
        }, ma = function() {
            return p.date.toLocaleTimeString();
        }, na = function() {
            return t.timezones ? ha() + " " + oa() : p.date.toString();
        }, oa = function() {
            if (t.timezones) {
                var a = "";
                return a += p.date.toTimeString().split(" ")[0], a += " GMT" + (o.utcTimezone.offset > 0 ? "+" : "-") + (Math.abs(o.utcTimezone.offset) < 10 ? "0" : "") + Math.abs(o.utcTimezone.offset) + "00", 
                a += " (" + o.utcTimezone.abbr + ")";
            }
            return p.date.toTimeString();
        }, pa = function() {
            return p.date.toUTCString();
        }, qa = function(a) {
            function b(a, b, c) {
                var d = "#%#", e = new RegExp(b + "(?!" + d + ")", "g");
                return a = a.replace(e, c + d);
            }
            function c(a) {
                return a <= 9 ? "0" + a : a;
            }
            function d(a, b) {
                return o.disableAmPm ? a : 12 === a ? b ? 0 : 12 : b ? a : a + 12;
            }
            var e = L(), f = N(), g = Q(), h = T(), i = V() + 1, j = X(), k = o.utcTimezone.offset;
            return a = b(a, "DD", c(h)), a = b(a, "D", h), a = b(a, "YYYY", j), a = b(a, "YY", j.toString().substr(2)), 
            a = b(a, "Y", j), a = b(a, "HH", c(d(e, g))), a = b(a, "hh", c(e)), a = b(a, "H", d(e, g)), 
            a = b(a, "h", e), a = b(a, "mm", c(f)), a = b(a, "m", N()), a = b(a, "a", g ? "am" : "pm"), 
            a = b(a, "A", g ? "AM" : "PM"), a = b(a, "MMM", o.monthsNames[i - 1]), a = b(a, "MM", c(i)), 
            a = b(a, "M", i), a = b(a, "ZZ", (k > 0 ? "+" : "-") + c(Math.abs(k)) + ":00"), 
            a = b(a, "Z", (k > 0 ? "+" : "-") + Math.abs(k) + ":00"), a = a.split("#%#").join("");
        }, ra = function(a, b) {
            s.onChange[a].push(b);
        }, sa = function(a, b) {
            s.beforeChange[a].push(b);
        }, ta = function(a, b) {
            s.afterChange[a].push(b);
        };
        this.init = w, this.setConfig = x, this.getFullTime = Y, this.getTimestamp = $, 
        this.setHours = K, this.setMinutes = M, this.setAmPm = O, this.setDate = S, this.setMonth = U, 
        this.setYear = W, this.setTimestamp = Z, this.values = p, this.toDateString = ha, 
        this.toGMTString = ia, this.toISOString = ja, this.toLocaleDateString = ka, this.toLocaleString = la, 
        this.toLocaleTimeString = ma, this.toString = na, this.toTimeString = oa, this.toUTCString = pa, 
        this.format = qa, this.onChange = ra, this.beforeChange = sa, this.afterChange = ta, 
        w(a);
    }
  
      </script>
  
      <script>
      function SendTime()
      {
        console.log("time button was clicked!");
      
        var message = myDatepicker.format('DD.MM.YYYY hh:mm');
      console.log(message);
      
        var xhr = new XMLHttpRequest();
        var url = "/time/send";
  
        xhr.addEventListener("load", transferComplete);
        xhr.addEventListener("error", transferFailed);
      
        xhr.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            // Typical action to be performed when the document is ready:
            if(xhr.responseText != null){
              console.log(xhr.responseText);
            }
          }
        };
      
        xhr.open("POST", url, true);
        xhr.send(message);
  
      };
      
      function transferComplete(evt)
      {
        var mySnack = document.getElementById("snackbar");
        mySnack.textContent  = "Data successfully sent";
          mySnack.className = "show";
          setTimeout(function(){ mySnack.className = mySnack.className.replace("show", ""); }, 3000);
      }
  
      function transferFailed(evt)
      {
        var mySnack = document.getElementById("snackbar");
        mySnack.textContent  = "Oops, something went wrong..";
          mySnack.className = "show";
          setTimeout(function(){ mySnack.className = mySnack.className.replace("show", ""); }, 3000);
      }
    </script>
  
      <script>
      var config = {
        target: 'scriptDatepicker',
        disableAmPm: true,
        minutes: {
        min: 0,
        max: 59,
        step: 1
      }
      };
      var myDatepicker = new MtrDatepicker(config);
    </script>
  
    </body>
  </html>
  


)=====";
