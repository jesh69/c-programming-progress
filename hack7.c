#include <stdio.h>

#define MAX_LEN 100

int main() 
{
    char ch;
    char s[MAX_LEN];
    char sen[MAX_LEN];

    // Read single character
    scanf("%c", &ch);
    
    // Read the word (single string)
    scanf("%s", s);
    
    // Read full line sentence
    // \n clears the leftover newline from previous scanf
    // %[^\n] reads the entire line including spaces
    scanf("\n%[^\n]", sen);

    // Output
    printf("%c\n", ch);
    printf("%s\n", s);
    printf("%s\n", sen);

    return 0;
}