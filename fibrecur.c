// Vijit Deogade 2024BMS028 FIBONACCI RECURSIVE

#include<stdio.h>
int fibrecur(int a){
    if(a==1) return 0;
    if(a==2) return 1;
    else{
        
        return fibrecur(a-1)+fibrecur(a-2);
        }
}
int main(){
    // int a=10;
    // for(int i=1;i<a+1;i++){
    //     printf("%d\n",fibrecur(i));
    // }
         printf("%d\n",fibrecur(4));

}