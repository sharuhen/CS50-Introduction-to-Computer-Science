#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void){
    float number;
    int no_coins=0;
    do
    {
        number=get_float("Number: ");
    }
    while (number<0);
    int cents=round(number*100);
    int amtremain=cents;

     while (amtremain-25>=0){
         no_coins+=1;
         amtremain-=25;
         }
     while (amtremain-10>=0){
         no_coins+=1;
         amtremain-=10;
     }
    while (amtremain-5>=0){
         no_coins+=1;
         amtremain-=5;
     }
     while (amtremain-1>=0){
         no_coins+=1;
         amtremain-=1;
     }
     printf("%i",no_coins);
}
