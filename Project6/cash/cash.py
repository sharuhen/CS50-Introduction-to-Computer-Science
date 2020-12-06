from cs50 import get_float

cash=get_float('Change owed: ')
while cash<0:
    cash=get_float('Change owed: ')

cash=cash*100;
no_coins=0;
cashleft=cash;
while cashleft>=25:
    no_coins=no_coins+1
    cashleft=cashleft-25

while cashleft>=10:
    no_coins=no_coins+1
    cashleft=cashleft-10

while cashleft>=5:
    no_coins=no_coins+1
    cashleft=cashleft-5

while cashleft>=1:
    no_coins=no_coins+1
    cashleft=cashleft-1

print(no_coins)
