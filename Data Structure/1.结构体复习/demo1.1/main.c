#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int year;
    int month;
    int day;
}DATE;


int main()
{
    DATE x;
    int i,sum=0;
    int num[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("请输入年-月-日: ");
    scanf("%d-%d-%d\n",&x.year,&x.month,&x.day);
    if(x.year%4==0&&x.year%100!=0||x.year%400==00)
    {
        for(i=0;i<x.month-1;i++)
        {
            if(i==1)
            {
                sum=sum+29;
            }
            else
            {
                sum=sum+num[i];
            }
        }
        sum=sum+x.day;
        printf("%d-%d-%d是该年的第%d\n天",x.year,x.month,x.day,sum);
    }
    else
    {
        for(int i=0;i<x.month;i++)
        {
            sum=sum=num[i];
        }
        sum=sum+x.day;
        printf("%d年%d月%d日是该年的第%d\n天",x.year,x.month,x.day,sum);
    }
    return 0;
}
