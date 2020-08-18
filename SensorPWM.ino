//>5V Motor Start/Stop and Speed Control

int ControlPin = 3;   //give your arduino pin a name
char read_char = ' ';
void setup() { // the setup routine runs once when you reset the Arduino:
  
 // pinMode(ControlPin, OUTPUT); // initialize the digital pin as an output.
  
  Serial.begin(9600);          //setup the serial monitor for viewing the active PWM control value
  
}

void loop() { // the loop routine runs over and over again forever:
  read_char = rf.read();
  Serial.println(read_char);
  if(read_char == 'A')
    {
    Serial.println("Stationary");
    analogWrite(en1,rpm0);
    analogWrite(en2,rpm0);
   
    }

    


 //Start/Stop Control
  digitalWrite(ControlPin, HIGH); // turn the motor on by making the voltage HIGH
  delay(5000);                    // wait for time seconds/1000
  digitalWrite(ControlPin, LOW);  // turn the motor off by making the voltge LOW
  delay(5000);                    // wait for time seconds/1000


 // Speed Control
  // reduce motor speed from max to min in increments of 5 points PWM:
  for (int speedPWM = 255 ; speedPWM >= 0; speedPWM -= 5) { // sets the PWM range from 255 to 0
    analogWrite(ControlPin, speedPWM);                      // writes speedPWM to the motor control pin, arduino pin 3
    Serial.println(speedPWM);                               // prints the fade value to the serial monitor to allow you to find minimum 0 load run speed 
    delay(2000);
  }

  // increase motor speed from min to max in increments of 5 points PWM:
  for (int speedPWM = 0 ; speedPWM <= 255; speedPWM += 5) {
    analogWrite(ControlPin, speedPWM);
    Serial.println(speedPWM);
    delay(2000);
  }
}
