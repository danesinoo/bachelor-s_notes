f= open("msg.txt")

output = ""
for line in f:
    for char in line:
        if char == "Z": 
            output += "0"
        if char == "N":
            output += "1"

print(output)
