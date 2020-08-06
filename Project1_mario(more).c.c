#include <stdio.h>
#include <cs50.h>

int main(void){
    int x;
    do {
        x=get_int("Height: ");
    } while(x<1 || x>8);
    for (int i=1;i<=x;i++){
        for (int j=0;j<x-i;j++){
            printf(" ");
        }
        for (int k=1;k<=i;k++){
            printf("#");
        }
        printf("  ");
        for (int f=1;f<=i;f++){
            printf("#");
        }
        printf("\n");
    }
}