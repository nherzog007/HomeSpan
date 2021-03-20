
// This is a placeholder .ino file that allows you to easily edit the contents of this library using the Arduino IDE,
// as well as compile and test from this point.  This file is ignored when the library is included in other sketches.

#include "PwmPin.h"

//ServoPin servo(3,18,-90);
ServoPin servo(3,18,0,500,2200,-90,90);
  
void setup(){
 
  Serial.begin(115200);
  delay(1000);

  Serial.print("\n\nTest sketch for HomeSpan Extras Library\n\n");

  Serial.println("Starting...");


  LedPin yellow(16);
  LedPin d1(19);
  LedPin d2(19);
  LedPin d3(19);
  LedPin d4(19);
  LedPin d5(19);
  LedPin d6(19);
  LedPin d7(19);
  LedPin d8(19);
  LedPin d9(19);
  LedPin d10(19);
  LedPin d11(19);
  LedPin d12(19);
  LedPin d13(19);
  LedPin d14(19);
  LedPin d15(19);
  LedPin d16(19);
  LedPin red(17);  

  while(1){
    for(int i=0;i<100;i++){
      yellow.set(i);
      delay(10);
    }
  
    for(int i=100;i>=0;i--){
      red.set(i);
      delay(10);
    }
  }

}

void loop(){

  
//  double STEP=1;
//
//  for(int i=-100*STEP;i<=100*STEP;i++){
//    servo.set((double)i/STEP);
//    delay(10);
//  }
//
//  for(int i=100*STEP;i>=-100*STEP;i--){
//    servo.set((double)i/STEP);
//    delay(10);
//  }
 
//  return;


}
