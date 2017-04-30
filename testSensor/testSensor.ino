#include <StandardCplusplus.h>
#include <vector>
  #include <SPI.h>
#include <WiFi.h>

using namespace std;

int sensor1 = 4;
int sensor2 = 5;
bool checkIn = false;
bool checkIn1 = false;
int counting =0;

vector<int> val;

#define WIFI_SSID "A406"
#define WIFI_PASSWORD "Ninewmaxz406"






// the IP address for the shield:
IPAddress ip(192, 168, 0, 177);    

char ssid[] = "A406";    // your network SSID (name) 
char pass[] = "Ninewmaxz406"; // your network password (use for WPA, or use as key for WEP)

int status = WL_IDLE_STATUS;

void setup() {  
  // Initialize serial and wait for port to open:
  Serial.begin(115200); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true);  // don't continue
  } 

  WiFi.config(ip);

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }

  // print your WiFi shield's IP address:
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP()); 



  
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);

}

void loop() {

  maClick();
  
}
void maClick() {
  int num = digitalRead(sensor1);
  int num1 = digitalRead(sensor2);


  
  if (num == 0 && checkIn == false ) {
    val.push_back(1);
    checkIn = true;
  }
  if (num1 == 0 && checkIn1 == false) {
    val.push_back(2);
    checkIn1 = true;
  }
  //
  if (val[0] == 1 && val[1] == 2) {
  counting++;    
    Serial.println(counting);
    delay(5000);
  } else if (val[0] == 2 && val[1] == 1) {
  counting--;
    Serial.println(counting);
    delay(5000);
  }
  Serial.print("val[0] :");
  Serial.println(val[0]);
  Serial.print("val[1] :");
  Serial.println(val[1]);
  Serial.println("------------------");
  Serial.print("size :");
  Serial.println(val.size());

  if (checkIn == true && checkIn1 == true) {
    checkIn = false;
    checkIn1 = false;
  }


  if (val.size() >= 2) {
    val[0] = 0;
    val[1] = 0;
    val.erase(val.begin(), val.begin() + 2);
  }


}

