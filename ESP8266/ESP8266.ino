const int checkSensor1 = 3;
const int checkSensor2 = 4;
const int lightRow[] = {5, 6, 7};
const int lightThreshold[] = {1, 5, 10};
int sensorState = 0;
bool lightState = false;
bool toggle = false;
unsigned int numOfPeople = 0;
unsigned long timeout;

void setup() {
  Serial.begin(115200);
  pinMode(checkSensor1, INPUT);
  pinMode(checkSensor2, INPUT);
  for (int row : lightRow)
    pinMode(row, OUTPUT);
}

void loop() {
  inOutSensor();
  turnTheLight();
}

void inOutSensor() {
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


