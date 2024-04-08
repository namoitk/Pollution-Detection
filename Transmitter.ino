#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);

const uint64_t pipe = 0xE8E8F0F0E1LL; // Serial code to communicate

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
}

void loop() {
  // Read data from sensor 
  int sensorValue = analogRead(A0);

  // Send data
  radio.write(&sensorValue, sizeof(sensorValue));

  Serial.print("Sent: ");
  Serial.println(sensorValue);

  delay(1000); // Adjust delay as needed
}
