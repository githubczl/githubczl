#include <stdio.h>
#include <stdlib.h>
#define MAX 10


typedef struct                   //顺序表存储结构
{
	int* elem;							 //动态分配空间的首地址，
	int length;							 //线性表当前长度
	int listsize;						 //线性表最大长度
}SqList;

int InitList(SqList *L);               				//构造空线性表L
int DestoryList(SqList* L);							//销毁线性表L
int ClearList(SqList* L);						//清空线性表L
int ListEmpty(SqList L);						//判断线性表是否为空
int Length(SqList L);								//求线性表元素个数
int GetElem(SqList L,int i, int *e);					//查找位序为i的元素，用e返回
int LocateElem(SqList L, int e);					//查找元素e,返回第一次出现的位序
int PriorElem(SqList L, int cur_e,int  *pre_e);     //用pre_e返回cur_e的前驱
int NextElem(SqList L,int  cur_e,int *next_e);			//用next_e返回cur_e的后继
int ListInsert(SqList* L,int i, int e);			 //将元素e插入的位置i;
int ListDelete(SqList* L,int i, int *e);			//删除位置i的元素，用e返回其值
int ListTraverse(SqList L);						 //遍历访问整个表L
int menu();											//菜单

int main()
{
	SqList L;
	int i, e, pre_e, next_e;                  //i存放位序，e存放元素值, pre_e存放e的前驱，next_e存放e的后继
	int option;
	menu();
	do
	{
		printf("\n输入选项:\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			InitList(&L);
			printf("初始化成功\n");
			break;
		case 2:
			DestoryList(&L);
			printf("销毁成功\n");
			break;
		case 3:
			ClearList(&L);
			printf("清空成功\n");
			break;
		case 4:
			if (ListEmpty(L))								  //返回值为1为空
				printf("线性表为空\n");
			else
				printf("线性表不为空\n");
			break;
		case 5:
			printf("线性表当前长度为%d\n", Length(L));
			break;
		case 6:
			printf("输入查找位序i\n");
			scanf("%d", &i);
			GetElem(L, i, &e);
			break;
		case 7:
			printf("输入要查找的元素e\n");
			scanf("%d", &e);
			LocateElem(L, e);
			break;
		case 8:
			printf("输入要查找的元素e\n");
			scanf("%d", &e);
			PriorElem(L, e, &pre_e);
			break;
		case 9:
			printf("输入要查找的元素e\n");
			scanf("%d", &e);
			NextElem(L, e, &next_e);
			break;
		case 10:
			printf("输入插入位序i和元素e\n");
			scanf("%d%d", &i, &e);
			if (i < 1 || i > L.length + 1)
			{
				printf("插入位序非法\n");
				break;
			}
			ListInsert(&L, i, e);
			break;
		case 11:
			printf("输入需要删除的位序i\n");
			scanf("%d", &i);
			if (i < 1 || i > L.length)
			{
				printf("删除位序非法\n");
				break;
			}
			e = ListDelete(&L, i, &e);
			printf("删除后\n");
			ListTraverse(L);
			printf("\n删除元素为%d\n", e);
			break;
		case 12:
			printf("遍历结果为：\n");
			ListTraverse(L); break;
		case 13: break;
		default:
			printf("输入选项不合法\n");
			break;
		}
	} while (option != 13);                                    //option==13退出
	return 0;
}
int InitList(SqList *L)									 //初始化操作
{
	L->elem = (int*)malloc(MAX * sizeof(int));				//动态分配内存
	if (!L->elem)
	{
		printf("动态分配内存失败\n");
		exit(0);
	}
	L->length = 0;								//初始化长度为0
	L->listsize = MAX;							//初始化大小为MAX
	return 0;
}

int DestoryList(SqList* L)				//销毁操作
{
	if (L->elem)
		free(L->elem);      //释放空间
	L->elem = NULL;         //指针指空
	return 0;
}

int ClearList(SqList* L)				 //清空操作
{
	L->length = 0;
	return 0;
}

int ListEmpty(SqList L)						//判断是否为空操作
{
	if (L.length == 0)
		return 1;
	else
		return 0;
}

