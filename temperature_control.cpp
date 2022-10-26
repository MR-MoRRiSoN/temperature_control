

#include "Arduino.h"
#include "temperature_control.h"

AsyncWebServer server(80); // Creating WebServer at port 80
WebSocketsServer webSocket = WebSocketsServer(81); // Creating WebSocket Server at port81

char _webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
 <script>
var connection = new WebSocket('ws://'+location.hostname+':81/');
connection.onopen = function () 
{  
connection.send('Connect ' + new Date()); };
 connection.onerror = function (error) 
 {   
  console.log('WebSocket Error ', error);
 };
 connection.onmessage = function (e) 
  {  
    console.log('Server: ', e.data);
  };
  function credentials_rec()
{
  var ssid = document.getElementById('ssid_cred').value;
  var pass = document.getElementById('pass_cred').value;
  var auth = document.getElementById('auth_token').value;
  var server_pass =document.getElementById('server_pass').value;
  var full_command = '#{"ssid":"'+ ssid +'", "pass":"' +pass +'","auth":"'+ auth +'", "server_pass":"' +server_pass +'"}';
  console.log(full_command);  <body>
    <div class="container">
      <div class="forms">
        <!-- Registration Form -->
        <div class="form signup">
          <span class="title">Login</span>

          <form action="#">
            <div class="input-field">
              <input
                id="ssid_cred"
                type="text"
                placeholder="WiFi Name"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="pass_cred"
                type="password"
                placeholder="WiFi Password"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="auth_token"
                type="email"
                class="password"
                placeholder="Esp-32 Authentication Mail"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="server_pass"
                type="password"
                class="password"
                placeholder="Esp-32 Authentication Password"
                required
              />
            </div>
            <div class="input-field button">
              <input type="button" value="Login" onclick="credentials_rec();" />
            </div>
          </form>
        </div>
      </div>
    </div>
  </body>  <body>
    <div class="container">
      <div class="forms">
        <!-- Registration Form -->
        <div class="form signup">
          <span class="title">Login</span>

          <form action="#">
            <div class="input-field">
              <input
                id="ssid_cred"
                type="text"
                placeholder="WiFi Name"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="pass_cred"
                type="password"
                placeholder="WiFi Password"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="auth_token"
                type="email"
                class="password"
                placeholder="Esp-32 Authentication Mail"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="server_pass"
                type="password"
                class="password"
                placeholder="Esp-32 Authentication Password"
                required
              />
            </div>
            <div class="input-field button">
              <input type="button" value="Login" onclick="credentials_rec();" />
            </div>
          </form>
        </div>
      </div>
    </div>
  </body>  <body>
    <div class="container">
      <div class="forms">
        <!-- Registration Form -->
        <div class="form signup">
          <span class="title">Login</span>

          <form action="#">
            <div class="input-field">
              <input
                id="ssid_cred"
                type="text"
                placeholder="WiFi Name"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="pass_cred"
                type="password"
                placeholder="WiFi Password"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="auth_token"
                type="email"
                class="password"
                placeholder="Esp-32 Authentication Mail"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="server_pass"
                type="password"
                class="password"
                placeholder="Esp-32 Authentication Password"
                required
              />
            </div>
            <div class="input-field button">
              <input type="button" value="Login" onclick="credentials_rec();" />
            </div>
          </form>
        </div>
      </div>
    </div>
  </body>  <body>
    <div class="container">
      <div class="forms">
        <!-- Registration Form -->
        <div class="form signup">
          <span class="title">Login</span>

          <form action="#">
            <div class="input-field">
              <input
                id="ssid_cred"
                type="text"
                placeholder="WiFi Name"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="pass_cred"
                type="password"
                placeholder="WiFi Password"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="auth_token"
                type="email"
                class="password"
                placeholder="Esp-32 Authentication Mail"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="server_pass"
                type="password"
                class="password"
                placeholder="Esp-32 Authentication Password"
                required
              />
            </div>
            <div class="input-field button">
              <input type="button" value="Login" onclick="credentials_rec();" />
            </div>
          </form>
        </div>
      </div>
    </div>
  </body>  <body>
    <div class="container">
      <div class="forms">
        <!-- Registration Form -->
        <div class="form signup">
          <span class="title">Login</span>

          <form action="#">
            <div class="input-field">
              <input
                id="ssid_cred"
                type="text"
                placeholder="WiFi Name"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="pass_cred"
                type="password"
                placeholder="WiFi Password"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="auth_token"
                type="email"
                class="password"
                placeholder="Esp-32 Authentication Mail"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="server_pass"
                type="password"
                class="password"
                placeholder="Esp-32 Authentication Password"
                required
              />
            </div>
            <div class="input-field button">
              <input type="button" value="Login" onclick="credentials_rec();" />
            </div>
          </form>
        </div>
      </div>
    </div>
  </body>
  connection.send(full_command);
  location.replace('http://'+location.hostname+'/submit');
}
  </script>
       <style>
      * {
        margin: 0;
        padding: 0;
        box-sizing: border-box;
        font-family: "Poppins", sans-serif;
      }

      body {
        height: 100vh;
        display: flex;
        align-items: center;
        justify-content: center;
        background-color: #4070f4;
      }

      .container {
        position: relative;
        max-width: 430px;
        width: 100%;
        height: 480px;
        background: #fff;
        border-radius: 10px;
        box-shadow: 0 5px 10px rgba(0, 0, 0, 0.1);
        overflow: hidden;
        margin: 0 20px;
      }

      .container .forms {
        display: flex;
        align-items: center;
        height: 480px;
        width: 200%;
        transition: height 0.2s ease;
      }

      .container .form {
        width: 50%;
        padding: 30px;
        background-color: #fff;
        transition: margin-left 0.18s ease;
      }

      .container .form .title {
        position: relative;
        font-size: 32px;
        font-weight: 600;
      }

      .form .input-field {
        position: relative;
        height: 50px;
        width: 100%;
        margin-top: 30px;
      }

      .input-field input {
        position: absolute;
        height: 100%;
        width: 100%;
        padding: 0 10px;
        border: none;
        outline: none;
        font-size: 14px;
        border-bottom: 2px solid #ccc;
        border-top: 2px solid transparent;
        transition: all 0.2s ease;
      }

      .form .button input {
        border: none;
        color: #fff;
        font-size: 18px;
        font-weight: 500;
        letter-spacing: 1px;
        border-radius: 6px;
        background-color: #4070f4;
        cursor: pointer;
        transition: all 0.3s ease;
      }
    </style>
  </head>
  <body>
    <div class="container">
      <div class="forms">
        <!-- Registration Form -->
        <div class="form signup">
          <span class="title">Login</span>

          <form action="#">
            <div class="input-field">
              <input
                id="ssid_cred"
                type="text"
                placeholder="WiFi Name"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="pass_cred"
                type="password"
                placeholder="WiFi Password"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="auth_token"
                type="email"
                class="password"
                placeholder="Esp-32 Authentication Mail"
                required
              />
            </div>
            <div class="input-field">
              <input
                id="server_pass"
                type="password"
                class="password"
                placeholder="Esp-32 Authentication Password"
                required
              />
            </div>
            <div class="input-field button">
              <input type="button" value="Login" onclick="credentials_rec();" />
            </div>
          </form>
        </div>
      </div>
    </div>
  </body>
