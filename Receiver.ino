#include <SPI.h>
#include <RF24.h>
#define CE_PIN   9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, address);
  radio.startListening();
}

void loop() {
  
  if (radio.available()) {
    long receivedData;
    radio.read(&receivedData, sizeof(receivedData));
    long firstThreeDigits = receivedData / 1000;
    long lastThreeDigits = receivedData % 1000;
    float pH_value =map(firstThreeDigits, 805, 975, 900,400 ) / 100.0;
    float turbidity = map(lastThreeDigits, 0, 1023, 0, 100); // Example: mapping from 0-1023 to 0-100
    Serial.print("ph value: ");
    Serial.print(pH_value,2);
    Serial.print(", Turbidity : ");
    Serial.println(turbidity,2);
  }
}
