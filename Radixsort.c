//Radix sort
#include <stdio.h>

// Find the largest number
int getMax(int a[], int n)
{
    int max = a[0];
    int i;

    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

// Counting Sort according to a particular digit
void countingSort(int a[], int n, int place)
{
    int output[100];
    int count[10] = {0};
    int i;

    // Count occurrences of each digit
    for (i = 0; i < n; i++)
    {
        int digit = (a[i] / place) % 10;
        count[digit]++;
    }

    // Find cumulative count
    for (i = 1; i < 10; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array
    for (i = n - 1; i >= 0; i--)
    {
        int digit = (a[i] / place) % 10;

        output[count[digit] - 1] = a[i];
        count[digit]--;
    }

    // Copy output back to original array
    for (i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

// Radix Sort
void radixSort(int a[], int n)
{
    int max;
    int place;

    max = getMax(a, n);

    // Process digits from units to highest digit
    for (place = 1; max / place > 0; place = place * 10)
    {
        countingSort(a, n, place);
    }
}

int main()
{
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = 8;
    int i;

    printf("Before sorting:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    radixSort(a, n);

    printf("\n\nAfter sorting:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}