</html>


)=====";





void _webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length)
{

  switch (type) {
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", num);
      break;
    case WStype_CONNECTED: {
        IPAddress ip = webSocket.remoteIP(num);
        Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, ip[0], ip[1], ip[2], ip[3], payload);

        // send message to client
        webSocket.sendTXT(num, "Connected");
      }
      break;
    case WStype_TEXT:
      Serial.printf("[%u] get Text: %s\n", num, payload);

      if (payload[0] == '#') 
      {
        String message = String((char*)( payload));
        message = message.substring(1);
        Serial.println(message);

        //JSON part
        DynamicJsonDocument doc(1024);
        DeserializationError error = deserializeJson(doc, message);

        String ssid = doc["ssid"];
        String pass = doc["pass"];
        String auth = doc["auth"];
        String server_pass =doc["server_pass"];
        Serial.println(ssid); Serial.println(pass);


        // Clearing EEPROM
        if (ssid.length() > 0 && pass.length() > 0) {
          Serial.println("clearing eeprom");
          for (int i = 0; i < 160; ++i) {
            EEPROM.write(i, 0);
          }


          // Storing in EEPROM
          Serial.println("writing eeprom ssid:");
          for (int i = 0; i < ssid.length(); ++i)
          {
            EEPROM.write(i, ssid[i]);
            Serial.print("Wrote: ");
            Serial.println(ssid[i]);
          }
          Serial.println("writing eeprom pass:");
          for (int i = 0; i < pass.length(); ++i)
          {
            EEPROM.write(32 + i, pass[i]);
            Serial.print("Wrote: ");
            Serial.println(pass[i]);
          }
          Serial.println("writing eeprom auth token:");
          for (int i = 0; i < auth.length(); ++i)
          {
            EEPROM.write(64 + i, auth[i]);
            Serial.print("Wrote: ");
            Serial.println(auth[i]);
          }
          EEPROM.commit();
          delay(2000);

          Serial.println("writing eeprom server pass token:");
          for (int i = 0; i < server_pass.length(); ++i)
          {
            EEPROM.write(96 + i, server_pass[i]);
            Serial.print("Wrote: ");
            Serial.println(server_pass[i]);
          }
          EEPROM.commit();
          delay(2000);

          //Restarting ESP board
          ESP.restart();
          break;
        }
     }
  }
}



