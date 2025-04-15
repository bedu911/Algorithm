#include <stdio.h>

// Function to take array elements from user
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

// Function to display array elements
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Binary search function (array must be sorted!)
void binarysearch(int a[], int n) {
    int key, isfound = -1;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);
    
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (a[mid] == key) {
            isfound = 1;
            break;
        } else if (a[mid] < key) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }

    if (isfound != -1) {
        printf("%d is found in the array\n", key);
    } else {
        printf("%d is not found in the array\n", key);
    }
}

int main() {
    int a[100], n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    input(a, n);
    printf("Array elements: ");
    display(a, n);

    // ❗ Binary Search requires a **sorted** array
    printf("NOTE: Make sure your array is sorted for binary search to work correctly.\n");

    binarysearch(a, n);
    return 0;
}
