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
//Function To Merge Two Sorted Array 
void merge(int *a,int start,int end,int mid){
    int b[100];
    int i=start;
    int j=mid+1;
    int k=start;
    while(i<=mid && j<=end){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++,k++;
        }else
        {
            b[k]=a[j];
            k++,j++;
        }
    }
    while(i<=mid){
        b[k]=a[i];
        i++,k++;
    }
    while(j<=end){
        b[k]=a[i];
        i++,k++;
    }
    for(int i=start;i<=end;i++){
        a[i]=b[i];
    }
}
//Function To Sort Array By Using Merge Sort Algorithm
void mergeSort(int a[],int start,int end){
    if(start<end){
    int mid=(start+end)/2;
    mergeSort(a,start,mid);
    mergeSort(a,mid+1,end);
    merge(a,start,end,mid);
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
    mergeSort(a,0,n-1);
    display(a,n);
    return 0;
}