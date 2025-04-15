#include<stdio.h>
#include<stdlib.h>
//Function To Take Array Elements From user
void input(int a[],int n){
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
}
//Function To Display Array ELements 
void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
//Function To Find Max Elements in Array
int maximum(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
//Count Sort For Each Digits (once ,Tens,,)of Each Elements
void countSort(int a[], int n, int exp) {
    int countarray[10] = {0}; // For digits 0–9
    int *b = (int *)malloc(n * sizeof(int));

    // Count the frequency of each digit at current position
    for(int i = 0; i < n; i++) {
        int digit = (a[i] / exp) % 10;
        countarray[digit]++;
    }

    // Convert to cumulative count
    for(int i = 1; i < 10; i++) {
        countarray[i] += countarray[i - 1];
    }

    // Build the output array (traverse from end to make it stable)
    for(int i = n - 1; i >= 0; i--) {
        int digit = (a[i] / exp) % 10;
        b[--countarray[digit]] = a[i];
    }

    // Copy back to original array
    for(int i = 0; i < n; i++) {
        a[i] = b[i];
    }

    free(b); // Always free dynamically allocated memory
}

void radixSort(int a[],int n){
    int exp;
    int max=maximum(a,n);
    for(int exp=1;(max/exp)>0;exp=exp*10){
        countSort(a,n,exp);
    }
}
int main(){
    int a[100],n;//Declaration of Array and Size of Array size
    printf("Enter the Size of Array: ");
    scanf("%d",&n);
    input(a,n);
    printf("Unsorted Array ");
    display(a,n);
    printf("Sorted Array ");
    radixSort(a,n);
    display(a,n);
    return 0;
}