void credentials::Erase_eeprom()
{
  EEPROM.begin(512); //Initialasing EEPROM
  Serial.println("Erasing...");
  Serial.println("clearing eeprom");
    for (int i = 0; i < 100; ++i) 
    {
      EEPROM.write(i, 0);
    }
   EEPROM.commit();
}



String credentials::EEPROM_Config()
{
 EEPROM.begin(512); //Initialasing EEPROM
  Serial.println();
  Serial.println();

  //---------------------------------------- Read eeprom for ssid and pass
  Serial.println("Reading EEPROM");


  for (int i = 0; i < 32; ++i)
  {
    ssid += char(EEPROM.read(i));
  }
  Serial.print("SSID: ");
  Serial.println(ssid);

  for (int i = 32; i < 64; ++i)
  {
    pass += char(EEPROM.read(i));
  }

  Serial.print("Password: ");
  Serial.println(pass);
  
  String auth_token = "";
  for (int i = 64; i < 96; ++i)
  {
    auth_token += char(EEPROM.read(i));
  }
  Serial.print("Auth Token:is ");
  Serial.println(auth_token);
  //return auth_token;
  String server_pass="";
  
  for (int i = 96; i < 140; ++i)
  {
    server_pass += char(EEPROM.read(i));
  }
  Serial.print("server_pass: ");
  Serial.println(server_pass);

 // return server_pass,auth_token;

  
}



bool credentials::credentials_get()
{
  if (_testWifi())
  {
    Serial.println("Succesfully Connected!!!");
    return true;
  }
  else
  {
    Serial.println("Turning the HotSpot On");
    return false;
  }
}



void credentials::setupAP(char* softap_ssid, char* softap_pass)
{
  
  WiFi.disconnect();
  delay(100);
  WiFi.softAP(softap_ssid,softap_pass);
  Serial.println("softap");
  _launchWeb();
  Serial.println("Server Started");
   webSocket.begin();
    webSocket.onEvent(_webSocketEvent);
}



bool credentials::_testWifi()
{
  int c = 0;
  Serial.println("Waiting for Wifi to connect");
  char* my_ssid = &ssid[0];
  char* my_pass = &pass[0];

  WiFi.begin(my_ssid, my_pass);
  while ( c < 20 ) {
    if (WiFi.status() == WL_CONNECTED)
    {
      return true;
    }
    delay(500);
    Serial.print("*");
    c++;
  }
  Serial.println("");
  Serial.println("Connect timed out, opening AP");
  return false;
}



// This is the function which will be called when an invalid page is called from client
void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}


void credentials::_createWebServer()
{
server.on("/", [](AsyncWebServerRequest * request) {
  request->send_P(200, "text/html", _webpage);
});

// Send a GET request to <IP>/get?message=<message>
server.on("/submit", HTTP_GET, [] (AsyncWebServerRequest * request) {
  String message;
   message = "Credentials received by ESP board!!!";
   request->send(200, "text/plain", message);
});

server.onNotFound(notFound);
server.begin();
  
}

void credentials::_launchWeb()
{
  Serial.println("");
  Serial.print("SoftAP IP: ");
  Serial.println(WiFi.softAPIP());
  _createWebServer();
  // Start the server

}

void credentials::server_loops()
{ 
     webSocket.loop();
}
