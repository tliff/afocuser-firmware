#include <Arduino.h>
#include "DRV8825.h"


#define MOTOR_STEPS 200

#define DIR 12
#define STEP 11

#define ENABLE 10


DRV8825 stepper(MOTOR_STEPS, DIR, STEP, ENABLE	);

String command;



void setup() {
  stepper.setRPM(50);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
      char received = Serial.read();
      if(received == '\n'){
        stepper.move(command.toInt()*(-1));
        Serial.write("OK\n");
        command = "";
      }
      else{
        command += received;
      }
  }
  delay(50);
}
