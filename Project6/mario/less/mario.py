from cs50 import get_int


number=get_int('Height: ')
while number<1 or number>8:
    number=get_int('Height: ')

for i in range(1,number+1):
    spaces=number-i
    print(" "*spaces,end="")
    print("#"*i)
