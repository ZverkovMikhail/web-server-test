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
    <div style="display:flex; flex-direction: column; align-items: center;" action='action' method='post'>
    <h2>ACRem</h2>
<div style="display:flex;">
    <div style="display:flex; flex-direction: column;">
        <label for="ssid">SSID:</label>
        <label for="pswd">Password:</label>
    </div>
    <div style="display:flex; flex-direction: column;">
        <input type='text' id='ssid_id' value='ACRem'>
        <input type='text' id='pswd_id' value='12345678'>
    </div>
</div>
<div style="display:flex;">
    <input type='button' onclick="sendToServer()" value='Изменить настройки'>
</div>
</div>
  </div>

</body>
<script>
 let socket = new WebSocket("ws://192.168.4.1/ws");

socket.onopen = function(e) {
  alert("[open] Connection established");
};

socket.onmessage = function(event) {
  alert(`[message] Data received from server: ${event.data}`);
};

socket.onclose = function(event) {
  if (event.wasClean) {
    alert(`[close] Connection closed cleanly, code=${event.code} reason=${event.reason}`);
  } else {
    // e.g. server process killed or network down
    // event.code is usually 1006 in this case
    alert('[close] Connection died');
  }
};

socket.onerror = function(error) {
  alert(`[error]`);
};
 
 function sendToServer(){
  let jsonMsg = `{"wifi_settings": {"ssid":"${document.querySelector("#ssid_id").value}", "pass":"${document.querySelector("#pswd_id").value}"}}`;
alert(jsonMsg);
socket.send(jsonMsg);
 }
</script>
</html>)rawliteral";