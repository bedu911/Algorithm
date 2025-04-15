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
//Function To Sort Array By Using Bubble Sort Algorithm
void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){ //Loops For Each Pass
        for(int j=0;j<n-1-i;j++){//Loops  For Each Comparision
            if(a[j]>a[j+1]){//Condition To detect Wrong Order if yes,then swap
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
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
    bubbleSort(a,n);
    display(a,n);
    return 0;
}