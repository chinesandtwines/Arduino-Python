import serial

connected = False

ser = serial.Serial("COM3", 9600, timeout=5)
line = ser.readline()

ser.write("<rmsg>")
line = ser.readline()
#print "Output from arduino: %s" % line
print line
line = ser.readline()
print line[1:] #prints message sent from arduino without the header char

#ser.write("g")
#line = ser.readline()
#print "Output from arduino: %s" % line

ser.close()
