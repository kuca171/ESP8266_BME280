////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
////  Author: Jiri Kucera                           ////
////  Description: BME280 pressure, humidity and    ////
////               temperature sensor               ////
////  Using board: Wemos D1 mini (ESP8266)          ////
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////
  
////////////////////////////////////////////////////////
////  include libraries for sensors                 ////
////////////////////////////////////////////////////////
  
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
  
////////////////////////////////////////////////////////
////  define and set sensors                        ////
////////////////////////////////////////////////////////
  
#define SEALEVELPRESSURE_HPA (1013.25) //this is default
// value, change to the value with the current sea level 
// pressure at your location
Adafruit_BME280 bme;
  
////////////////////////////////////////////////////////
////  Setup                                         ////
////////////////////////////////////////////////////////
  
void setup() {
//initialize serial for debugging and print result
  Serial.begin(115200);
  
//initialize BME
  Serial.println(F("BME280 test"));
 
  bool status;
 
  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}
  
////////////////////////////////////////////////////////
////  Loop                                          ////
////////////////////////////////////////////////////////
  
void loop() { 
  //BME sensor read data
  float humidity = bme.readHumidity();
  float temperature = bme.readTemperature();
  int pressure =  bme.readPressure() / 100.0F;
  int bme_altitude = bme.readAltitude(SEALEVELPRESSURE_HPA);
  
  //print result to serial
  Serial.print("Humidity = ");
  Serial.print(humidity, 2);
  Serial.println(" %");
    
  Serial.print("Temperature = ");
  Serial.print(temperature, 2);
  Serial.println(" *C");
 
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" hPa");
 
  Serial.print("BME altitude = ");
  Serial.print(bme_altitude);
  Serial.println(" m");
    
  delay(2000); //delay between readings
}
