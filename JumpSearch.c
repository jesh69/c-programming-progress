//Jump Search
#include <stdio.h>
#include <math.h>

int jumpSearch(int arr[], int n, int key)
{
    int step = sqrt(n);
    int prev = 0;

    /* Jump through the array */
    while (arr[(step < n ? step : n) - 1] < key)
    {
        prev = step;
        step = step + sqrt(n);

        if (prev >= n)
            return -1;
    }

    /* Linear search within the identified block */
    while (arr[prev] < key)
    {
        prev++;

        if (prev == (step < n ? step : n))
            return -1;
    }

    /* Element found */
    if (arr[prev] == key)
        return prev;

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

    result = jumpSearch(arr, n, key);

    if (result != -1)
        printf("Element %d found at index %d\n", key, result);
    else
        printf("Element %d not found\n", key);

    return 0;
}