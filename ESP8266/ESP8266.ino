const int checkSensor1 = D1;
const int checkSensor2 = D2;
//const int LED1 = 5;
//const int LED2 = 6;
//const int LED3 = 7;
int sensorState = 0;
bool toggle = false;
unsigned long timeout;
unsigned int numOfPeople = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(checkSensor1, INPUT);
  pinMode(checkSensor2, INPUT);
  //  pinMode(LED1, OUTPUT);
  //  pinMode(LED2, OUTPUT);
  //  pinMode(LED3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  peopleCheck();
  //Serial.println(numOfPeople);
  //  if (numOfpeople >= 10) {
  //    digitalWrite(LED3, LOW);
  //  } else if (numOfpeople >= 5 ) {
  //    digitalWrite(LED2, LOW);
  //  } else if (numOfpeople >= 1 ) {
  //    digitalWrite(LED1, LOW);
  //  }
}

void peopleCheck() {
  //Check if people getting in or out
  if (toggle == false) {
    //Get in
    if (digitalRead(checkSensor1) == LOW ) {
      sensorState = 1;
      toggle = true;
      timeout = millis();
    }
    //Get out
    else if (digitalRead(checkSensor2) == LOW) {
      sensorState = 2;
      toggle = true;
      timeout = millis();
    }
  }
  //Check if people pass all the sensor
  if (toggle == true && millis() - timeout > 1000) {
    toggle = false;
    Serial.println("Sensor reset");
  } else {

    if (sensorState == 1 && digitalRead(checkSensor2) == LOW) {
      numOfPeople++;
      Serial.println("IN");
      sensorState = 0;
      toggle = false;
    } else if (sensorState == 2 && digitalRead(checkSensor1) == LOW) {
      numOfPeople++;
      Serial.println("OUT");
      sensorState = 0;
      toggle = false;
    }
  }
}

