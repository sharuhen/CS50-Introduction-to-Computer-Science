#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[]){

    if(argc==1 || argc>2){
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int x=strlen(argv[1]);
    if(x!=26){
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int k=0;k<26;k++){
            if(isalpha(argv[1][k])!=1024){
                printf("Key must only contain alphabetic characters\n");
                return 1;
            }
    }
    string alphabet="abcdefghijklmnopqrstuvwxyz";
    int count=0;
    for(int m=0;m<26;m++){
        count=0;
        for(int i=0;i<26;i++){
            if((char)alphabet[m]==tolower(argv[1][i])){
                count++;
            }
        }
        if(count>1){
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
    }

    string plain=get_string("plaintext: ");
    printf("ciphertext: ");
    int length=strlen(plain);
    for (int i=0;i<length;i++){
        if(plain[i]>='a' && plain[i]<='z'){
            printf("%c",tolower(argv[1][plain[i]-97]));
        } else if(plain[i]>='A' && plain[i]<='Z'){
            printf("%c",toupper(argv[1][plain[i]-65]));
        } else {
            printf("%c",plain[i]);
        }
    }
    printf("\n");
    return 0;
}