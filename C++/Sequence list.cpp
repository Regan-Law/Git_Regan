#include <iostream>
#include <iomanip>

using namespace std;
/*
	�������壺

	*InitList(*L):��ʼ������������һ���յ����Ա�L��
	*IsNull(L):�ж������Ƿ����
	*ListEmpty(L)���ж����Ա��Ƿ�Ϊ�ձ������Ա�Ϊ�գ�����true�����򷵻�false��
	*ClearList(*L)�������Ա���ա�
	*GetElem(L,i,&e)�������Ա�L�еĵ�i��λ��Ԫ��ֵ���ظ�e��
	*LocationElem(L,e)�������Ա��в��������ֵe��ȵ�Ԫ�أ�������ҳɹ������ظ�Ԫ���ڱ�����ű�ʾ�ɹ������򣬷���0��ʾʧ�ܡ�
	*ListInsert(*L,i,e)�������Ա�L�е�i��λ�ò�����Ԫ��e��
	*ListDelete(*L,i*e):ɾ�����Ա�L�е�i��λ��Ԫ�أ�����e������ֵ��
	*ListLength(L)���������Ա�L��Ԫ�ظ�����

*/

typedef int ElemType; //�궨�������data
typedef int Status;	  //�궨�庯���ķ���ֵ
//�궨�������������
#define MAXSIZE 100
//�궨�巵��ֵStatus�����ͣ�OK��1����ʾִ�гɹ���ERROR(0)��ʾִ��ʧ�ܻ�����������������ж�
#define OK 1
#define ERROR 0
/*
	ע����Ϊ�����õ�data�õ�ʱint���͵ģ����Բ��õ�������ṹ�����͵Ľṹ��
*/
typedef struct
{					//���ڽṹ�����͵�����
	ElemType* data; //int���͵�ָ�룬���ڲ�������
	int length;		//����ĳ���
} List;

/*
	����һ��������
		�ɹ�����OK
		ʧ�ܷ���ERROR
*/
Status InitList(List* L)
{
	//���ڴ�������һ��ռ䣬���������ռ�ĵ�ַ
	L->data=new ElemType[MAXSIZE];
	L->length=0;
	if(!L) //�ж����������Ƿ�Ϊ��
	{
		//��������ʧ��
		cout<<"�����ڴ�ʧ��"<<endl;
		return ERROR;
	}
	else
	{
		//��������ɹ�
		cout<<"�����ɹ�����������������������ˡ�"<<endl;
		return OK;
	}
}
/*
	�ж������Ƿ����
		���ڷ���OK
		�����ڷ���ERROR
	����ӡ��ʾ��Ϣ
*/
Status IsNull(List L)
{
	List* p=&L; //������Ĳ��������ĵ�ַ���Ƹ�ָ��p
	if(p)
	{
		//����Ϊ��
		return OK;
	}
	else
	{
		//����Ϊ��
		cout<<"����Ϊ�գ����ȴ�������"<<endl;
		return ERROR;
	}
}
/*
	�ж������Ƿ�Ϊ��
		Ϊ�շ���ERROR
		��Ϊ�շ���OK
*/
Status ListEmpty(List& L)
{
	if(IsNull(L))
	{
		//����OK˵���������
		//����������ж�
		if(L.length==0)
		{
			//Ϊ��
			return ERROR;
		}
		else
		{
			//��Ϊ��
			return OK;
		}
	}
	else
	{
		//����ERROR˵���������ڣ��ж������Ƿ�Ϊ�վ�û��Ҫ��,ֱ�ӷ���
		return ERROR;
	}
}
/*
	���˳��������ݣ�ǰ�᣺����Lȷ�����ڣ�
		����ɹ�����OK
		����ʧ�ܷ���ERROR
*/
void ClearList(List& L)
{
	//��վ��ǽ�˳��������е����ݽ�������
	int i;
	for(i=0; i<L.length; i++)
	{
		L.data[i]=0;
	}
}
/*
	��˳�������Ӳ����������ڲ���
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
	�������������ڲ��ԣ�
*/
void ShowDatas(List& L)
{
	for(int i=0; i<L.length; i++)
	{
		cout<<L.data[i]<<endl;
	}
}

