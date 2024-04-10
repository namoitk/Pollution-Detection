const int turbiditySensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(turbiditySensorPin);

  // Map the analog value to a turbidity range (adjust the range as needed)
  float turbidity = map(sensorValue, 0, 1023, 0, 100); // Example: mapping from 0-1023 to 0-100

  // Print the turbidity value to the serial monitor
  Serial.print("RAW: ");
  Serial.print(sensorValue);
  Serial.print(" Turbidity: ");
  Serial.println(turbidity);

  
}
