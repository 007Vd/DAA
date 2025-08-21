#include <stdio.h>
#include<stdlib.h>
void adder(int n, int a[n][n], int b[n][n], int c[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void subtracter(int n, int a[n][n], int b[n][n], int c[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] - b[i][j];
        }
    }
}
void mat(int k,int a[k][k],int b[k][k]){
      for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                a[i][j]=0;
                b[i][j]=0;
            }
        }

}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    // printf("intitialized");
    if (n == 2)
    {
        int a = A[0][0], b = A[0][1], c = A[1][0], d = A[1][1];
        int e = B[0][0], f = B[0][1], g = B[1][0], h = B[1][1];
        int m1 = (a + d) * (e + h), m2 = (c + d) * e, m3 = a * (f - h), m4 = d * (g - e), m5 = (a + b) * h, m6 = (c - a) * (e + f), m7 = (b - d) * (g + h);
        C[0][0] = m1 + m4 + m7 - m5;
        C[0][1] = m3 + m5;
        C[1][0] = m2 + m4;
        C[1][1] = m1 - m2 + m3 + m6;
    return;}

   else{
        int k = n / 2;
        int A00[k][k], A01[k][k], A10[k][k], A11[k][k], B00[k][k], B01[k][k], B10[k][k], B11[k][k],
            C00[k][k], C01[k][k], C10[k][k], C11[k][k], T1[k][k], T2[k][k], m1[k][k], m2[k][k], m3[k][k], m4[k][k], m5[k][k], m6[k][k], m7[k][k];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                A00[i][j] = A[i][j];
                A01[i][j] = A[i][j + k];
                A10[i][j] = A[i + k][j];
                A11[i][j] = A[i + k][j + k];
                B00[i][j] = B[i][j];
                B01[i][j] = B[i][j + k];
                B10[i][j] = B[i + k][j];
                B11[i][j] = B[i + k][j + k];
            }
        }
      mat(k,T1,T2);
        adder(k, A00, A11, T1);
        adder(k, B00, B11, T2);
        strassen(k, T1, T2, m1);
        mat(k,T1,T2);
        adder(k, A10, A11, T1);
        strassen(k, T1, B00, m2);mat(k,T1,T2);
        subtracter(k, B01, B11, T1);
        strassen(k, A00, T1, m3);mat(k,T1,T2);
        subtracter(k, B10, B00, T2);
        strassen(k, A11, T2, m4);mat(k,T1,T2);
        adder(k, A00, A01, T1);
        strassen(k, T1, B11, m5);mat(k,T1,T2);
        subtracter(k, A10, A00, T1);
        adder(k, B00, B01, T2);
        strassen(k, T1, T2, m6);mat(k,T1,T2);
        subtracter(k, A01, A11, T1);
        adder(k, B10, B11, T2);
        strassen(k, T1, T2, m7);mat(k,T1,T2);

               
        adder(k, m1, m4, T1);
        subtracter(k, T1, m5, T2);
        adder(k, T2, m7, C00);

     
        adder(k, m3, m5, C01);

       
        adder(k, m2, m4, C10);

        
        subtracter(k, m1, m2, T1);
        adder(k, T1, m3, T2);
        adder(k, T2, m6, C11);


        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                C[i][j]=C00[i][j];
                C[i][j+k]=C01[i][j];
                C[i+k][j]=C10[i][j];
                C[i+k][j+k]=C11[i][j];
            }
        }
        }
    }

int main()
{
    int n;
    printf("enter number n*n");
    scanf("%d",&n);
    // int A[n][n], B[n][n], 
    int C[n][n];
    int A[n][n];
     for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        A[i][j]=rand()%100;
    }
 }
//  printf("a");
//   for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             printf("%d ", A[i][j]);
//         }
//         printf("\n");
//     }
//= {
//     {1, 2, 4, 5},
//     {3, 4, 6, 7},
//     {2, 3, 1, 4},
//     {5, 6, 5, 9}
// };

 int B[n][n];
 for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        B[i][j]=rand()%100;
    }
 } //= {
//     {1, 2, 4, 5},
//     {3, 4, 6, 7},
//     {2, 3, 1, 4},
//     {5, 6, 5, 9}
// };

    strassen(n, A, B, C);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
