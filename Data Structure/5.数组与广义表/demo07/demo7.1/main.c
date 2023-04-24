#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 12500
//存储三元组的结构体
typedef struct {
    int i,j;
    int data;
}Triple;
//存储稀疏矩阵的结构体
typedef struct {
    Triple data[MAXSIZE +1];
    int mu,nu,tu;
}TSMatrix;

void display1(TSMatrix M) {
    int i, j, k;
    for (i = 1; i <= M.mu; i++) {
        for (j = 1; j <= M.nu; j++) {
            int value = 0;
            for (k = 0; k < M.tu; k++) {
                if (i == M.data[k].i && j == M.data[k].j) {
                    printf("%d\t", M.data[k].data);
                    value = 1;
                    break;
                }
            }
            if (value == 0)
                printf("0\t");
        }
        printf("\n");
    }
}

void TransposeSMatrix(TSMatrix M, TSMatrix T)
{
     int q,p,col;
     T.mu=M.mu; T.nu=M.nu; T.tu=M.tu;
    if(T.tu){
        q = 1;
        for(col = 1;col<=M.nu ; ++col)
            for(p = 1;p<=M.tu; ++p)
                if(M.data[p].j ==col){
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].data = M.data[p].data;
                    ++q;
                }
    }
    return 1;
}//TransposeSMatrix

void FastTransposeSMatix(TSMatrix M, TSMatrix T)
{
     T.mu=M.mu; T.nu=M.nu; T.tu=M.tu;
     int col,t,p,q;
     int num[100],cpot[100];
     if(T.tu){
        for(col = 1;col<=M.nu ; ++col)
            num[col] = 0;
        for(t = 1; t<M.nu ; ++t)
            ++num[M.data[t].j];
        cpot[1]=1;
        for(col = 2;col<=M.nu; ++col)
            cpot[col] = cpot[col -1] + num[col - 1];
        for(p = 1;p<=M.tu;++p){
            col = M.data[p].j; q=cpot[col];
            T.data[q].i = M.data[p].j;
            T.data[q].j = M.data[p].i;
            T.data[q].data = M.data[p].data;
            ++cpot[col];
        }
     }
     return 1;
}

int main()
{
    TSMatrix M;
    TSMatrix T;
    M.mu = 7;
    M.nu = 8;
    M.tu = 9;




    M.data[0].i =1;
    M.data[0].j =2;
    M.data[0].data =12;

    M.data[1].i =1;
    M.data[1].j =3;
    M.data[1].data =9;

    M.data[2].i =3;
    M.data[2].j =1;
    M.data[2].data =-3;

    M.data[3].i =3;
    M.data[3].j =8;
    M.data[3].data =4;

    M.data[4].i =4;
    M.data[4].j =3;
    M.data[4].data =24;

    M.data[5].i =4;
    M.data[5].j =6;
    M.data[5].data =2;

    M.data[6].i =5;
    M.data[6].j =2;
    M.data[6].data =18;

    M.data[7].i =6;
    M.data[7].j =7;
    M.data[7].data =-7;

    M.data[8].i =7;
    M.data[8].j =4;
    M.data[8].data =-6;

    display1(M);
    TransposeSMatrix(M,T);
    printf("Hello world!\n");
    return 0;
}

