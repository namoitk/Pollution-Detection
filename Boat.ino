//          Arduino Uno             |          NRF24L01 Module
//----------------------------------|----------------------------------
//⮙ 3.3V -------------------------> | ⮙ VCC
//⮛ GND  -------------------------> | ⮛ GND
//⮙ D9   -------------------------> | ⮙ CE
//⮙ D10  -------------------------> | ⮙ CSN
//⮙ D13  -------------------------> | ⮙ SCK
//⮙ D11  -------------------------> | ⮙ MOSI
//⮙ D12  -------------------------> | ⮙ MISO

//          Arduino Uno             |          Analog
//----------------------------------|----------------------------------
//⮙ A0 ---------------------------> | ⮙ Turbidity sensor
//⮛ A1  --------------------------> | ⮛ pH sensor

#include <SPI.h>
#include <RF24.h>
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define CE_PIN   9
#define CSN_PIN 10
RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  radio.begin();
  radio.openWritingPipe(address);
}

void loop() {
  long number1 = analogRead(A0); 
  long number2 = analogRead(A1); 
  long combinedNumber = (number1 * 1000) + number2;
  if (Serial.available() > 0) {
    char value = Serial.read();
    Serial.print(value);

    if (value == 'F') {
      forward();
    } else if (value == 'B') {
      backward();
    } else if (value == 'L') {
      left();
    } else if (value == 'R') {
      right();
    } else {
      Stop();
    }
  }
  // Send the combined data
  radio.write(&combinedNumber, sizeof(combinedNumber));
  Serial.println("Data Sent: " + String(combinedNumber));

}
void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void backward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void left() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void right() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}



