//CODE FOR ESP32 RC  
// Universal Motor Control Code with Bluetooth   
#define MOTOR_A_IN1 14 
#define MOTOR_A_IN2 27 
#define MOTOR_A_ENA 12 
#define MOTOR_B_IN3 26  
#define MOTOR_B_IN4 25  
#define MOTOR_B_ENB 33  
 
#include <BluetoothSerial.h>  
BluetoothSerial SerialBT;  
String device_name = "ESP32_B-Ty";  
// OPTIMIZED SPEED SETTINGS (SAME AS BEFORE)  
int MAX_SPEED = 255;            
// Absolute maximum  
int FORWARD_BACKWARD_SPEED = 240;  // Almost max for forward/backward (95%)  
int SIDEWAYS_TURN_SPEED = 230;     // Level 4-5 for sideways turns (90%)  
int DIAGONAL_SPEED_MAIN = 240;     // Main motor in diagonals  
int DIAGONAL_SPEED_SECONDARY = 220; // Secondary motor in diagonals  
void setup() {  
Serial.begin(115200);  
// Initialize motor pins  
pinMode(MOTOR_A_IN1, OUTPUT);  
pinMode(MOTOR_A_IN2, OUTPUT);  
pinMode(MOTOR_B_IN3, OUTPUT);  
pinMode(MOTOR_B_IN4, OUTPUT);  
pinMode(MOTOR_A_ENA, OUTPUT);  
pinMode(MOTOR_B_ENB, OUTPUT);  
    
  // Stop all motors initially  
  stopMotors();  
    
  // Initialize Bluetooth  
  SerialBT.begin(device_name);  
    
  Serial.println("=== REVERSED DIRECTION MOTOR CONTROL ===");  
  Serial.println("Device Name: " + device_name);  
  Serial.println("  Forward/Backward: 95% (Almost MAX)");  
  Serial.println("    Sideways Turns: 90% (Level 4-5)");  
  Serial.println("     MOTOR DIRECTIONS ARE REVERSED");  
  Serial.println("Commands: F-forward, B-backward, L-left, R-right, S-stop");  
  Serial.println("Speed: 1-60%, 2-75%, 3-85%, 4-90%, 5-95%, 6-100%");  
  Serial.println("Connect via Bluetooth to: " + device_name);  
}  
  
void loop() {  
  // Check Bluetooth connection  
  if (SerialBT.available()) {  
    char command = SerialBT.read();  
    Serial.print("BT Command: ");  
    Serial.println(command);  
      
    switch(command) {  
      case 'F': moveForward(FORWARD_BACKWARD_SPEED); SerialBT.println("Forward   95%");  
break;  
      case 'B': moveBackward(FORWARD_BACKWARD_SPEED); SerialBT.println("Backward   95%"); break;  
      case 'L': turnLeft(SIDEWAYS_TURN_SPEED); SerialBT.println("Left Turn     90%"); break;  
      case 'R': turnRight(SIDEWAYS_TURN_SPEED); SerialBT.println("Right Turn     90%"); break;  
      case 'S': stopMotors(); SerialBT.println("Stopped"); break;  
      case 'G': forwardLeft(); SerialBT.println("Forward Left ↗️"); break;  
      case 'I': forwardRight(); SerialBT.println("Forward Right ↖️"); break;  
      case 'H': backwardLeft(); SerialBT.println("Backward Left ↙️"); break;  
      case 'J': backwardRight(); SerialBT.println("Backward Right ↘️"); break;  
        
      // SPEED LEVELS  
      case '1': setMotorSpeed(150); SerialBT.println("Speed 60%"); break;  
      case '2': setMotorSpeed(190); SerialBT.println("Speed 75%"); break;  
      case '3': setMotorSpeed(215); SerialBT.println("Speed 85%"); break;  
      case '4': setMotorSpeed(230); SerialBT.println("Speed 90%"); break;  
      case '5': setMotorSpeed(240); SerialBT.println("Speed 95%"); break;  
      case '6': setMotorSpeed(255); SerialBT.println("Speed 100% MAX"); break;  
      case '0': setMotorSpeed(100); SerialBT.println("Speed 40% Slow"); break;  
    }  
  }  
    
  // Also check serial monitor for commands  
  if (Serial.available()) {  
    char command = Serial.read();  
    SerialBT.print("Serial Command: ");  
    SerialBT.println(command);  
      
    switch(command) {  
      case 'F': moveForward(FORWARD_BACKWARD_SPEED); break;  
      case 'B': moveBackward(FORWARD_BACKWARD_SPEED); break;  
      case 'L': turnLeft(SIDEWAYS_TURN_SPEED); break;  
      case 'R': turnRight(SIDEWAYS_TURN_SPEED); break;  
      case 'S': stopMotors(); break;  
      case '1': setMotorSpeed(150); break;  
      case '2': setMotorSpeed(190); break;  
      case '3': setMotorSpeed(215); break;  
      case '4': setMotorSpeed(230); break;  
      case '5': setMotorSpeed(240); break;  
      case '6': setMotorSpeed(255); break;  
    }  
  }  
    
  delay(100);  
}  
  
// REVERSED MOTOR DIRECTION FUNCTIONS  
  
void moveForward(int speed) {  
  Serial.println("Moving Forward   95% POWER - REVERSED DIRECTION");  
  // REVERSED: Changed HIGH/LOW to opposite  
  digitalWrite(MOTOR_A_IN1, LOW);    // Was HIGH  
  digitalWrite(MOTOR_A_IN2, HIGH);   // Was LOW  
  digitalWrite(MOTOR_B_IN3, HIGH);    // Was HIGH  
  digitalWrite(MOTOR_B_IN4, LOW);   // Was LOW  
  analogWrite(MOTOR_A_ENA, speed);  
  analogWrite(MOTOR_B_ENB, speed);  
}  
  
