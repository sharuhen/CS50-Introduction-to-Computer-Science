#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float count_letters(string y);
float count_words(string y);
float count_sentences(string y);

int main(void)
{
    string x = get_string("Text: ");
    float L = (count_letters(x) / count_words(x)) * 100;
    float S = (count_sentences(x) * 100) / count_words(x);
    float index = (0.0588 * L) - (0.296 * S) - 15.8;
    float final = round(index);

    if (final < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (final >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)final);
    }

}

float count_sentences(string y){
    int countsen = 0;
    int len=strlen(y);
    for (int i = 0 ; i < len ; i++){
        if (y[i] == '.' || y[i]=='!' || y[i]=='?'){
            countsen++;
        }
    }
    return countsen;
}

float count_words(string y){
    int countwords=0;
    int len = strlen(y);
    for (int j = 0 ; j < len ; j++){
       if(y[j] == ' '){
           countwords++;
       }
   }
   return countwords+1;
}

float count_letters (string y)
    {
    int lettercount = 0;
    int len = strlen(y);
    for (int i=0 ; i < len ; i++){
        if (isalpha(y[i]) == 1024){
            lettercount++;
        }
    }
    return lettercount;
}


