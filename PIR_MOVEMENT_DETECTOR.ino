/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
//#define BLYNK_TEMPLATE_ID           "TMPxxxxxx"
//#define BLYNK_TEMPLATE_NAME         "Device"
//#define BLYNK_AUTH_TOKEN            "YourAuthToken"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "YourNetworkName";
char pass[] = "YourPassword";

#define PIR_SENSOR 4
BlynkTimer timer;

void movementdetected()
{
  int movementisdetected = digitalRead(PIR_SENSOR);
  Serial.println(movementisdetected);
  if (movementisdetected==1) {
    Serial.println("Movement Detected in Home");
    Blynk.logEvent("MOVEMENT DETECTED","MOVEMENT DETECTED");
//    flag=1;
  }
  else if (movementisdetected==0)
  {
   // flag=0;
  }
}

void setup()
{
  Serial.begin(9600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(PIR_SENSOR, INPUT);
  timer.setInterval(5000L, movementdetected);
}

void loop()
{
  Blynk.run();
  timer.run();
}

