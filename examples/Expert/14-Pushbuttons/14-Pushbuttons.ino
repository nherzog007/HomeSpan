
////////////////////////////////////////////////////////////
//                                                        //
//    HomeSpan: A HomeKit implementation for the ESP32    //
//    ------------------------------------------------    //
//                                                        //
// Example 14: Pushbuttons                                //
//                                                        //
////////////////////////////////////////////////////////////

#include "HomeSpan.h" 
#include "DEV_Blinker.h"     
#include "DEV_Identify.h"       

void setup() {

   // Though HomeKit and the HomeKit Accessory Protocol (HAP) Specification provide a very flexible framework
   // for creating iOS- and MacOS-controlled devices, they does not contain every possible desired feature.
   //
   // One very common Characteristic HomeKit does not seem to contain is a simple pushbutton, like the type you
   // would find on a remote control.  Unlike switches that can be "on" or "off", a pushbutton has no state.
   // Rather, a pushbutton performs some action when it's pushed, and that's all it does until it's pushed
   // again.
   //
   // Though HomeKit does not contain such a Characteristic, it's easy to emulate in HomeSpan.  To do so, simply
   // define a Service with a boolen Characteristic (such as the On Characteristic), and create an update()
   // method to peform the operations to be executed when the "pushbutton" is "pressed" (i.e. set to true).
   // 
   // You could stop there and have something in HomeKit that acts like a pushbutton, but it won't look like a
   // pushbutton because every time you press the tile for your device in HomeKit, the Controller will toggle
   // between showing it's on and showing it's off.  Pressing a tile that shows the status is already ON, and will
   // change to OFF, when you actually want to re-trigger some sort of "on" action is not very satisfying.
   //
   // Ideally, we'd like HomeKit to acknowledge you've pressed the tile for the device by lighting up, sending
   // a request to update(), AND THEN resetting itself automatically to the "off" position a second or two later.
   // This would indeed emulate a light-up pushbutton.
   //
   // Fortunately, it is easy to emulate this in HomeSpan through the use of a Service's loop() function. Simply
   // code a derived Service as you normally would with its own update() method, and implement a loop() method
   // that "resets" one or more Characteristics after a set period of time.  This is similar to what we did in the
   // with loop() methods in the prior two examples, except a lot simpler since the only logic is to set the value
   // of a Characteristic to "off" after a few seconds using timeVal() and setVal().
   //
   // Example 14 demonstrates this by implementing a "pushbutton" Service to blink an LED three times.  By itself, this
   // is not very useful.  But it is a good model for showing how to implement an IR LED that sends a Volume-Up command to
   // a TV; or an RF Transmitter to control to some remote device, like a ceiling fan.
   //
   // All the functionality is wrapped up in a newly-defined "DEV_Blinker" Service, which can be found in DEV_Blinker.h.
   // This new Service is a copy of the DEV_LED service from Example 9, with modifications to make it into a generic
   // blinking LED.  As usual, changes and new lines between this Example 14, and original Example 9, are notably commented.
  
  Serial.begin(115200);

  homeSpan.begin(Category::Bridges,"HomeSpan Bridge");
  
  // Defines the Bridge Accessory
 
  new SpanAccessory();  
    new DEV_Identify("Bridge #1","HomeSpan","123-ABC","HS Bridge","0.9",3);
    new Service::HAPProtocolInformation();
      new Characteristic::Version("1.1.0");
  
  // *** NEW *** defines an LED Blinker Accessory attached to pin 16 which blinks 3 times

  new SpanAccessory();                                                          
    new DEV_Identify("LED Blinker","HomeSpan","123-ABC","20mA LED","0.9",0);
    new DEV_Blinker(16,3);                                                      // DEV_Blinker takes two arguments - pin, and number of times to blink

} // end of setup()

//////////////////////////////////////

void loop(){
  
  homeSpan.poll();
  
} // end of loop()