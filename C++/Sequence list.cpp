#include <iostream>
#include <iomanip>

using namespace std;
/*
	函数定义：

	*InitList(*L):初始化操作，建立一个空的线性表L。
	*IsNull(L):判断链表是否存在
	*ListEmpty(L)：判断线性表是否为空表，若线性表为空，返回true，否则返回false。
	*ClearList(*L)：将线性表清空。
	*GetElem(L,i,&e)：将线性表L中的第i个位置元素值返回给e。
	*LocationElem(L,e)：在线性表中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则，返回0表示失败。
	*ListInsert(*L,i,e)：在线性表L中第i个位置插入新元素e。
	*ListDelete(*L,i*e):删除线性表L中第i个位置元素，并用e返回其值。
	*ListLength(L)：返回线性表L的元素个数。

*/

typedef int ElemType; //宏定义链表的data
typedef int Status;	  //宏定义函数的返回值
//宏定义链表的最大个数
#define MAXSIZE 100
//宏定义返回值Status的类型，OK（1）表示执行成功，ERROR(0)表示执行失败或出错，用于主函数的判断
#define OK 1
#define ERROR 0
/*
	注意因为这里用的data用的时int类型的，所以不用单独定义结构体类型的结构体
*/
typedef struct
{					//定于结构体类型的链表
	ElemType* data; //int类型的指针，用于操作数组
	int length;		//链表的长度
} List;

/*
	创建一个空链表
		成功返回OK
		失败返回ERROR
*/
Status InitList(List* L)
{
	//在内存中申请一块空间，并返回这块空间的地址
	L->data=new ElemType[MAXSIZE];
	L->length=0;
	if(!L) //判断链表现在是否为空
	{
		//链表申请失败
		cout<<"申请内存失败"<<endl;
		return ERROR;
	}
	else
	{
		//链表申请成功
		cout<<"创建成功，可以向链表中添加数据了。"<<endl;
		return OK;
	}
}
/*
	判断链表是否存在
		存在返回OK
		不存在返回ERROR
	并打印提示信息
*/
Status IsNull(List L)
{
	List* p=&L; //将传入的参数变量的地址复制给指针p
	if(p)
	{
		//链表不为空
		return OK;
	}
	else
	{
		//链表为空
		cout<<"链表为空，请先创建链表"<<endl;
		return ERROR;
	}
}
/*
	判断链表是否为空
		为空返回ERROR
		不为空返回OK
*/
Status ListEmpty(List& L)
{
	if(IsNull(L))
	{
		//返回OK说明链表存在
		//对链表进行判断
		if(L.length==0)
		{
			//为空
			return ERROR;
		}
		else
		{
			//不为空
			return OK;
		}
	}
	else
	{
		//返回ERROR说明链表不存在，判断链表是否为空就没必要了,直接返回
		return ERROR;
	}
}
/*
	清空顺序表中数据（前提：链表L确定存在）
		清理成功返回OK
		清理不失败返回ERROR
*/
void ClearList(List& L)
{
	//清空就是将顺序表中现有的数据进行清零
	int i;
	for(i=0; i<L.length; i++)
	{
		L.data[i]=0;
	}
}
/*
	向顺序表中添加部分数据用于测试
*/
void AddDatas(List& L)
{
	for(int i=0; i<10; i++)
	{
		L.data[i]=i+1;
		L.length++;
	}
}
/*
	遍历链表（仅用于测试）
*/
void ShowDatas(List& L)
{
	for(int i=0; i<L.length; i++)
	{
		cout<<L.data[i]<<endl;
	}
}

//GetElem(L,i,*e)：将线性表L中的第i个位置元素值返回给e。

void GetElem(List L,int i,ElemType& e)
{
	if(i>L.length)
	{
		cout<<"您输入的位置有误"<<endl;
		return;
	}
	e=L.data[i-1];
}
//LocationElem(L,e)：在线性表中查找与给定值e相等的元素，如果查找成功，返回该元素在表中序号表示成功；否则，返回0表示失败。
int LocationElem(List L,ElemType e)
{
	int i=0;
	for(i=0; i<L.length; i++)
	{
		if(L.data[i]==e)
		{
			return ++i;
		}
	}
	return 0;
}
//ListInsert(*L,i,e)：在线性表L中第i个位置插入新元素e。
Status ListInsert(List& L,int i,ElemType e)
{
	//判断用户输入的位置是否错误
	if(i>L.length+1&&i<1)
	{
		cout<<"您输入的位置有误"<<endl;
		return ERROR;
	}
	//判断插入的位置是否在顺序表的末尾
	if(i<=L.length)
	{
		int j;
		for(j=L.length; j>=i; j--)
		{
			//将要插入元素的后面的元素全部向后移
			L.data[j]=L.data[j-1];
		}
	}
	//无论插入前面或者末尾，都执行
	L.data[i-1]=e;
	L.length++;
	return OK;
}

// ListDelete(*L,i*e):删除线性表L中第i个位置元素，并用e返回其值。
Status ListDelete(List& L,int i,ElemType& e)
{
	//判断用户输入的位置是否有误
	if(i>=L.length&&i<1)
	{
		cout<<"您输入的有误"<<endl;
		return ERROR;
	}
	//判断删除的位置是否在顺序表的末尾
	if(i<=L.length)
	{
		//将删除元素的位置后面的所有元素往前移一位
		e=L.data[i-1];
		int j;
		for(j=i-1; j<L.length-1; j++)
		{
			//将后一位元素的值赋值给前一个元素，达到覆盖的效果
			L.data[j]=L.data[j+1];
		}
	}
	//无论删除哪一个，都要执行的语句
	L.length--;
	return OK;
}

// ListLength(L)：返回线性表L的元素个数。
int ListLength(List L)
{
	return L.length;
}
/*
	主函数：用于调用各个函数，通过函数功能的拼接实现需求
			并且用于测试
*/
int main()
{

	List list; //声明一个链表变量
	system("color 02");
	//判断list变量的类型和字节
	//int size=sizeof(list);
	//cout<<size<<endl;
	if(InitList(&list))
	{
		//判断链表是否为空
		if(!ListEmpty(list))
		{
			AddDatas(list);
			List* p=&list;
			//ShowDatas(list);
			/*	//调用清空函数
			ClearList(list);
			//展示链表清空后的数据
			ShowDatas(list);
			*/
			//返回顺序表中的第5个元素
			ElemType e;
			GetElem(list,5,e);
			//cout<<e<<endl;
			//调用LocationElem（）函数
			int a;
			a=LocationElem(list,2);
			if(a)
			{
				//cout<<a<<endl;
				ListDelete(list,1,a);
				cout<<"删除的元素为："<<a<<endl;
				ShowDatas(list);
				cout<<"链表的个数为:"<<ListLength(list)<<endl;
			}
			else
			{
				cout<<"未找到"<<endl;
			}
			cout<<"测试成功"<<endl;
		}
	}
	else
	{
		cout<<"测试失败"<<endl;
	}
	return 0;
}
