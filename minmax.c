#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int global_min;
int global_max;

void minmaxhelper(int arr[], int i,int j){
    if(i==j){
        if(arr[i]<global_min) global_min=arr[i];
        if(arr[i]>global_max) global_max=arr[i];
        return;
    
    }
    if(j==i+1){
        if(arr[i]<global_min) global_min=arr[i];
        if(arr[j]<global_min) global_min=arr[j];

        if(arr[i]>global_max) global_max=arr[i];        
        if(arr[j]>global_max) global_max=arr[j];
        return;
    }
    int mid=(i+j)/2;

    minmaxhelper(arr,i,mid);
    minmaxhelper(arr,mid+1,j);
}
void printer(int n, int arr[n]){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    
    clock_t start, end;
    double cpu_time_used;
     
         
    
    int n;
    printf("enter number of elements");
    scanf("%d",&n);
    int arr[n];
    start = clock();
    for(int i=0;i<n;i++){
        arr[i]=rand()%(500-100+1)+100;

    }
    global_min=global_max=arr[0];
    
    printf("input arr\n");
    printer(n,arr);

    minmaxhelper(arr,0,n-1);
    printf("minimum= %d\n",global_min);
    printf("maximum= %d\n",global_max);
     for (long i = 0; i < 100000000; i++);

    end = clock();    

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);





}