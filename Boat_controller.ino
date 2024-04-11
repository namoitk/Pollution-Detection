#define FORWARD 'F'
#define BACKWARD 'B'
#define LEFT 'L'
#define RIGHT 'R'

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  // Initialize any other necessary setup code here
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    executeCommand(command);
  }
  // Continue with other tasks in your main loop
}

void executeCommand(char command) {
  switch (command) {
    case FORWARD:
      // Perform action for moving forward
      break;
    case BACKWARD:
      // Perform action for moving backward
      break;
    case LEFT:
      // Perform action for turning left
      break;
    case RIGHT:
      // Perform action for turning right
      break;
    default:
      // Invalid command received
      break;
  }
}
      
