import random

def PassGen(lenght):
    output = ""
    for i in range(lenght):
        tmp = random.randint(0, 2)
        if tmp == 0:
            output += str(random.randint(0, 9))
        elif tmp == 1:
            output += chr(random.randint(65, 90))
        else:
            output += chr(random.randint(97, 122)) 
    return output

lenght = 10
for i in range(20):
    password = PassGen(lenght)
    print(password)

