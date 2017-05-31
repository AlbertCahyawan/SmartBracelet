# Arduino Distance Detector Using Wi-Fi Sensor (Smart-Sam)

![persasive](https://cloud.githubusercontent.com/assets/12613854/26640231/5cf13fba-4651-11e7-92eb-6bbcb78b797c.png)

COMP6124 - Pervasive Computing
Class 2016/2017
Computer Science Program
BINUS International
Jakarta
Arduino Distance Detector Using Wi-Fi Sensor (Smart-Sam)
Samuel Arief Yapadi - 1801444255
Kenny Lie - 1801443630
Albert Cahyawan - 180143631

# PROJECT DESCRIPTION
As we carry around important objects such as our phone, wallet, keys; there is a risk of losing it. Falling from our pockets, forgetting to carry and leaving the items behind are a few reasons as to why we leave our objects. We need a definite solution to solve this issue. Here is a case study showcasing the importance of not forgetting our important devices:
A boy named Lex goes to campus. Unfortunately, he forgot to bring his smartphone. Lex has no idea where he left his device. His smartphone is very important as his notes and slideshows are in his smartphone. In this scenario, the device that we’re developing is the perfect solution to this problem. As with an easy connection to the Wi-Fi module, Lex can determine the distance of his device.
To solve this problem, we have decided to create a light up ‘bracelet’ which connects to a device through Wi-Fi. The light on the ‘bracelet’ will light up with distinct colors depending on the distance between the ‘bracelet’ and the device; blue if its near, yellow on intermediate distance and red when the object is far away. This ensures that users will be alerted when the user’s important device is left behind. This project aims to reduce the amount of times we forget our devices. 

# COMPONENTS REQUIRED
The components required for this project are as follows
•	Arduino (Wemos D1)
•	LED
•	220-ohm resistor
•	Connecting wires
•	Breadboard

# HOW DOES IT WORK? 
The Wemos D1 Wi-Fi module sets up a Wi-Fi channel which is then connected to a device. We set up the Wi-Fi name as well as the password. The Wemos D1 Wi-Fi module is then coded with Arduino so that it can detect the distance between the Wi-Fi module and the device. The Wi-Fi module then detects distance when the device is connected to the Wi-Fi module. There are 3 stages of distance which is indicated by 3 distinct light colors.
-	Blue Light: 0-5 meters
-	Yellow Light: 5-15 meters
-	Red Light: 15 meters above

We can see the exact distance between the Wi-Fi module and the device through a laptop monitor. The light will also turn red if there is no device connected at all. We use a function taken from the internet to calculate the distance between the device and Wi-Fi module. 
We chose to use a Wi-Fi module for this project as we believe that a Wi-Fi module can detect objects at a greater distance; as we feel that covering further distance is very important in a system like this. 

# CIRCUIT DIAGRAM
Connect the LCD to the Arduino as follows:
•	Pin 1 on the LCD to ground on the Arduino.
•	Pin 2 on the LCD to 5V on the Arduino.
•	Pin 3 on the LCD to the middle pin on the 10K potentiometer. 
•	Pin 4 on the LCD to digital pin 2 on the Arduino.
•	Pin 5 on the LCD to the ground of Arduino. This will put the LCD in read mode.
•	Pin 6 on the LCD to the pin 3 of Arduino.
•	Connect the data pins (D4-D7) to the pins 4, 5, 6, 7 on the Arduino.
•	Pin 15 to the 5V pin on the Arduino through the 220-ohm resistor. This is the positive pin of the backlight.
•	Pin 16 to ground on the Arduino. This is the negative pin of the backlight.
Then connect the DS3231 real time clock module to the Arduino as follows:
•	GND on the DS3231 to GND on the Arduino
•	VCC on the DS3231 to the 5V pin on the Arduino
•	SCL on the DS3231 to A5 on the Arduino
•	SDA on the DS3231 to A4 on the Arduino

# INDIVIDUAL WEEKLY PROGRESS:
Samuel Arief Yapadi – 1801444255
Week 1: Decide the project design
Week 2: Set up scenario
Week 3: Succeeded in lighting up the lights
Week 4: Picture of light bulb lighting up in 3 different colours
Week 5: No progress
Week 6: Succeeded in lighting up the lights with Wi-Fi
Week 7: Succeeded in changing light color with Wi-Fi
Week 8: Enabled distance detection through Wi-Fi
Week 9: Succeeded in changing light color based on distance
Week 10: Set distance range for light
Week 11: Final video and final polishing
 Problem found and covered during project development: 
	We encountered several problems because of our insistence in using a Wi-Fi sensor instead of a Bluetooth sensor. Using a Wi-Fi sensor instead of a Bluetooth sensor is a better way for us as Wi-Fi covers more distance than Bluetooth; which explains our insistence in using this type of sensor. As there are little examples of programs that utilize Wi-Fi sensor to detect distance, our group searched the internet for several tutorials so that we can use Wi-Fi as a medium to determine distance.
Kenny Lie - 1801443630

Week 1: Determine the topic of our project
Week 2: Set up scenario
Week 3: Finish the LED traffic light with breadboard and arduino
Week 4: No progress
Week 5: Add the Wemos.CC plugins so that in can be coded with Arduino code
Week 6: Turn the built-in Light in Arduino on and off through browser on other        
   device
Week 7: Succeeded in changing light color with Wi-Fi
Week 8: Enabled distance detection through Wi-Fi
Week 9: Succeeded in changing light color based on distance
Week 10: Set distance range for light
Week 11: Final video and final polishing

 Problem found and covered during project development: 
We encountered several problems because of our insistence in using a Wi-Fi sensor instead of a Bluetooth sensor. Using a Wi-Fi sensor instead of a Bluetooth sensor is a better way for us as Wi-Fi covers more distance than Bluetooth; which explains our insistence in using this type of sensor. As there are little examples of programs that utilize Wi-Fi sensor to detect distance, our group searched the internet for several tutorials so that we can use Wi-Fi as a medium to determine distance.
Albert Cahyawan - 180143631

Week 1: Determine the topic of our project
Week 2: Create a scenario and how the device works
Week 3: Arduino comes from tokopedia
Week 4: Finish traffic light and understanding the Arduino code + photo
Week 5: All the required items are prepared and ready to use
Week 6: Connect the Arduino to Wifi
Week 7: Succeeded in changing light color with Wi-Fi
Week 8: Enabled distance detection through Wi-Fi
Week 9: Succeeded in changing light color based on distance
Week 10: Set distance range for light
Week 11: Final video and final polishing

 Problem found and covered during project development: 
We encountered several problems because of our insistence in using a Wi-Fi sensor instead of a Bluetooth sensor. Using a Wi-Fi sensor instead of a Bluetooth sensor is a better way for us as Wi-Fi covers more distance than Bluetooth; which explains our insistence in using this type of sensor. As there are little examples of programs that utilize Wi-Fi sensor to detect distance, our group searched the internet for several tutorials so that we can use Wi-Fi as a medium to determine distance.
