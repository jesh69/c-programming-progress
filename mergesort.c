//mergesort
#include <stdio.h>

void MergeSort(int A[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);

        Merge(A, low, mid, high);
    }
}

void Merge(int A[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    int B[100];

    while (i <= mid && j <= high)
    {
        if (A[i] <= A[j])
        {
            B[k] = A[i];
            i++;
        }
        else
        {
            B[k] = A[j];
            j++;
        }

        k++;
    }

    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}

int main()
{
    int A[100];
    int n, i;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("\nBefore Sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    MergeSort(A, 0, n - 1);

    printf("\nAfter Sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}