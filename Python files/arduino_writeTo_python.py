import serial

connected = False

ser = serial.Serial("COM3", 9600, timeout=5)
line = ser.readline()

ser.write("r")
line = ser.readline()
print "Output from arduino: %s" % line

ser.write("g")
line = ser.readline()
print "Output from arduino: %s" % line

ser.close()
