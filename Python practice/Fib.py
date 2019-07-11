import math

def fibonacci(num):
  x = 0
  y = 1

  if num < 0:
    print("Not a valid input")
  elif num == 0:
    return x
  elif num == 1:
    return y
  else:
      for i in range(2,num):
        z = x + y
        x = y
        y = z
      return y

loop = True

while loop == True:
  num = input("Please select a positive integer: ")
  int_num = int(num)
  decision = input ("\nWould you like to implement a Factorial [1] or Fibonacci [2] method?: ")

  if int(decision) == 1:
    print ("\nThe Factorial of ", num, ": ")
    print (math.factorial(int(num)))

  elif int(decision) == 2:
    print("\nThe Fibonacci series at number ", num, "is: ")
    print(fibonacci(int(num) + 1))
