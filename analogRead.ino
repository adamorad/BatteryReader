#include <ThingerWifi101.h>

#define USERNAME "testing1992"
#define DEVICE_ID "MKR"
#define DEVICE_CREDENTIAL "12345678"

#define SSID "Too Fly for a WiFi"
#define SSID_PASSWORD "0534247973"

ThingerWifi101 thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

float yaw = 0; 

void setup() {
  // configure wifi network
  thing.add_wifi(SSID, SSID_PASSWORD);


  // more details at http://docs.thinger.io/arduino/
}

void loop() {
  thing.handle();

  yaw = analogRead(A2); 

  thing["var"] >> [](pson& out){
      out = yaw;
  };
}
