import random
auto = "abcdefghijklmnopqrstuvwxyz01234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ!@#$%^&*()?"
lower = "abcdefghijklmnopqrstuvwxyz"
upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
num = "01234567890"
spec = "!@#$%^&*()?"


name = input('Enter password name: ')
auto1 = input('auto gen a password? y/n: ')
if auto1 == "y":
    auto2 = int(input('what length?'))
    p =  "".join(random.sample(auto, auto2))
    print (p)
    auto3 = input('write to file? y/n: ')
    if auto3 == "y":
        file = open("pass.txt", "a")
        file.write("\n\n")
        file.write(name)
        file.write("\n")
        file.write(p)
        file.close()
else:
    b = int(input('Enter how many lower case letters:'))
    c = int(input('Enter how many upper case letters:'))
    d = int(input('Enter how many numbers:'))
    e = int(input('Enter how many specials:'))
    passw1 = random.sample(lower,b)
    passw2 = random.sample(upper,c)
    passw3 = random.sample(num,d)
    passw4 = random.sample(spec,e)
    final = passw1+passw2+passw3+passw4
    myString = "".join(final)
    print (myString)
    auto4 = input('write to file? y/n: ')
    if auto4 == "y":
        file = open("pass.txt", "a")
        file.write("\n\n")
        file.write(name)
        file.write("\n")
        file.write(myString)
        file.close()
