#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *i,int *j){
    int temp=*i;
    *i=*j;
    *j=temp;
}
int partition(int arr[],int l,int h){
    int p=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++){
        if(arr[j]<=p){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[h]);
    return i+1;

}
int quickselect(int arr[],int l,int h,int k){
    if(l<=h){
        int pindex=partition(arr,l,h);
        if(pindex==k-1){
            return arr[pindex];
        }
        else if( pindex>k-1){
            return quickselect(arr,l,pindex-1,k);
        }
        else{
            return quickselect(arr,pindex+1,h,k);
        }
    }
return -1;
}

int main(){
    int n;
    printf("enter arr size");
    scanf("%d",&n);
    int arr[n];
    srand(time(NULL));


    for(int i=0;i<n;i++){
        arr[i]=rand()%(n+1);

    }
    printf("generated arr:");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    clock_t start=clock();
    printf(" 5th smallest%d\n",quickselect(arr,0,n-1,5));
    printf("10th smallest%d\n",quickselect(arr,0,n-1,10));
    printf("15th smallest %d\n",quickselect(arr,0,n-1,15));


    clock_t end=clock();
    double t_t= ((double)(end-start))/CLOCKS_PER_SEC;
    printf("Time taken %f",t_t);
    
}