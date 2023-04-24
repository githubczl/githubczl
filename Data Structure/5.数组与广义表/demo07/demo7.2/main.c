#include<stdio.h>
#include<stdlib.h>
#define number 10
typedef int elemtype;
typedef struct Triple
{
    int i,j,data;

}Triple;

typedef struct
{
    Triple data[number];
    int rpos[number];
    int n,m,num;
}TSMatrix;

TSMatrix transposeMatrix(TSMatrix M,TSMatrix T)
{
    T.m=M.n;
    T.n=M.m;
    T.num = M.num;
    if(T.num)
    {
        int q=0;
        for(int col=1;col<=M.m;col++)
        {
            for(int p=0;p<M.num;p++)
            {
                if(M.data[p].j==col)
                {
                    T.data[q].i=M.data[p].j;
                    T.data[q].j=M.data[p].i;
                    T.data[q].data=M.data[p].data;
                    q++;
                }
            }
        }
    }
    return T;
}

TSMatrix fastTransposeMatrix(TSMatrix M, TSMatrix T)
{
    T.n=M.m;
    T.m=M.n;
    T.num = M.num;
    if(T.num)
    {
        int array[number];
        for(int col=1;col<=M.m;col++)
        {
            array[col]=0;

        }
        for(int t=0;t<M.num;t++)
        {
            int j=M.data[t].j;
            array[j]++;
        }
        int cpot[T.m+1];
        cpot[1]=1;
        for(int col=2;col<=M.m;col++)
        {
            cpot[col]=cpot[col-1]+array[col-1];
        }
        for(int p=0;p<M.num;p++)
        {
            int col = M.data[p].j;
            int q = cpot[col];
            T.data[q-1].i=M.data[p].j;
            T.data[q-1].j=M.data[p].i;
            T.data[q-1].data=M.data[p].data;
            cpot[col]++;
        }
    }
    return T;
}

int main()
{
     TSMatrix M;
     TSMatrix T;
     M.m=2;
     M.n=3;
     M.num =4;
     M.data[0].i=1;
     M.data[0].i=2;
     M.data[0].data=1;
     M.data[1].i=2;
     M.data[1].i=2;
     M.data[1].data=3;
     M.data[2].i=3;
     M.data[2].i=1;
     M.data[2].data=6;
     M.data[3].i=3;
     M.data[3].i=2;
     M.data[3].data=5;
     T=transposeMatrix(M,T);
     printf("使用普通方法");
     for(int i=0;i<T.num;i++)
     {
         printf("(%d,%d,%d)", T.data[i].i, T.data[i].j, T.data[i].data);
     }
     printf("\n");
     TSMatrix T1;
     T1=fastTransposeMatrix(M,T);
     printf("使用快速方法");
     for(int i=0;i<T.num;i++)
     {
         printf("(%d,%d,%d)", T.data[i].i, T.data[i].j, T.data[i].data);
     }
     return 0;



}
