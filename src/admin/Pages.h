#include <Arduino.h>

const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML><html lang="ru-RU">
<head>
  <meta charset="UTF-8"/>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { text-align:center; }
    .vert { margin-bottom: 10%; }
    .hori{ margin-bottom: 0%; }
  </style>
</head>
<body>
  <div id="container">
    <form style="display:flex; flex-direction: column; align-items: center;" action='action' method='post'>
    <h2>ACRem</h2>
<div style="display:flex;">
    <div style="display:flex; flex-direction: column;">
        <label for="ssid">SSID:</label>
        <label for="pswd">Password:</label>
    </div>
    <div style="display:flex; flex-direction: column;">
        <input type='text' name='ssid' value='ACRem'>
        <input type='text' name='pswd' value='12345678'>
    </div>
</div>
<div style="display:flex;">
    <input type='submit' value='Изменить настройки'>
</div>
</form>
  </div>

</body>
<script>
  var deg = 0;
  function triggerFlash() {
    var xhr = new XMLHttpRequest();
    xhr.open('GET', "/flash", true);
    xhr.send();
  }
</script>
</html>)rawliteral";