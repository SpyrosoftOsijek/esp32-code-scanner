| Supported Targets | ESP32-S3 |
| ----------------- | -------- |

#  ESP32-S3 code scanner 

## Authors: Filip Hulak, Vjekoslav Pećar
## Mentor: Flip Kulić

This project includes using a camera to capture a frame from which a barcode is then detected and decoded. The program is stored and executed on an ESP32-S3 board. The project was developed through an internship at Spyrosoft.

## How to use the project

### Hardware Required

* ESP32-S3-EYE development module 
* USB cable for power supply and programming

### Software Required

The project was developed in the Visual Studio Code environment using Ubuntu. Within the IDE itself, the ESP-IDF extension was installed to significantly simplify usage. To avoid problems, using the same development environment is advised, as parts of the project may not work in different operating systems or environments. 

### Configure the project

Depending on your layout, some of the project parameters (such as PORT) might have to be changed.

### Build and flash the project

* Compile the  project:
```
idf.py build
```
* Flash the compiled project:
```
idf.py flash
```
* Power on the ESP32-S3 board and check the output:
```
idf.py monitor
```
(To exit the serial monitor, type ``Ctrl-]``.)

### Using the project

After flashing the program onto the device and checking the output using "idf.py monitor", the program will start periodically printing out the word "Loop". Point the camera module towards a barcode. If a barcode is detected, the following output will read "Loop", followed by the result which was read from the barcode. Note that the camera will need to have a specific distance and/or orientation for the barcode to be able to be properly read.

## Example Output
```
Loop
Loop
Loop
Loop
Loop12345678
Loop12345678
Loop
Loop
```

## Backend
Originally, the project was planned to have the ability to send results of detected barcodes to a web server in the form of POST requests. While the backend for this site was implemented and able to successfully handle POST requests, it has not been connected to the rest of the program, so the only way to follow and check the outputs is via monitoring.

## Troubleshooting
There are currently no plans for the development on this project to be continued, and that is unlikely to ever change.