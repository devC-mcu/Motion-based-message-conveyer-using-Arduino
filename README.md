# Motion-based-message-conveyer-using-Arduino


This device helps the patients and physically challenged peoples to communicate easily with thw nurse or the person who looks for them.

Hardware used :-
              Arduino nano (for transmitter part)
              Arduino uno  (for receiver part)
              ASK transmitter
              ASk receiver
              MPU6050 (accelerometer + gyroscope) sensor
              lcd module 
              sd card module 
              


The device is divided into two parts :

1. tranmitter:- microcontroller used - Arduino nano
              
              implemented on the hand or any other body part of a patient .
              mpu6050 accelerometer + gyroscope sensor detects the motion of the body part it is placed on.
              Based on the motion of the hand the message is transmitted.
              
              
 2. receiver:- microcontroller used - Arduino uno
             
               The transmitted message is received and processed by the microcontroller, according to the received data 
               the message which the patient is trying to communicate si displaye don the lcd dispaly and audio of the 
               same message is played.
               
               the audio to be played is saved in the sdcard. 
