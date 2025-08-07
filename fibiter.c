
// Vijit Deogade 2024BMS028 FIBONACCI ITERATIVE

#include<stdio.h>
void fibiter(int a){
    int t1=0;
    int t2=1;
    int i=0;
    
    printf("%d\n",t1);
    printf("%d\n",t2);

    while(i<a-2){
        int newsum=0;
        newsum=t1+t2;
        printf("%d\n",newsum);
        t1=t2;
        t2=newsum;
        i++;


    }
}
int main(){
    fibiter(10);
}