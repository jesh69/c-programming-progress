#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d", &n);
    
    int len = 2 * n - 1; // Correct size for the pattern
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            int layer = i;

            if(j < layer)
                layer = j;

            if(len - 1 - i < layer)
                layer = len - 1 - i;

            if(len - 1 - j < layer)
                layer = len - 1 - j;

            // Use 'n' instead of hardcoded '4'
            printf("%d ", n - layer);
        }
        printf("\n");
    }
    return 0;
}