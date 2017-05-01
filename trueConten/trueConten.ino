#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

unsigned long timeout;
int sensorState = 0;
bool toggle = false;
bool toggle1 = false;
int sensorone = D1;
int sensortwo = D2;
int led1 =  D3;
int led2 = D4;
int led3 = D5
           int count = 0;


#define FIREBASE_HOST "test1-59b46.firebaseio.com"
#define FIREBASE_AUTH "81LyQY5oyjuS9WNN9pzdn1gIoXbtzbbk1G9y4SE2"

#define WIFI_SSID "iPad"
#define WIFI_PASSWORD "mimimiml111"



void setup() {
  // put your setup code here, to run once:
  pinMode(sensorone, INPUT);
  pinMode(sensortwo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);



  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);


  Serial.begin(115200);

  WiFi.mode(WIFI_STA);

  WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
  Serial.println("connecting....");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);

  }//loop while
  Serial.println();
  Serial.println("connecting.....");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {

  people();

  Firebase.set("num", count);

  if (count == 1 && toggle1 == false) {
    digitalWrite(led1, LOW);

    Serial.println("open");
  } else if (count == 5 && toggle1 == false) {
    digitalWrite(led2, LOW);
    Serial.println("open");
  } else if (count == 10 && toggle1 == false) {
    digitalWrite(led3, LOW);
    Serial.println("open");
  }








  void people() {
    if (digitalRead(sensorone) == LOW && toggle == false) {
      sensorState = 1 ;
      timeout = millis();
      toggle = true;
    } else if (digitalRead(sensortwo) == LOW && toggle == false) {
      sensorState = 2 ;
      timeout = millis();
      toggle = true;
    }

    if (sensorState == 1 && digitalRead(sensortwo) == LOW) {
      count++;
      Serial.println("IN");
      toggle = false;

    } else if (sensorState == 2 && digitalRead(sensorone) == LOW) {
      count--;
      Serial.println("out");
      toggle = false;
    }
    if (millis() - timeout > 5000 && toggle == true) {
      toggle = false;
    }

  }

