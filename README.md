# Arduino Powered Glove Controller

With my final project at Resilient Coders, I wanted to include something tangible that the a user could physically interact with.

I outfitted a glove with flex sensors connected to a circuit on a breadboard to an Arduino. It is used to control an animation I made in p5.js.

This was my first time working with Arduinos and hardware in general so I did lots of research to learn how to build circuits where I could get individual, readable data from each finger. I build the glove with super glue and duct tape. I am a software, not an electrical engineer after all.

## Some of the tech I used includes:

*   Arduino Microcontroller/ IDE
*   SerialPort
*   Web Sockets
*   Node
*   Express
*   HTML 5 Canvas
*   p5.js

## How Does It Work?

The glove works via the readings from the flex sensors, which are just variable resistors I bought off of amazon. The resistance of the sensor will change based on how much the sensor is bent in either direction. I thought this would be perfect to implement over the fingers where the wearer can simply bend their fingers to create resistance values.

I wrote a C program in the Arduino IDE which will take the sensor values from each sensor, concatenate them into a string, and output that string to the serial monitor each second.

Whilst the C program is running on the microcontroller, I have an Express.js server running with SerialPort which gets the data coming from a specific USB Port and the Serial Monitor on my machine. I print these values to the terminal simultaneously to ensure they are the same values from the serial port.

I also utilize a web socket in the server which allows me to get the data from the server, store it in an object, and print it to the client via a middleware JS file which holds the serialport data during the session.

In the animation file, I call on the socket.io object and access the sensor data. I split the string at the comma and take each fingers data value by using specific index values of the newly made array for each finger. From here I can control a certain aspect of the animation with how much each finger is bent.

## How to Run

You can download or clone this, run npm install but you will get an error as the program requires the hardware and the Arduino IDE in order to run properly. Feel free to reach out to me for any questions or to use this code in your own awesome project!!
