#include <iostream>
#include<cstdio>
#include<ctype.h>
using namespace std;

int main()
{
    char str[50];
    gets(str);
    
    int counter = 0, vowels = 0, consonants = 0 , hard = 0, easy = 0;
    
    for(int i = 0; str[i] != '\0'; i++){
        
        if(counter == 4 && str[i] != ' ')
            continue;
            
        if(str[i] == ' '){
            if(counter == 4 || consonants > vowels)
                hard++;
            else 
                easy++;
            counter = 0;
            vowels = 0;
            consonants = 0;
            continue;
        }
        
        switch(tolower(str[i])){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u': vowels++;
                      counter = 0;
                      break;
            default: consonants++;
                     counter++;
        }
        
    }
    
    if(counter == 4 || consonants > vowels)
        hard++;
    else 
        easy++;
    
    cout<<5*hard + 3*easy;
    
    return 0;
}