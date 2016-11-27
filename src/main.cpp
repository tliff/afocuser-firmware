#include <Arduino.h>
#include "DRV8825.h"


#define MOTOR_STEPS 200

#define DIR 4
#define STEP 3
#define MICROSTEPS 32

DRV8825 stepper(MOTOR_STEPS, DIR, STEP, 10, 11, 12);

String command;



void setup() {
  stepper.setRPM(180);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
      char received = Serial.read();
      debugSerial.write(received);
      if(received == '\n'){
        Serial.write("OK\n");
        stepper.move(command.toInt());
        command = "";
      }
      else{
        command += received;
      }
  }
  delay(50);
}
