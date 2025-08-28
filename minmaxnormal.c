#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int global_min,global_max;

void minhelper(int n,int arr[n]){
    global_min=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]<global_min)
        {
            global_min=arr[i];
            
        }
        
    }
}

void maxhelper(int n,int arr[n]){
    global_max=arr[0];
    for(int i=0;i<n;i++){
        if(arr[i]>global_max)
        {
            global_max=arr[i];
            
        }
        
    }
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
     start = clock();
         

   
    
    int n=10;
    printf("enter number of elements");
    scanf("%d",&n);
    int arr[n];

    for(int i=0;i<n;i++){
        // arr[i]=rand()%100;
          arr[i]=rand()%(500-100+1)+100;
    }
    printf("input matrix\n");

    printer(n,arr);

    minhelper(n,arr);
    maxhelper(n,arr);

    printf("minimum= %d\n",global_min);
    printf("maximum= %d\n",global_max);
    for (long i = 0; i < 100000000; i++);

    end = clock();    

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Time taken: %f seconds\n", cpu_time_used);
    
}