#include <SPI.h>
#include <RF24.h>

// CE and CSN pins for the NRF24L01 module
#define CE_PIN   9
#define CSN_PIN 10

// Create an instance of the RF24 class
RF24 radio(CE_PIN, CSN_PIN);

// Address for the receiver
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);

  // Initialize the NRF24L01 module
  radio.begin();
  
  // Set the receiver address
  radio.openReadingPipe(1, address);

  // Start listening
  radio.startListening();
}

void loop() {
  // Check if data is available
  if (radio.available()) {
    long receivedData;
    // Read the data
    radio.read(&receivedData, sizeof(receivedData));
    
    // Extract the first three digits
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
