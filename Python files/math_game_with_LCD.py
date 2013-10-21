from random import randint
import serial
math_ops = ['Add', 'Subtract', 'Multiply', 'Divide']

count = 0
score = 0

#setup serial
ser = serial.Serial("COM4", 9600, timeout=5) #ensure correct COM port
line = ser.readline()

while count < 5:
    index = randint(0,3)

    # Addition
    if math_ops[index] == "Add":
        num1 = randint(1, 10)
        num2 = randint(1, 10)
        add = num1 + num2
        ans = int(raw_input("What is %d + %d? \n" %(num1, num2)))
        if ans == add:
            print "Correct! \n"
            score += 1
            count += 1
        elif ans != add:
            print "Wrong! Answer is %d \n" %add
            count += 1

    #Subtraction
    if math_ops[index] == "Subtract":
        num1 = randint(1, 10)
        num2 = randint(1, 10)
        if num1 >= num2:
            sub = num1 - num2
            ans = int(raw_input("What is %d - %d? \n" %(num1, num2)))
        else:
            sub = num2 - num1
            ans = int(raw_input("What is %d - %d? \n" %(num2, num1)))

        if ans == sub:
            print "Correct! \n"
            score += 1
            count += 1
        elif ans != sub:
            print "Wrong! Answer is %d \n" %sub
            count += 1

    #Multiplication
    if math_ops[index] == "Multiply":
        num1 = randint(1, 10)
        num2 = randint(1, 10)
        mult = num1 * num2
        ans = int(raw_input("What is %d x %d? \n" %(num1, num2)))
        if ans == mult:
            print "Correct! \n"
            score += 1
            count += 1
        elif ans != mult:
            print "Wrong! Answer is %d \n" %add
            count += 1

    #Division
    if math_ops[index] == "Divide":
        remainder = 1
        while remainder != 0:
            num1 = randint(1, 10)
            num2 = randint(1, 10)
            if num1 >= num2:
                if num1 % num2 == 0:
                    remainder = 0
                    div = num1 / num2
                    ans = int(raw_input("What is %d / %d? \n" %(num1, num2)))
            elif num2 >= num1:
                if num2 % num1 == 0:
                    remainder = 0
                    div = num2 / num1
                    ans = int(raw_input("What is %d / %d? \n" %(num2, num1)))
        if ans == div:
            print "Correct! \n"
            score += 1
            count += 1
        elif ans != div:
            print "Wrong! Answer is %d \n" %div
            count += 1

print "Your final score is %d/%d" %(score, count)
            
        
        
