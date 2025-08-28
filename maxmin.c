#include<stdio.h>
#include<stdlib.h>
int gmin=0,gmax=0;
void minmax(int arr[],int low,int high){
    if(low==high){
        if(arr[low]<gmin) gmin=arr[low];
        if(arr[low]>gmax) gmax=arr[low];
        return;  }
    if(high==low+1){
        if(arr[low]<gmin) gmin=arr[low];
        if(arr[high]<gmin) gmin=arr[high];

        if(arr[low]>gmax) gmax=arr[low];
        if(arr[high]>gmax) gmax=arr[high];
        return;
    
    }
    int mid=(low+high)/2;
    minmax(arr,low,mid);
    minmax(arr,mid+1,high);

}
int main(){
    int arr[] = {3, 5, -1, 8, 2, 10, 4};
    gmin=gmax=arr[0];
    minmax(arr,0,6);
    printf("min = %d\n",gmin);
    printf("max= %d\n",gmax);
}
