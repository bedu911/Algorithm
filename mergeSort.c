#include <stdio.h>

// Function To Take Array Elements From user
void input(int a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
}

// Function To Display Array Elements 
void display(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Function To Merge Two Sorted Subarrays
void merge(int *a, int start, int end, int mid) {
    int b[100]; // Temporary array
    int i = start;
    int j = mid + 1;
    int k = start;

    // Merge the two halves into b[]
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) {
        b[k++] = a[i++];
    }

    // Copy remaining elements from the right half
    while (j <= end) {
        b[k++] = a[j++];
    }

    // Copy sorted elements back into original array
    for (int i = start; i <= end; i++) {
        a[i] = b[i];
    }
}

// Function To Sort Array By Using Merge Sort Algorithm
void mergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);      // Sort left half
        mergeSort(a, mid + 1, end);    // Sort right half
        merge(a, start, end, mid);     // Merge the two halves
    }
}

int main() {
    int a[100], n; // Declaration of Array and Size of Array
    printf("Enter the Size of Array: ");
    scanf("%d", &n);
    
    printf("Enter %d elements:\n", n);
    input(a, n);

    printf("Unsorted Array: ");
    display(a, n);

    mergeSort(a, 0, n - 1);

    printf("Sorted Array: ");
    display(a, n);

    return 0;
}
