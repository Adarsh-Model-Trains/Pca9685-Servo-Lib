# Pca9685-Servo-Lib

---

# <a href="https://github.com/adarshkumarsingh83/Pca9685-Servo-Lib/archive/production.zip"> Library download link </a>

## About the Lib
```
Pca9685-Servo-Lib is for supporing multiple Pca9685 boards together 
in chain with less complexcity of the programming 

max we can connect 64 Pca9685 together in chain which will give extra 1024 pins for operations 
this api support a simple interface where we can controll 1-1024 pins by its sequence number 
respected to their sequence in the chain 

pin number will start from 1 to (number of board X 16 pin per board)

NOTE: Order of Pca9685 board address wise must be in sequence otherwise it will not work in expected manner 
```


###  YOUTUBE LINK FOR PCA9685 BOARD CONFIGURATION 
[![PCA9685-PWM-BOARD](http://img.youtube.com/vi/-SGKnX_kVgc/0.jpg)](https://www.youtube.com/watch?v=-SGKnX_kVgc "PCA9685-PWM-BOARD")


### YOUTUBE LINK SERVO CALIBRATION FOR OPEN AND THROW POSITION DETAILS 
[![SERVO-CALIBRATION-FOR-TURNOUT-PCA9685-PWM-BOARD](http://img.youtube.com/vi/DAPnm3rTAaE/0.jpg)](https://www.youtube.com/watch?v=DAPnm3rTAaE "SERVO-CALIBRATION-FOR-TURNOUT-PCA9685-PWM-BOARD") 

## Single Board 
![img](/image/connection-details.png)

## MultiBoard in chain 

![img](/image/multiBoard_dasichain.jpg)

### or 

![img](/image/multi_pca9685-servo.png)


## Connection details
![img](/image/connection-dettails.JPG)
```
sda and scl from arduino to pca9685 
external power supply +5v and gnd to the breadboard 
from breadboard external power supply +5v and gnd to the first pca9685  in chain to vcc and gnd 
and +5v and gnd to the 1st pca9685 sidew power inputs 
and one gnd from the external power supply to the arduino for common gnd setup 

connect the other pca9684 in the chain with 1st soder which has address 41 
connect the other pca9684 in the chain with 2nd soder which has address 42 
connect the other pca9684 in the chain with 2nd soder which has address 43 

NOTE please refer the pca9684 board configuation details section
```

## Pca9684 Configuation Details 
### soldering for pca9685 board for adddress configuation in dasi chain
![img](/image/pca9685-soldering-address-chart.png)


## steps for using lib

### YOUTUBE LINK LIBRARY AND DEMO 
[![SERVO-CALIBRATION-FOR-TURNOUT-PCA9685-PWM-BOARD](http://img.youtube.com/vi/a1wPu9dkoak/0.jpg)](https://www.youtube.com/watch?v=a1wPu9dkoak "SERVO-CALIBRATION-FOR-TURNOUT-PCA9685-PWM-BOARD") 


## include the header file
```
#include "Pca9685Board.h"

```

## define the object for the Pca9685Board
```

Pca9685Board pca9685Board;

```

## define the number of the board we are using in chain
```
#define NO_OF_BOARDS 8
```

## initialize the object with in setup method
```
void setup() {
  
   .....

  pca9685Board.initPca9685Boards(NO_OF_BOARDS);

  .......

}
```

## set the frequency for the pwm in setup 

```
void setup() {
  
   .....

 pca9685Board.setFrequency(60);

  .......

}
```

## define the right and left max position for the servo switch moter in setup
* WE HAVE TO DO THIS FOR ALL THE  SERVVO TRUNOUT CONFIGURED 
* USE CALIBRATION SKETCH FOR THIS 
```
void setup() {
  
   .....

   pca9685Board.setSwitchRange(TURNOUT_NO, openRange, closeRange);

   .......

}

```

## for debug messages a initialize Serial in setup
```
void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 

  .........
}

```


## use lib method for throwing stich 
```
void loop() {
  
  .......

   pca9685Board.throwSwitch(pinNo);
  ..........
}
```

## use lib method for closing swtich 
```
void loop() {
  
  .......

	pca9685Board.closeSwitch(pinNo);
  ..........
}
```

## use lib method for displaying state of pins 
```
void loop() {
  
  .......

	pca9685Board.displayPinState();
  ..........
}
```


### Complete Example
```
#include "Pca9685Board.h"

#define NO_OF_BOARDS 3

int MAX_PINS = 0;

Pca9685Board pca9685Board;
void setup() {
  Serial.begin(9600);
  pca9685Board.initPca9685Boards(NO_OF_BOARDS);

  MAX_PINS = NO_OF_BOARDS * 16;
  for (int i = 1; i <= MAX_PINS; i++) {
    pca9685Board.setSwitchRange(i, 100, 400);
  }
}

void loop() {
  delay(1000);

  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  pca9685Board.throwSwitch(pinNo);
  pca9685Board.displayPinState();
  delay(1000);
  pca9685Board.closeSwitch(pinNo);
  pca9685Board.displayPinState();
  delay(1000);
}

```
