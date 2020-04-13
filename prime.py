import time
import datetime
num = int(input("Enter a number: "))
primes = [2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59]
start_time = time.monotonic()
def isprime(n,debug=False):
    for i in primes:
        if i * i > n:
            primes.append(n)
            return True
        elif n % i == 0:
            if debug:
                print(n, 'is divisible by', i)
            return False
    return True
        
for i in range(61,int(num**0.5),2):
    isprime(i)
if isprime(num,debug=True):
    print(num, 'is prime')
else:
    print(num, 'is composite')
end_time = time.monotonic()
print(datetime.timedelta(seconds = end_time - start_time))