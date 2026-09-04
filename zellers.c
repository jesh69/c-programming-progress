// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int h,k,m,j,q;
    for(;;){
    printf("enter date of the month: ");
    scanf("%d",&q);
     printf("enter number of month(13 for jan & 14 for feb & 3-12 from mar-dec): ");
    scanf("%d",&m);
     printf("enter first 2 digis of the year: ");
    scanf("%d",&j);
    printf("enter last 2 digits of the year:");
    scanf("%d",&k);
   // h=(q+[13*(m+1)/5​]+k+[k/4]+[j/4​]+5*j)%7;

        if (m == 13 || m == 14) {
    k--;
    if (k < 0) {
        k = 99;
        j--;
    }
}
    h = (q + (13 * (m + 1) / 5) + k + (k / 4) + (j / 4) + 5 * j) % 7;
    if(h == 0){
        printf("SATURDAY\n");
    }
    else if(h == 1)
        printf("SUNDAY\n");
    else if(h == 2)
        printf("MONDAY\n");
    else if(h == 3)
        printf("TUESDAY\n");
    else if(h == 4)
        printf("WEDNUSDAY\n");
    else if(h == 5)
        printf("THURSDAY\n");
    else
        printf("FRIDAY\n");
            

    }    return 0;
}