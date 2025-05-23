/*********************************************************************************
 *  MIT License
 *  
 *  Copyright (c) 2020-2025 Gregg E. Berman
 *  
 *  https://github.com/HomeSpan/HomeSpan
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 ********************************************************************************/

// For developer use and testing only - provides a common set of pin numbers mapped to the Adafruit Feather Board.
// Facilitates the testing of identical code on different ESP32 chips using a common jig without rewiring

#pragma once
 
#if defined(ARDUINO_FEATHER_ESP32)
  enum {
    F13=13,F12=12,F27=27,                                             // Digital w/Touch (3 pins)
    F15=15,F32=32,F14=14,F16=16,F17=17,F21=21,                        // Digital Only (6 pins)
    F26=26,F25=25,F34=34,F39=39,F36=36,F4=4,                          // A0-A5
    F22=22,F23=23,                                                    // I2C SCL/SDA
    F5=5,F18=18,F19=19,F33=33                                         // SPI SCK/SDO/SDI/CS
  };
  #define DEVICE_SUFFIX ""

#elif defined(ARDUINO_ESP32S2_DEV)
  enum {
    F13=1,F12=3,F27=7,                                                // Digital w/Touch (3 pins)
    F15=10,F32=42,F14=11,F16=20,F17=21,F21=16,                        // Digital Only (6 pins)
    F26=17,F25=14,F34=13,F39=12,F36=18,F4=19,                         // A0-A5
    F22=9,F23=8,                                                      // I2C SCL/SDA
    F5=36,F18=35,F19=37,F33=34,                                       // SPI SCK/SDO/SDI/CS
    BUILTIN_PIXEL=18                                                  // Built-in Neo-Pixel
  };
  #define DEVICE_SUFFIX "-S2"

#elif defined(ARDUINO_ESP32C3_DEV)
  enum {
    F27=19,F32=2,F14=10,F16=20,F17=21,F21=18,                         // Digital Only (6 pins, but F16 and F17 used for Serial)
    F26=0,F25=1,F4=3,                                                 // A0/A1/A5
    F22=9,F23=8,                                                      // I2C SCL/SDA
    F5=4,F18=6,F19=5,F33=7,                                           // SPI SCK/SDO/SDI/CS
    BUILTIN_PIXEL=8                                                   // Built-in Neo-Pixel    
    };
  #define DEVICE_SUFFIX "-C3"

#elif defined(ARDUINO_ESP32S3_DEV)
  enum {
    F13=5,F12=6,F27=7,                                                // Digital w/Touch (3 pins)
    F15=16,F32=17,F14=18,F16=41,F17=40,F21=38,                        // Digital Only (6 pins)
    F26=1,F25=2,F34=20,F39=19,F36=15,F4=4,                            // A0-A5
    F22=9,F23=8,                                                      // I2C SCL/SDA
    F5=12,F18=11,F19=13,F33=10,                                       // SPI SCK/SDO/SDI/CS
    BUILTIN_PIXEL=48                                                  // Built-in Neo-Pixel        
  };
  #define DEVICE_SUFFIX "-S3"
  
#elif defined(ARDUINO_ESP32C6_DEV)
  enum {
    F12=9,F27=6,F15=7,F32=10,F14=11,F16=13,F17=12,F21=15,             // Digital Only (8 pins)
    F26=3,F25=2,F34=1,F39=0,F36=5,F4=4,                               // A0-A5
    F22=22,F23=23,                                                    // I2C SCL/SDA
    F5=21,F18=19,F19=20,F33=18,                                       // SPI SCK/SDO/SDI/CS
    BUILTIN_PIXEL=8                                                   // Built-in Neo-Pixel        
  };
  #define DEVICE_SUFFIX "-C6"
  
#elif defined(ARDUINO_WESP32)
  enum {
    F12=2,F27=32,                                                     // Digital w/Touch (2 pins)
    F26=12,F25=14,F32=18,F14=23,F21=5,F33=13,                         // Digital Only (6 pins)
    F34=35,F39=34,F36=36,F4=33,                                       // A2-A5
    F22=4,F23=15                                                      // I2C SCL/SDA
  };
  #define DEVICE_SUFFIX "-WESP32"

#endif
