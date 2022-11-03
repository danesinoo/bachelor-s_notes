import random
import string

#define the vocabulary
vocabulary = list(string.ascii_letters) + list(string.digits)

#if you uncomment the following line, you allow the reproducibility
#random.seed(123)

#set final variable
password = ''

#define number of iterations
password_size = 10

for i in range(password_size):
    #shuffle the vocabulary
    random.shuffle(vocabulary)

    #update the password. We take the first element of the vector
    password += vocabulary[0]

print(f"Password generated=\t{password}")
