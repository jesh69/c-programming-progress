#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	
    int n,i,rem,rev,sum;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    for(i = 0 ; i < 5 ; i++){
    rev = 10;
    rem += n % rev;
    n /= 10;
    sum = rem;
    }
    printf("%d",sum);
    return 0;
}
