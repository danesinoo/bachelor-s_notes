input = 'abc'
key = 2

#solution 1
output1 = '' #copy
for i in range(len(input)):
    output1 += chr(ord(input[i]) + key)

print(output1)

#solution 2
output2 = ''
for c in input:
    output2 += chr(ord(c) + key)

print(output2)

#solution 3
output3 = ''.join([chr(ord(c) + key) for c in input])
print(output3)
