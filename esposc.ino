#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>
//#include <OSCMessage.h>

int led1 = 19;
int led2 = 22;
int lightSensorPin = 34;
int analogValue = 0;


/* Put your SSID & Password */
const char* ssid = "ESP32_Felicia";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  analogValue = analogRead(lightSensorPin);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
    server.begin();
}

void loop(){
    udp.beginPacket("192.168.1.2", 57222);
    udp.printf("ello");
    udp.endPacket();
    analogValue = analogRead(lightSensorPin);
    Serial.println(analogValue); // Print the voltage.
    if(analogValue >= 50){
      digitalWrite(led1, HIGH);
    }
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, HIGH);
  //Wait for 1 second
  delay(1000);
  
}
