//Bucket sort
#include <stdio.h>

#define N 8
#define BUCKETS 10

void insertionSort(float bucket[], int size)
{
    int i, j;
    float key;

    for(i = 1; i < size; i++)
    {
        key = bucket[i];
        j = i - 1;

        while(j >= 0 && bucket[j] > key)
        {
            bucket[j + 1] = bucket[j];
            j--;
        }

        bucket[j + 1] = key;
    }
}

void bucketSort(float arr[], int n)
{
    float buckets[BUCKETS][N];
    int count[BUCKETS] = {0};

    int i, j, index;
    int k = 0;

    /* Step 1: Put elements into buckets */

    for(i = 0; i < n; i++)
    {
        index = arr[i] * BUCKETS;

        buckets[index][count[index]] = arr[i];

        count[index]++;
    }

    /* Step 2: Sort each bucket */

    for(i = 0; i < BUCKETS; i++)
    {
        insertionSort(buckets[i], count[i]);
    }

    /* Step 3: Combine all buckets */

    for(i = 0; i < BUCKETS; i++)
    {
        for(j = 0; j < count[i]; j++)
        {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main()
{
    float arr[N] = {
        0.78, 0.17, 0.39, 0.26,
        0.72, 0.94, 0.21, 0.12
    };

    int i;

    printf("Original array:\n");

    for(i = 0; i < N; i++)
    {
        printf("%.2f ", arr[i]);
    }

    bucketSort(arr, N);

    printf("\n\nSorted array:\n");

    for(i = 0; i < N; i++)
    {
        printf("%.2f ", arr[i]);
    }

    return 0;
}