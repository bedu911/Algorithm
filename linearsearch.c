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
void linearsearch(int a[],int n){
    int key,isfound=-1;
    printf("Enter the key To be Search:");
    scanf("%d",&key);
    for(int i=0;i<n;i++){
        if(a[i]==key){
            isfound=i;
            break;
        }
    }
    if(isfound!=-1){
        printf("%d is Found in Array\n",key);
    }else{
               printf("%d is Not Found in Array\n",key);
    }
}
int main(){
    int a[100],n;//Declaration of Array and Size of Array size
    printf("Enter the Size of Array: ");
    scanf("%d",&n);
    input(a,n);
    printf("Array Elements ");
    display(a,n);
    linearsearch(a,n);
    return 0;
}