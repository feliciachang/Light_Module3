#include <WiFi.h>
#include <WebServer.h>
#include <WiFiUdp.h>

int led = 19;
int led2 = 22;
int led3 = 21;
int led4 = 18;
int led5 = 10;
int led6 = 5;
int lightSensorPin = 34;
int prev = 0;
int analogValue = 0;


/* Put your SSID & Password */
const char* ssid = "ESP32_Felicia";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

WebServer server(80);

WiFiUDP udp;

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  analogValue = analogRead(lightSensorPin);
  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  
    server.begin();
}

void loop() {
    udp.beginPacket("192.168.1.2", 57222);
    udp.print(analogValue);
    udp.endPacket();
    prev = analogValue;
    analogValue = analogRead(lightSensorPin);
    Serial.println(prev); // Print the voltage.
    if(analogValue > prev + 50){
      digitalWrite(led, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(led5, LOW);
      digitalWrite(led6, LOW);
    }
    else {
      digitalWrite(led, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
    }
//    digitalWrite(led1, HIGH);
//    digitalWrite(led2, HIGH);
  //Wait for 1 second
  delay(300);
}
