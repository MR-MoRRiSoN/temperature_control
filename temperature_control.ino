#include "temperature_control.h"
#include <BlynkSimpleEsp32.h>
#include <FirebaseESP32.h>
credentials Credentials;
#include <NTPClient.h>
#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>
#define API_KEY "AIzaSyDkalxmdT8hHeU9Ybj7ZAiS9LOoPmlAdMs"
#define DATABASE_URL "temperature-control-5f016-default-rtdb.europe-west1.firebasedatabase.app"
#define UTC_OFFSET_IN_SECONDS 14400
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
unsigned long sendDataPrevMillis = 0;
String nameOfDevice = "";
bool check = true;
const byte maxNumberOfTime=12;
String sentTime[maxNumberOfTime]={"02:13","02:14","02:15","02:16","02:17"};
int count = 1;
int resultOfTemp=-20;
String oldTime="";
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", UTC_OFFSET_IN_SECONDS);
const int REDY = 13;
const int WAIT = 12;
const int NOCON = 14;
char auth_token[33];
bool connected_to_internet = 0;
const int Erasing_button = 0;
bool k = false;
int countName = 1;
String uid = "";

//Provide credentials for your ESP server
char* esp_ssid = "TEMPERATURE CONTROL";
char* esp_pass = "12312312";





String EmailOfServer() {
  EEPROM.begin(512); //Initialasing EEPROM
  Serial.println();
  Serial.println();
  String auth_token = "";
  for (int i = 64; i < 96; ++i)
  {
    auth_token += char(EEPROM.read(i));
  }
  return auth_token;
}
String PasswordOfServer() {
  EEPROM.begin(512); //Initialasing EEPROM
  Serial.println();
  Serial.println();
  String server_pass = "";
  for (int i = 96; i < 140; ++i)
  {
    server_pass += char(EEPROM.read(i));
  }
  return server_pass;
}

String NameOfCurrentDevice() {
  int i = 0;




}


void setup()
{
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  pinMode(REDY, OUTPUT);
  pinMode(WAIT, OUTPUT);
  pinMode(NOCON, OUTPUT);
  digitalWrite(REDY, HIGH);
  digitalWrite(WAIT, HIGH);
  digitalWrite(NOCON, HIGH);

  pinMode(Erasing_button, INPUT);
  for (uint8_t t = 4; t > 0; t--) {
    Serial.println(t);
    delay(1000);
  }
  // Press and hold the button to erase all the credentials
  if (digitalRead(Erasing_button) == LOW)
  {
    Credentials.Erase_eeprom();
  }
  String auth_string = Credentials.EEPROM_Config();
  auth_string.toCharArray(auth_token, 33);

  if (Credentials.credentials_get())
  {
    connected_to_internet = 1;
    digitalWrite(REDY, HIGH);
    digitalWrite(WAIT, HIGH);
    digitalWrite(NOCON, LOW);
  }
  else
  {
    Credentials.setupAP(esp_ssid, esp_pass);
    connected_to_internet = 0;
    digitalWrite(REDY, LOW);
    digitalWrite(WAIT, LOW);
    digitalWrite(NOCON, HIGH);
  }


  if (connected_to_internet)
  {
    String USER_EMAIL = EmailOfServer();
    String USER_PASSWORD = PasswordOfServer();
    String nameis = "-------------                 ";
    timeClient.begin();
    Serial.println();
    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
    config.api_key = API_KEY;
    auth.user.email = USER_EMAIL;
    auth.user.password = USER_PASSWORD;
    config.database_url = DATABASE_URL;
    config.token_status_callback = tokenStatusCallback; // see addons/TokenHelper.h
    Firebase.begin(&config, &auth);
    if (Firebase.ready()) {
      Serial.print("Being processed queue ID: ");
      uid = auth.token.uid.c_str();
      Serial.print("User UID: ");
      Serial.print(uid);
    } else {
      digitalWrite(REDY, HIGH);
      digitalWrite(WAIT, HIGH);
      digitalWrite(NOCON, LOW);
    }
    Firebase.reconnectWiFi(true);
    Firebase.setDoubleDigits(5);
    while (true) {

      Firebase.getString(fbdo, "listOfFrigRefrig/" + String(countName) + "/uid"  );
      nameis = fbdo.stringData();
      digitalWrite(REDY, LOW);
      digitalWrite(WAIT, LOW);
      digitalWrite(NOCON, HIGH);
      delay(1000);
      digitalWrite(REDY, LOW);
      digitalWrite(WAIT, HIGH);
      digitalWrite(NOCON, LOW);
      delay(1000);

      if (uid == nameis) {
        Serial.println("Mail asdasddddddddddddddddddddddddddddddddddddddddd : " + nameis);
        Firebase.getString(fbdo, "listOfFrigRefrig/" + String(countName) + "/title"  );
        nameOfDevice = fbdo.stringData();
        Serial.println(nameOfDevice);
        digitalWrite(REDY, HIGH);
        digitalWrite(WAIT, LOW);
        digitalWrite(NOCON, LOW);
        break;
      }
      countName++;
    }
  }
}



void loop()
{
  Credentials.server_loops();
  if (connected_to_internet)
  {
    timeClient.update();
    String currentTtime = getTimeStampString();
    String currentDataBase = getDayMonthYearString();
    String detectNextMemberIndex;
    if (check == true) //detect last member in base if it is 
    {
      Firebase.getString(fbdo, "TemperatureControl/" + currentDataBase+"/"+nameOfDevice);
      detectNextMemberIndex = fbdo.stringData();
      for (int i = 1; i < detectNextMemberIndex.length(); i++)
      {
        if(detectNextMemberIndex.substring(i,i-1)==",")
        {
          count++;
          } 
      }
      
       check=false;
    }
    for(int i=0; i<maxNumberOfTime; i++)
    {
    if(currentTtime==sentTime[i]&&oldTime!=currentTtime)
    {
      String dataBaseUrl = "TemperatureControl/" + currentDataBase + "/" + nameOfDevice + "/" + count;
     Serial.printf( Firebase.setString(fbdo, dataBaseUrl, resultOfTemp)
     ? "\n Value Succesful Uploadded In Database \n" : fbdo.errorReason().c_str());
     count++;
     Serial.println(currentTtime+"current");
     Serial.println(sentTime[i] +"sent");
      oldTime=currentTtime;
      }
    }
  Serial.println(currentTtime.toInt());
  }
  
}




String getTimeStampString() {
  time_t rawtime = timeClient.getEpochTime();
  struct tm * ti;
  ti = localtime (&rawtime);

  uint8_t hours = ti->tm_hour;
  String hoursStr = hours < 10 ? "0" + String(hours) : String(hours);

  uint8_t minutes = ti->tm_min;
  String minuteStr = minutes < 10 ? "0" + String(minutes) : String(minutes);

  return  hoursStr +":"+ minuteStr ;
}

String getDayMonthYearString() {
  time_t rawtime = timeClient.getEpochTime();
  struct tm * ti;
  ti = localtime (&rawtime);

  uint16_t year = ti->tm_year + 1900;
  String yearStr = String(year);

  uint8_t month = ti->tm_mon + 1;
  String monthStr = month < 10 ? "0" + String(month) : String(month);

  uint8_t day = ti->tm_mday;
  String dayStr = day < 10 ? "0" + String(day) : String(day);

  return "Date_" + dayStr + "-" + monthStr + "-" + yearStr;
}