int Length(SqList L)
{
	return L.length;
}

int GetElem(SqList L, int i, int* e)			//按位序查找操作
{
	if (i<1 || i>L.length)
	{
		printf("位置%d不合法\n", i);
		return 0;
	}
	else
	{
		printf("元素值为%d\n", L.elem[i - 1]);
		return *e = L.elem[i - 1];
	}
}

int LocateElem(SqList L,int e)					//按位置查找操作
{
	int i, flag=1;                               //flag标志，没找到为1
	for (i = 0; i < L.length; i++)
		if (L.elem[i] == e)
		{
			flag = 0;
			printf("所查元素位序为%d", i + 1);
			return i + 1;							//找到返回位置序号
		}
	if (flag)
		printf("查询无果");
	return 0;										//失败返回0
}

int PriorElem(SqList L, int cur_e, int* pre_e)					 //求前驱操作
{
	int i, k=-1;												  //k存放cur_e的前驱数组坐标，初始化值为-1
	for (i = 0; i < L.length; i++)
		if (L.elem[i] == cur_e)
		{
			k = i - 1;
			break;
		}
	if (k > -1)                                                         //有前驱
	{
		*pre_e = L.elem[k];
		printf("前驱元素为%d\n", *pre_e);
		return *pre_e;
	}
	else																//无前驱
	{
		printf("查询无果\n");
		return 0;
	}
}

int NextElem(SqList L,int cur_e, int *next_e)			//求后继操作
{
	int i, k=-1;											 //k存放cur_e的后继数组坐标,初始值为-1
	for(i=0;i<L.length;i++)
		if (L.elem[i] == cur_e)
		{
			k = i + 1;
			break;
		}
	if (k > 0 && k < L.length)                         //没有元素后继坐标为0，最后一个元素也没有后继
	{
		*next_e = L.elem[k];
		printf("后继元素为%d\n",*next_e);
		return *next_e;
	}
	else																//无后继
	{
		printf("查询无果\n");
		return 0;
	}
}

int ListInsert(SqList* L, int i, int e)           //插入操作
{
	if (i<1 || i>L->length+1)
	{
		printf("插入位置%d不合法\n", i);
		return 0;
	}
	if (L->length == L->listsize)				//顺序表已满
	{
		printf("顺序表已满,插入失败\n");
		return 0;
	}
	for (int k = L->length; k > i-1; k--)    //位置i和之后的元素全部后移
		L->elem[k] = L->elem[k - 1];
	L->elem[i - 1] = e;
	L->length++;								//当前长度加一
	return e;
}

int ListDelete(SqList* L, int i, int* e)          //删除操作
{
	if (i<1 || i>L->length)
	{
		printf("位置%d不合法\n", i);
		return 0;
	}
	*e = L->elem[i-1];
	for (int k = i - 1; k < L->length; k++)//位置i和之后的元素全部前移
		L->elem[k] = L->elem[k + 1];
	L->length--;                  //表长减1
	return *e;
}

int ListTraverse(SqList L)      //遍历所有元素
{
	if (ListEmpty(L))
	{
		printf("顺序表为空\n");
		return 0;
	}
	for (int i = 0; i < L.length; i++)
		printf("%-5d", L.elem[i]);
	return 0;
}

int menu()
{
	printf("\n\n\n******************************菜单***************************************\n");
	printf("****************************************************************************************\n");
	printf("1、	初始化InitList(*L),					2、销毁DestoryList(*L)\n");
	printf("3、	清空ClearList(*L) ,					4、判表空ListEmpty(L)\n");
	printf("5、	求表长Length(L),					6、按位查找GetElem(L,i,*e)\n");
	printf("7、	按值查找LocateElem(L,e),					8、求前驱PriorElem(L, cur_e,*pre_e)\n");
	printf("9、	求后继NextElem(L,cur_e,*next_e),					10、插入ListInsert(*L, i, e)\n");
	printf("11、 删除ListDelete(*L, i,*e),					12、遍历（输出）ListTraverse(L)*\n");
	printf("13、 退出\n");
	return 0;
}


