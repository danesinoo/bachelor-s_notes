def operation(num1, num2, opt): 
    if opt == 0:
        return num1 + num2
    elif opt == 1:
        return num1 - num2
    elif opt == 2:
        return num1 * num2
    elif opt == 3:
        return num1 / num2
    elif opt == 4:
        return num1 % num2

input1 = 5
input2 = 6
opt = 1

tmp = operation(input1, input2, opt)
print(tmp)
