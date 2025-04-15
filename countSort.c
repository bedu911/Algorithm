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
//Function To Find Maximum Elements in The Array
int maximum(int a[],int n){
    int max=a[0];
    for(int i=1;i<n;i++){
        if(a[i]>max){
            max=a[i];
        }
    }
    return max;
}
//Function To Sort Array By Using count Sort Algorithm
void countSort(int a[],int n){
    int max=maximum(a,n);
    int *countarray=(int *)malloc((max+1)*sizeof(int));
    int b[n];
    for(int i=0;i<max+1;i++){//Initialising All Elements to 0
        countarray[i]=0;
    }
    for(int i=0;i<n;i++){//Frequency if Each Element
        countarray[a[i]]=countarray[a[i]]+1;
    }
    for(int i=1;i<max+1;i++){//Update Actual Position
        countarray[i]=countarray[i]+countarray[i-1];
    }
    for(int i=n-1;i>=0;i--){//Place the Elements to it's Place
        b[--countarray[a[i]]]=a[i];
    }
    for(int i=0;i<n;i++){//Copy to Original Array
        a[i]=b[i];
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
    countSort(a,n);
    display(a,n);
    return 0;
}