#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include "EmonLib.h"                   // Include Emon Library

EnergyMonitor emon1;
//CheckPeopleSensor
const int sensorone = D1;
const int sensortwo = D2;
const int Air1 = D6;
const int Air2 = D7;
const int sensorState = 0;
const int lightThreshold[] = {1, 5, 10};
const int lightRow[] = {D3, D4, D5};
bool lightState = false;
bool toggle = false;
unsigned long timeout;
unsigned int numOfPeople = 0;


#define FIREBASE_HOST "datacontro.firebaseio.com"
#define FIREBASE_AUTH "T4Sj1NzCmvsoClqegpG3VnaT9DLw2FzNKgqXZ0IR"

#define WIFI_SSID "iPad"
#define WIFI_PASSWORD "mimimiml111"



void setup() {
  // put your setup code here, to run once:
  pinMode(sensorone, INPUT);
  pinMode(sensortwo, INPUT);
  for (int row : lightRow)
    pinMode(row, OUTPUT);
  pinMode(Air1, OUTPUT);
  pinMode(Air2, OUTPUT);



  for (int row : lightRow)
    pinMode(row, HIGH);
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

  inOutSensor();
  air();
  turnTheLight();
  energy();

}


void inOutSensor() {
  Firebase.set("UserinRoom", numOfPeople);
  //Check if people getting in or out
  if (toggle == false) {
    //Get in
    if (digitalRead(checkSensor1) == LOW ) {
      sensorState = 1;
      toggle = true;
      timeout = millis();
    }
    //Get out
    else if (digitalRead(checkSensor2) == LOW ) {
      sensorState = 2;
      toggle = true;
      timeout = millis();
    }
  }
  //Check if people pass all the sensor
  if (toggle == true && millis() - timeout < 500) {
    if (sensorState == 1 && digitalRead(checkSensor2) == LOW) {
      numOfPeople++;
      Serial.print("Number of people in the room : ");
      Serial.println(numOfPeople);
      toggle = false;
    } else if (sensorState == 2 && digitalRead(checkSensor1) == LOW) {
      numOfPeople--;
      Serial.print("Number of people in the room : ");
      Serial.println(numOfPeople);
      toggle = false;
    }
  } else {
    toggle = false;
  }
}

void air() {
  int sum = Firebase.getInt("air");

  if (sum == 1 ) {
    digitalWrite(Air1, LOW);

  } else if (sum == 2) {
    digitalWrite(Air2, LOW);

  } else if (sum == 0) {
    digitalWrite(Air1, HIGH);
    digitalWrite(Air2, HIGH);
  }

}

void turnTheLight() {
  for (int i = (sizeof(lightThreshold) / sizeof(int)) - 1; i >= 0; i--) {
    if (numOfPeople >= lightThreshold[i])
      lightState = true;
    else
      lightState = false;

    if (lightState = true)
      digitalWrite(lightRow[i], LOW);
    else
      digitalWrite(lightRow[i], HIGH);
  }
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

