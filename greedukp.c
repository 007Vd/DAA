#include<stdio.h>
void greedykp(int n,float weight[],float value[],float capacity){
    float ratio[20];
    float totalvalue=0;
    float remaining= capacity;
    
    for(int i=0;i<n;i++){
        ratio[i]=value[i]/weight[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ratio[i]<ratio[j]){
                float temp= ratio[i];
                ratio[i]=ratio[j];
                ratio[j]=temp;

                float temp1= weight[i];
                weight[i]= weight[j];
                weight[j]=temp1;

                float temp2= value[i];
                value[i]=value[j];
                value[j]= temp2;
            }
                }


    }
    for(int i=0;i<n;i++){
        if(weight[i]<=remaining){
            totalvalue=totalvalue+ value[i];
            remaining= remaining-weight[i];
        }
        else{
            totalvalue=totalvalue+ratio[i]*remaining;
            break;
        }

    }
    printf("max value attained : %f",totalvalue);

}
int main(){
    int n;
    printf("enter the number of items u want");
    scanf("%d",&n);
    float weight[20],value[20],capacity;
    printf("enter the weights");
    for(int i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }
     printf("enter the values");
    for(int i=0;i<n;i++){
        scanf("%f",&value[i]);
    }
    printf("enter capcity");
    scanf("%f",&capacity);

    greedykp(n,weight,value,capacity);

    
}