#include <DHT11.h>
//#include <ESP8266WiFi.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define SOIL_MOISTURE_PIN A0

DHT11 dht11(DHTPIN);

//const char* ssid = "your_SSID";
//const char* password = "your_PASSWORD";

void setup() {
    Serial.begin(9600);
    //WiFi.begin(ssid, password);
    //while (WiFi.status() != WL_CONNECTED) {
        //delay(1000);
    //}
}

void loop() {
    int humidity = dht11.readHumidity();
    int temperature = dht11.readTemperature();
    

    if(humidity != DHT11::ERROR_CHECKSUM && humidity != DHT11::ERROR_TIMEOUT){
      Serial.print("Humidity: "); Serial.print(humidity); Serial.println("%");
      
    }
    else{
      Serial.println(DHT11::getErrorString(humidity));
    }

    // Send data to server
    
    Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" ºC");
    Serial.print("Soil Moisture: "); Serial.println(readSensor());
    

    // Add code here to send data via HTTP or MQTT

    delay(5000); // Wait before next reading
}

int readSensor() {
  int soilMoisture = analogRead(SOIL_MOISTURE_PIN);  // Read the analog value from sensor


  int outputValue = map(soilMoisture, 0, 1023, 255, 0); // map the 10-bit data to 8-bit data


  //analogWrite(ledPin, outputValue); // generate PWM signal


  return outputValue;             // Return analog moisture value


}