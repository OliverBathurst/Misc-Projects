def FirstFactorial(num): 

    i = 1
    factorial = 1
    while (num>=i):
        factorial = factorial * i
        i= i+1
    return factorial
    
# keep this function call here  
print FirstFactorial(raw_input())  