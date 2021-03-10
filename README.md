# Pca9685-lib

---

# <a href="https://github.com/adarshkumarsingh83/Pcf8574-lib/archive/main.zip"> Library download link </a>

## About the Lib
```
Pca9685-lib is for supporing multiple Pca9685 boards together 
in chain with less complexcity of the programming 

max we can connect 64 Pca9685 together in chain which will give extra 1024 pins for operations 
this api support a simple interface where we can controll 1-1024 pins by its sequence number 
respected to their sequence in the chain 

pin number will start from 1 to (number of board X 16 pin per board)

NOTE: Order of Pca9685 board address wise must be in sequence otherwise it will not work in expected manner 
```


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
    and one gnd from the external power supply to the arduino for common gnd setup 

connect the other pca9684 in the chain with 1st soder which has address 41 
connect the other pca9684 in the chain with 2nd soder which has address 42 

NOTE please refer the pca9684 board configuation details section
```

## Pca9684 Configuation Details 
### soldering for pca9685 board for adddress configuation in dasi chain
![img](/image/pca9685-soldering-address-chart.png)