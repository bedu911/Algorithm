#include <stdio.h>

// Function To Take Array Elements From User
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

// Function To Partition the Array (Lomuto Partition Scheme)
int partition(int a[], int start, int end) {
    int pivot = a[start];
    int i = start + 1;
    int j = end;
    int temp;

    do {
        while (i <= end && a[i] <= pivot) {
            i++;
        }
        while (a[j] > pivot) {
            j--;
        }
        if (i < j) {
            // Swap a[i] and a[j]
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    } while (i < j);

    // Swap pivot with a[j]
    temp = a[start];
    a[start] = a[j];
    a[j] = temp;

    return j; // Returning pivot index
}

// Function To Sort Array Using Quick Sort Algorithm
void quickSort(int a[], int start, int end) {
    if (start < end) {
        int indexofpivot = partition(a, start, end);
        quickSort(a, start, indexofpivot - 1);   // Recursive call for left subarray
        quickSort(a, indexofpivot + 1, end);     // Recursive call for right subarray
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

    quickSort(a, 0, n - 1);

    printf("Sorted Array: ");
    display(a, n);

    return 0;
}
