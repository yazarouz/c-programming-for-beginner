// ============================================================
// Text Analyzer & Reverser
// Author: yazarouz
// Date: 2026/02/03
// Description: 
//   A console utility that analyzes input text by counting:
//   • Alphabetic characters (letters)
//   • Numeric digits
//   • Words (space-delimited tokens)
//   And outputs the reversed version of the input string.
//   Uses standard C libraries (stdio.h, string.h, ctype.h)
// ============================================================

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define max_lenth 100

void input(char text[]){
    printf("Please input a text: ");
    fgets(text , max_lenth , stdin);

    text[strcspn(text , "\n")] = '\0';
}

int letter(const char text[]){
    int count = 0 ;
    for(int i = 0 ; text[i] ; i++){
        if(isalpha(text[i])){
            count++;
        }
    }
    return count;
}   

int digit(const char text[]){
    int count = 0 ;
    for(int i = 0 ; text[i] ; i++){
        if(isdigit(text[i])){
            count++;
        }
    }
    return count;
}

int words(const char text[]){
    int count = 0;
    int len = strlen(text);
    for(int i = 0 ; text[i] ; i++){
        if(text[i] == ' '){
            count++;
        }
    }
    if(text[len - 1] == ' '){
        return count;
    }
    else return count + 1 ;
}

void reverse(char text[]){
    int len = strlen(text);
    for(int i = 0 ; i < (len / 2) ; i++){
        char temp = text[i];
        text[i] = text[len - 1 - i];
        text[len - 1 - i] = temp;
    }
}

int main(){
    char text[max_lenth];
    int count_letter;
    int count_digit;
    int count_words;

    input(text);

    count_letter = letter(text); 
    count_digit = digit(text);
    count_words = words(text);

    printf("Orginal text: %s\n" , text);
    printf("Letter: %d\n" , count_letter);
    printf("Digit: %d\n" , count_digit);
    printf("Words: %d\n" , count_words);

    char reverse_text[max_lenth];
    strcpy(reverse_text , text);
    reverse(reverse_text);

    printf("Reverse: %s" , reverse_text);

    return 0;
}