//GetElem(L,i,*e)�������Ա�L�еĵ�i��λ��Ԫ��ֵ���ظ�e��

void GetElem(List L,int i,ElemType& e)
{
	if(i>L.length)
	{
		cout<<"�������λ������"<<endl;
		return;
	}
	e=L.data[i-1];
}
//LocationElem(L,e)�������Ա��в��������ֵe��ȵ�Ԫ�أ�������ҳɹ������ظ�Ԫ���ڱ�����ű�ʾ�ɹ������򣬷���0��ʾʧ�ܡ�
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
//ListInsert(*L,i,e)�������Ա�L�е�i��λ�ò�����Ԫ��e��
Status ListInsert(List& L,int i,ElemType e)
{
	//�ж��û������λ���Ƿ����
	if(i>L.length+1&&i<1)
	{
		cout<<"�������λ������"<<endl;
		return ERROR;
	}
	//�жϲ����λ���Ƿ���˳����ĩβ
	if(i<=L.length)
	{
		int j;
		for(j=L.length; j>=i; j--)
		{
			//��Ҫ����Ԫ�صĺ����Ԫ��ȫ�������
			L.data[j]=L.data[j-1];
		}
	}
	//���۲���ǰ�����ĩβ����ִ��
	L.data[i-1]=e;
	L.length++;
	return OK;
}

// ListDelete(*L,i*e):ɾ�����Ա�L�е�i��λ��Ԫ�أ�����e������ֵ��
Status ListDelete(List& L,int i,ElemType& e)
{
	//�ж��û������λ���Ƿ�����
	if(i>=L.length&&i<1)
	{
		cout<<"�����������"<<endl;
		return ERROR;
	}
	//�ж�ɾ����λ���Ƿ���˳����ĩβ
	if(i<=L.length)
	{
		//��ɾ��Ԫ�ص�λ�ú��������Ԫ����ǰ��һλ
		e=L.data[i-1];
		int j;
		for(j=i-1; j<L.length-1; j++)
		{
			//����һλԪ�ص�ֵ��ֵ��ǰһ��Ԫ�أ��ﵽ���ǵ�Ч��
			L.data[j]=L.data[j+1];
		}
	}
	//����ɾ����һ������Ҫִ�е����
	L.length--;
	return OK;
}

// ListLength(L)���������Ա�L��Ԫ�ظ�����
int ListLength(List L)
{
	return L.length;
}
/*
	�����������ڵ��ø���������ͨ���������ܵ�ƴ��ʵ������
			�������ڲ���
*/
int main()
{

	List list; //����һ���������
	system("color 02");
	//�ж�list���������ͺ��ֽ�
	//int size=sizeof(list);
	//cout<<size<<endl;
	if(InitList(&list))
	{
		//�ж������Ƿ�Ϊ��
		if(!ListEmpty(list))
		{
			AddDatas(list);
			List* p=&list;
			//ShowDatas(list);
			/*	//������պ���
			ClearList(list);
			//չʾ������պ������
			ShowDatas(list);
			*/
			//����˳����еĵ�5��Ԫ��
			ElemType e;
			GetElem(list,5,e);
			//cout<<e<<endl;
			//����LocationElem��������
			int a;
			a=LocationElem(list,2);
			if(a)
			{
				//cout<<a<<endl;
				ListDelete(list,1,a);
				cout<<"ɾ����Ԫ��Ϊ��"<<a<<endl;
				ShowDatas(list);
				cout<<"����ĸ���Ϊ:"<<ListLength(list)<<endl;
			}
			else
			{
				cout<<"δ�ҵ�"<<endl;
			}
			cout<<"���Գɹ�"<<endl;
		}
	}
	else
	{
		cout<<"����ʧ��"<<endl;
	}
	return 0;
}
