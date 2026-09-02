//Fibonacci Search
#include <stdio.h>

int fibonacciSearch(int arr[], int n, int key)
{
    int fibMm2 = 0;       // (m-2)'th Fibonacci number
    int fibMm1 = 1;       // (m-1)'th Fibonacci number
    int fibM = fibMm2 + fibMm1;  // m'th Fibonacci number

    int offset = -1;

    /*
       Find the smallest Fibonacci number
       greater than or equal to n
    */
    while (fibM < n)
    {
        fibMm2 = fibMm1;
        fibMm1 = fibM;
        fibM = fibMm2 + fibMm1;
    }

    /*
       Search while there are elements
       remaining
    */
    while (fibM > 1)
    {
        int i = offset + fibMm2;

        if (i >= n)
            i = n - 1;

        /*
           If key is greater than arr[i],
           eliminate the left part
        */
        if (arr[i] < key)
        {
            fibM = fibMm1;
            fibMm1 = fibMm2;
            fibMm2 = fibM - fibMm1;

            offset = i;
        }

        /*
           If key is smaller than arr[i],
           eliminate the right part
        */
        else if (arr[i] > key)
        {
            fibM = fibMm2;
            fibMm1 = fibMm1 - fibMm2;
            fibMm2 = fibM - fibMm1;
        }

        /*
           Element found
        */
        else
        {
            return i;
        }
    }

    /*
       Check the remaining element
    */
    if (fibMm1 && offset + 1 < n &&
        arr[offset + 1] == key)
    {
        return offset + 1;
    }

    return -1;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50,
                 60, 70, 80, 90, 100};

    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    int result;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = fibonacciSearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}