#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    char num[10];
    char name[20];
    int score[2];
    float aver;
}STU;
STU stu[3]={{"200901","zhang",{70,75}},{"200902","wang",
{80,85}},{"200903","zhao",{60,65}}};
int main()
{
    int i,max;
    printf("三个学生的信息:\n学号    姓名   成绩\n");
    for(i=0;i<3;i++)
    {
        printf("%-8s%-12s%d %d\n",stu[i].num,stu[i].name,stu[i].score[0],stu[i].score[1]);
    }
    printf("三个学生的平均成绩是：\n");
    for(i=0;i<3;i++)
    {
        stu[i].aver=(stu[i].score[0]+stu[i].score[1])/2;
        printf("第%d个学生的平均分为：%f\n",i,stu[i].aver);
    }
    for(i=0;i<3;i++)
    {
        max=stu[0].aver;
        if(max<stu[i].aver)
        {
            max=stu[i].aver;
        }

    }
    printf("平均分最高的学生为：%d\n",max);
    return 0;
}