void moveBackward(int speed) {  
  Serial.println("Moving Backward   95% POWER - REVERSED DIRECTION");  
  // REVERSED: Changed HIGH/LOW to opposite  
  digitalWrite(MOTOR_A_IN1, HIGH);   // Was LOW  
  digitalWrite(MOTOR_A_IN2, LOW);    // Was HIGH  
  digitalWrite(MOTOR_B_IN3, LOW);   // Was LOW  
  digitalWrite(MOTOR_B_IN4, HIGH);    // Was HIGH  
  analogWrite(MOTOR_A_ENA, speed);  
analogWrite(MOTOR_B_ENB, speed);  
}  
void turnLeft(int speed) {  
Serial.println("Turning Left     90% POWER - REVERSED DIRECTION");  
// REVERSED: Changed HIGH/LOW to opposite  
digitalWrite(MOTOR_A_IN1, HIGH);   // Was LOW  
digitalWrite(MOTOR_A_IN2, LOW);    // Was HIGH  
digitalWrite(MOTOR_B_IN3, HIGH);    // Was HIGH  
digitalWrite(MOTOR_B_IN4, LOW);   // Was LOW  
analogWrite(MOTOR_A_ENA, speed);  
analogWrite(MOTOR_B_ENB, speed);  
}  
void turnRight(int speed) {  
Serial.println("Turning Right     90% POWER - REVERSED DIRECTION");  
// REVERSED: Changed HIGH/LOW to opposite  
digitalWrite(MOTOR_A_IN1, LOW);    // Was HIGH  
digitalWrite(MOTOR_A_IN2, HIGH);   // Was LOW  
digitalWrite(MOTOR_B_IN3, LOW);   // Was LOW  
digitalWrite(MOTOR_B_IN4, HIGH);    // Was HIGH  
analogWrite(MOTOR_A_ENA, speed);  
analogWrite(MOTOR_B_ENB, speed);  
}  
void forwardLeft() {  
Serial.println("Forward Left ↗️ - REVERSED DIRECTION");  
digitalWrite(MOTOR_A_IN1, LOW);    // Was HIGH  
digitalWrite(MOTOR_A_IN2, HIGH);   // Was LOW  
digitalWrite(MOTOR_B_IN3, HIGH);    // Was HIGH  
digitalWrite(MOTOR_B_IN4, LOW);   // Was LOW  
  analogWrite(MOTOR_A_ENA, DIAGONAL_SPEED_SECONDARY);  // 90% for turning motor  
  analogWrite(MOTOR_B_ENB, DIAGONAL_SPEED_MAIN);       // 95% for main motor  
}  
  
void forwardRight() {  
  Serial.println("Forward Right ↖️ - REVERSED DIRECTION");  
  digitalWrite(MOTOR_A_IN1, LOW);    // Was HIGH  
  digitalWrite(MOTOR_A_IN2, HIGH);   // Was LOW  
  digitalWrite(MOTOR_B_IN3, HIGH);    // Was HIGH  
  digitalWrite(MOTOR_B_IN4, LOW);   // Was LOW  
  analogWrite(MOTOR_A_ENA, DIAGONAL_SPEED_MAIN);       // 95% for main motor  
  analogWrite(MOTOR_B_ENB, DIAGONAL_SPEED_SECONDARY);  // 90% for turning motor  
}  
  
void backwardLeft() {  
  Serial.println("Backward Left ↙️ - REVERSED DIRECTION");  
  digitalWrite(MOTOR_A_IN1, HIGH);   // Was LOW  
  digitalWrite(MOTOR_A_IN2, LOW);    // Was HIGH  
  digitalWrite(MOTOR_B_IN3, LOW);   // Was LOW  
  digitalWrite(MOTOR_B_IN4, HIGH);    // Was HIGH  
  analogWrite(MOTOR_A_ENA, DIAGONAL_SPEED_SECONDARY);  // 90% for turning motor  
  analogWrite(MOTOR_B_ENB, DIAGONAL_SPEED_MAIN);       // 95% for main motor  
}  
  
void backwardRight() {  
  Serial.println("Backward Right ↘️ - REVERSED DIRECTION");  
  digitalWrite(MOTOR_A_IN1, HIGH);   // Was LOW  
  digitalWrite(MOTOR_A_IN2, LOW);    // Was HIGH  
  digitalWrite(MOTOR_B_IN3, LOW);   // Was LOW  
  digitalWrite(MOTOR_B_IN4, HIGH);    // Was HIGH  
  analogWrite(MOTOR_A_ENA, DIAGONAL_SPEED_MAIN);       // 95% for main motor  
analogWrite(MOTOR_B_ENB, DIAGONAL_SPEED_SECONDARY);  // 90% for turning motor  
}  
void stopMotors() {  
Serial.println("Stopping Motors");  
digitalWrite(MOTOR_A_IN1, LOW);  
digitalWrite(MOTOR_A_IN2, LOW);  
digitalWrite(MOTOR_B_IN3, LOW);  
digitalWrite(MOTOR_B_IN4, LOW);  
analogWrite(MOTOR_A_ENA, 0);  
analogWrite(MOTOR_B_ENB, 0);  
}  
void setMotorSpeed(int speed) {  
Serial.print("Setting speed to: ");  
Serial.println(speed);  
analogWrite(MOTOR_A_ENA, speed);  
analogWrite(MOTOR_B_ENB, speed);  
}  