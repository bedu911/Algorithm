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
/* Function To Divide The Array Such ELement Left To Pivot is Lesser thanPivot and Elements Right To Pivot is Greater Than Pivot */
int partition(int a[],int start,int end){
    int pivot=a[start];
    int i=start+1;
    int j=end;
    int temp;
    do{
       while(a[i]<=pivot){
           i++;
       } 
       while(a[j]>pivot){
           j--;
       }
       if(i<j){
           temp=a[i];
           a[i]=a[j];
           a[j]=a[i];
       }
    }while(i<j);
    temp=a[start];
    a[start]=a[j];
    a[j]=temp;
    return j;
}
//Function To Sort Array By Using Quick Sort Algorithm
void quickSort(int a[],int start,int end){
    int indexofpivot;
    if(start<end){
        indexofpivot=partition(a,start,end);
        quickSort(a,start,indexofpivot-1);//Recursive Call for LeftSubArray
        quickSort(a,indexofpivot+1,end);//Recursive Call for RightSubArray
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
    quickSort(a,0,n-1);
    display(a,n);
    return 0;
}