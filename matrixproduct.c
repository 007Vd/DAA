#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
 
int reqfun(int p[],int n){
    int m[n+1][n+1];
    for(int i=1;i<=n;i++){
        m[i][i]=0;
     }
     for(int l=2;l<=n-1;l++){
        for(int i=1;i<=n-l;i++){
            int j=i+l-1;
            m[i][j]=INT_MAX;
            
            for(int k=i;k<=j-1;k++){
                int c=m[i][k]+m[k+1][j] +(p[i-1]*p[k]*p[j]);
                if(c<m[i][j]){
                    m[i][j]=c;

                }
               }
        }
    }
return m[1][n-1];
}
int main(){
    int n;
    printf("enter the number of matrices");
    scanf("%d",&n);

    printf("enter n+1 dimesnions\n");
    int p[n+1];
    for(int i=0;i<=n;i++){
        // p[i]= rand()% 50 +5;
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d X %d ,",p[i],p[i+1]);
    }
    printf("\n");
    int mincost=reqfun(p,n+1);
    printf("%d is the minimum no of multiplications \n",mincost);
    printf("%dX%d is the dimension of the matrix",p[0],p[n]);
}
