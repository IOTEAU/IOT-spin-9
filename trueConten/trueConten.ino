#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "EmonLib.h"                   // Include Emon Library

EnergyMonitor emon1;

unsigned long timeout;
int sensorState = 0;
bool toggle = false;
bool toggle1 = false;
int sensorone = D1;
int sensortwo = D2;
int led1 = D3;
int led2 = D4;
int led3 = D5;
int Air1 = D6;
int Air2 = D7;

int count = 0;


#define FIREBASE_HOST "datacontro.firebaseio.com"
#define FIREBASE_AUTH "T4Sj1NzCmvsoClqegpG3VnaT9DLw2FzNKgqXZ0IR"

#define WIFI_SSID "A406"
#define WIFI_PASSWORD "Ninewmaxz406"



void setup() {
  // put your setup code here, to run once:
  pinMode(sensorone, INPUT);
  pinMode(sensortwo, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(Air1, OUTPUT);
  pinMode(Air2, OUTPUT);



  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(Air1, HIGH);
  digitalWrite(Air2, HIGH);

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

  emon1.current(A0, 111.1);

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {

  people();

  
  air();
  //sensor();
}


void people() {

  Firebase.set("UserinRoom", count);
  
  if (digitalRead(sensorone) == LOW && toggle == false) {
    sensorState = 1 ;
    timeout = millis();
    toggle = true;
  } else if (digitalRead(sensortwo) == LOW && toggle == false) {
    sensorState = 2 ;
    timeout = millis();
    toggle = true;
  }

  Serial.println(sensorState);

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



   if (count == 1 ) {
    digitalWrite(led1, LOW);

      Serial.println("open");
  } else if (count == 5 ) {
    digitalWrite(led2, LOW);
    Serial.println("open5");
  } else if (count == 10) {
    digitalWrite(led3, LOW);
    Serial.println("open10");
  }

}


void air() {
  int sum = Firebase.getInt("air");

  if (sum == 1 ) {
    digitalWrite(Air1, LOW);
    Serial.println("openAir01");
  } else if (sum == 2) {
    digitalWrite(Air2, LOW);
    Serial.println("openAir02");
  }

}


void sensor() {



 
}

void energy() {
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  double power = Irms * 230.0;
  double energy = power * 1 * 1000;


  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["energy"] = energy;
  String name = Firebase.push("energy", energy);
  delay(200);
}

