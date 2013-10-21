import serial
import simplejson as json
import requests

# MD5 hash from  http://www.miraclesalad.com/webtools/md5.php
myhash = "d9ffaca46d5990ec39501bcdf22ee7a1"
appname = "dddd"    # name content isnt relevant

light = 1           # this is the Hue bulb we are working with

# --- get status of bulb
huehub = "http://192.168.2.18/api/"+ myhash + "/lights/" + str(light)
reply= requests.get (huehub)
a=json.loads(reply.text)

# input command prompt
#input_cmds = {'p': 'Toggle power', 'r': 'Red lighting',
#              'g': 'Green lighting', 'b': 'Blue lighting'}
#print "The possible input commands are: "
#for key in input_cmds:
#    print key, ": ", input_cmds[key]
#while True:
#    cmd = raw_input("Enter a command: ")
#    for key in input_cmds:
#        if cmd not in input_cmds:
#            print "Error. Command not recognized. Try again."
#            cmd = raw_input("Enter a command:")
#        else:
#            break
#    break

# initialize serial port
connected = False
ser = serial.Serial("COM3", 9600, timeout=5)
line = ser.readline()
ser.write("p")
line = ser.readline()

print "Arduino returned: %s" % line

if line == "P":
    if a['state']['on'] == True :
        print "lamp was ON, now turning it off"
        onoff = False
    else:
        print "lamp was OFF, now turning it on"
        onoff = True

    # --- set new state of bulb
    payload= json.dumps({"on":onoff})
    sethuehub = huehub + "/state"
    reply= requests.put (sethuehub, data=payload)

    ser.close()
