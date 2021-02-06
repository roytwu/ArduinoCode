"""
Author:      Roy TWu
Description: serial communication test
History:     02/06/220 -- initial version      
Note:        To run this script, Arduino's serial monitor must be turned off             
"""
import serial
import math



#* ---------- ---------- ----------
#*     open serial port
#* ---------- ---------- ----------
ser = serial.Serial('COM4', 38400, timeout=1)
#ser = serial.Serial('COM4', 9600, timeout=10)

ser.write(b".") #* request data by sending a dot


#* ---------- ---------- ----------
#*     reading and segmentation
#* ---------- ---------- ----------
#* input shall be always properly terminated with EOL characters
line = ser.readline() 
serInput = line.split(b', ')
try:
    while True:
        #* keep printing until keyboard interruption
        print(len(serInput))
        if len(serInput) == 3:
            print('acc X...', float(serInput[0]))
            print('acc Y...', float(serInput[1]))
            print('acc Z...', float(serInput[2]))
            
except KeyboardInterrupt:
    print("\nwhile statement is terminated (ctrl+C)")
    pass



#* ---------- ---------- ----------
#*     close serial port
#* ---------- ---------- ----------
ser.close()
print("\nSerial communication is off")




# #* while not line_done:
# line = ser.readline() 
# angles = line.split(b", ")
    
# if len(angles) == 6:
#     ax = float(angles[0]) #*Euler angle x
#     ay = float(angles[1]) #*Euler angle y
#     az = float(angles[2]) #*Euler angle z
#     gyrX = math.radians(float(angles[3])) 
#     gyrY = math.radians(float(angles[4])) 
#     gyrZ = math.radians(float(angles[5])) 
#     line_done = 1 
    
# print('gyro data output...', gyrX, gyrZ, gyrZ)
