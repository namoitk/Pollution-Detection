int pH_Value;
float Voltage;

void setup() {
  pinMode(pH_Value, INPUT);
  Serial.begin(9600); // Initialize Serial communication
  
}

void loop() {
  pH_Value = analogRead(A0);
  Voltage = map(pH_Value, 805, 975, 900,400 ) / 100.0;
  Serial.print("Raw value: ");
  Serial.print(pH_Value);
  Serial.print(", pH Value: ");
  Serial.println(Voltage,2); // Print the pH value
 
  
}
