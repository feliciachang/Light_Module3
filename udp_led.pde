import hypermedia.net.*;

int PORT = 57222;
String IP = "192.168.1.2";
UDP udp;

int sensorValue = 0;

void setup() {
  udp = new UDP(this, PORT, IP);
  udp.listen(true);
  System.out.println("starting");

  fullScreen();
  background(#F5E9DC);
  //colorMode(HSB);
}

void draw() {
  stroke(200, 130, 130, 127);
  noFill();
  ellipse(width/2, height/2, sensorValue % 2000, sensorValue % 2000);
  ellipse(width/2, height/2, sensorValue % 1000, sensorValue % 1000);

}

void receive(byte[] data, String PORT, int IP) {
   String value = new String(data);
   sensorValue = int(value);
   println(int(value));
}
