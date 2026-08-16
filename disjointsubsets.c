//disjoint subsets 
#include <stdio.h>

#define MAX 100

int parent[MAX];

// Function to initialize each element as its own parent
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Find operation (with path compression)
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

// Union operation
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY) {
        parent[rootY] = rootX;
        printf("Union performed: %d and %d\n", x, y);
    } else {
        printf("%d and %d are already in the same set.\n", x, y);
    }
}

// Display parent array
void display(int n) {
    printf("\nElement : Parent\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t : %d\n", i, parent[i]);
    }
}

int main() {
    int n, choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    makeSet(n);

    do {
        printf("\n--- Disjoint Set Operations ---\n");
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Display Parent Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union: ");
                scanf("%d %d", &x, &y);

                if (x >= 0 && x < n && y >= 0 && y < n)
                    unionSets(x, y);
                else
                    printf("Invalid elements!\n");
                break;

            case 2:
                printf("Enter element to find its set: ");
                scanf("%d", &x);

                if (x >= 0 && x < n)
                    printf("Representative of %d is %d\n", x, find(x));
                else
                    printf("Invalid element!\n");
                break;

            case 3:
                display(n);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 4);

    return 0;
}