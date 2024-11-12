#include "secrets.h"
#include <DHT.h>

#define DHTPIN 4       // GPIO pin for the DHT11
#define DHTTYPE DHT11  // Define the DHT type
#define MQ135PIN 34    // GPIO pin for MQ135
#define TEMP_THRESHOLD 50 // Temperature threshold in Celsius
#define GAS_THRESHOLD 300 // Gas threshold value (adjust based on calibration)

#define AWS_IOT_PUBLISH_TOPIC "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial  .begin(115200);
  dht.begin();
  pinMode(MQ135PIN, INPUT);
}

void loop() {
  // Read temperature and humidity from DHT11
  float temp = dht.readTemperature();
 

  // Read gas level from MQ135
  int gasLevel = analogRead(MQ135PIN);
 
  }

  // Display readings
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("% | Gas Level: ");
  Serial.println(gasLevel);

  // Check if the temperature or gas level exceeds the threshold
  if (temp > TEMP_THRESHOLD) {
    Serial.println("Warning: High temperature detected!");
    // Add code here for sending alert
  }

  if (gasLevel > GAS_THRESHOLD) {
    Serial.println("Warning: High gas level detected!");
    // Add code here for sending alert
  }

  delay(2000);  // Wait for 2 seconds before taking another reading
}