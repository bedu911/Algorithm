#include<stdio.h>
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
//Function To Sort Array By Using Selection Sort Algorithm
void selectionSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int indexofmin=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[indexofmin]){
                indexofmin=j;
            }
        }
        int temp=a[i];
        a[i]=a[indexofmin];
        a[indexofmin]=temp;
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
    selectionSort(a,n);
    display(a,n);
    return 0;
}