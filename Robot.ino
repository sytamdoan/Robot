int state = 0; /* This variable stores the data taken from the bluetooth phone, which can then be used to move, stop, or reverse the robot*/
int bottomLeft1 = 13; /* All of these */
int bottomLeft2 = 12;
int bottomRight1 = 11;
int bottomRight2 = 10;
int topLeft1 = 7;
int topLeft2 = 6;
int topRight1 = 5;
int topRight2 = 4;
/*
 * Author: Tam Doan
 * Description: This code is used to program a robot that accepts signals from a phone(Samsung Only). The robot can move forward, backwards, and stop
 * depending on what signal is recieved. The bluetooth module used is an HCO5 and the prototype board L298N is used to reverse the motors.
 * Without the L298N, the motors can only move forward. Final note is that this project and code might be added onto later. For now, it's a robot that can
 * move with a phone's command.
 */
void setup() {
  Serial.begin(9600);

  digitalWrite(bottomLeft1,LOW);
  digitalWrite(bottomLeft2,LOW);
  digitalWrite(bottomRight1,LOW);
  digitalWrite(bottomRight2,LOW);
  digitalWrite(topLeft1,LOW);
  digitalWrite(topLeft2,LOW);
  digitalWrite(topRight1,LOW);
  digitalWrite(topRight2,LOW);
}

void loop() {

  
    if (Serial.available() > 0) {
      state = Serial.read();
    }
  
    if(state == '0') { /* This state dicates that the robot stops*/
  
      digitalWrite(bottomLeft1,LOW);
      digitalWrite(bottomLeft2,LOW);
      digitalWrite(bottomRight1,LOW);
      digitalWrite(bottomRight2,LOW);
      digitalWrite(topLeft1,LOW);
      digitalWrite(topLeft2,LOW);
      digitalWrite(topRight1,LOW);
      digitalWrite(topRight2,LOW);
      
    } else if (state == '1') { /* This state dicates that the robot moves forward*/
      
      digitalWrite(bottomLeft1,HIGH);
      digitalWrite(bottomLeft2,LOW);
      digitalWrite(bottomRight1,LOW);
      digitalWrite(bottomRight2,HIGH);
      digitalWrite(topLeft1,HIGH);
      digitalWrite(topLeft2,LOW);
      digitalWrite(topRight1,LOW);
      digitalWrite(topRight2,HIGH);
      
    } else if (state == '2') { /* This state dicates that the robot moves backwards*/
      
      digitalWrite(bottomLeft1,LOW);
      digitalWrite(bottomLeft2,HIGH);
      digitalWrite(bottomRight1,HIGH);
      digitalWrite(bottomRight2,LOW);
      digitalWrite(topLeft1,LOW);
      digitalWrite(topLeft2,HIGH);
      digitalWrite(topRight1,HIGH);
      digitalWrite(topRight2,LOW);
      
    }

}
