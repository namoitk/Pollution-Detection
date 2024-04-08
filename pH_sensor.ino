const int pH_sensor_pin = A0; // Analog pin the pH sensor is connected to
const float refVoltage = 5.0;  

///////////// PORT CONNECTION ///////////////
// vcc = 5v
// GND = GND
// P0 = A0

float readpH() {
  int sensorValue = analogRead(pH_sensor_pin); // input value sensor
  
  // Convert the analog value to voltage
  float voltage = sensorValue * (refVoltage / 1024.0);
  float pH = 7.0 - (voltage - 2.5); // Example: pH 7 at 2.5V
  return pH;
}

void setup() {
  Serial.begin(9600); // Initialize Serial communication
}

void loop() {
  float pH = readpH(); // Read pH value
  
  // Print the pH value to the Serial Monitor
  Serial.print("pH Value: ");
  Serial.println(pH, 2); 
}