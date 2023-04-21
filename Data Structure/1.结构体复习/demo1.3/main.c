#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char num[10];
    char name[20];
    int score;
}STU;
STU stu[4]={{"200901","Zhang",70},
{"200902","Wang",80},{"200903","Zhao",65},
{"200904","Zhou",95}};

int main()
{
    int i,j;
    STU t;
    printf("4个学生的信息是：\n");
    for(i=0;i<4;i++)
    {
        printf("%-8s%-12s%d\n",stu[i].num,stu[i].name,stu[i].score);
    }
    printf("按照成绩降序排序后的结果是：\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<=2-i;j++)
        {
            if (stu[j].score > stu[j+1].score)//相邻两个数如果逆序，则交换位置
			{
				t = stu[j];
				stu[j] = stu[j+1];
				stu[j + 1] = t;
			}
        }
    }
    for(i=0;i<4;i++)
    {
        printf("%-8s%-12s%d\n",stu[i].num,stu[i].name,stu[i].score);
    }
    printf("Hello world!\n");
    return 0;
}
