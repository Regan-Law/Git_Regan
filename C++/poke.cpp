#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
class PerDeck
{
	int nNum;	//ʵ������
	public:
	void Show();	//��ʾ
	void SortFace();	//����ֵ����
	void SortSuit();	//����ɫ����
	int Delete(int n);	//ɾ�����Ϊn����һ���˿�
};

class Playing_Card    //�˿���
{
private:
	int m_Value;	//�˿˵�ʵ����ֵ�������ͱ�ʾ����1��ʼ��1~13
	char m_Face[3];  //�˿˵����ִ�С
	char m_Suit;    //�˿˵Ļ�ɫ���ڡ��졢÷������
	//���ұ�ǵ�ASCII��Ϊ6, ���ұ�ǵ�ASCII��Ϊ3, �����ǵ�ASCII��Ϊ4,÷����ǵ�ASCII��Ϊ5��
public:
	friend class PerDeck;
	Playing_Card();		//���캯������������������
	void showcard();	//��ʾ�˿˶������ֵ����ɫ
	void Card_Make(int);//�����˿�,Ϊһ���˿��ƵĶ������ض�����ֵ����ɫ
};

class Deck	//һ���˿ˣ�54�ţ�
{
private:
	Playing_Card m_cardarray[54];			//�����˿���Ķ���
	int m_lastdelt;					//����⸱�˿���ɾ��������
public:
	friend class PerDeck;
	Deck();					//���캯���������ڵ�52��������a
	void MakeDeck();		//����һ���˿ˣ������ڵ�54���Ƹ�����ֵ����ɫ
	void Deal_One();		//���⸱�ƵĿ�ͷɾ��һ����
	void ShowDeck();		//���δ�ӡ�˿˵�����
	void DeckShuff(int);	//ϴ�ƣ�����Ϊϴ�ƴ���
	void Remove_Card();		//ɾ����ʹ�õ��˿ˣ�ʹɾ���������Ƶ���������
};							
//��������
void Program_Init();					//�˵�
void Center_Text(char[]);				//ʹ�ò˵��������
int get_number();						//�����û�������ֵָ��
char Get_Key();							//�����û��ַ���ָ��
void DeckMakeDriver();					
//������Ҫ�㷨���ڲ����ö�����������������˿ˣ�ϴ�ƣ�ɾ����
int getRandInt(int min,int max);		//ȡ��������֮������������ֵ
void prog_close();						//��ͣ�������У�ʹ�û��ܹ��鿴�м�����н��

int main()				//������
//*	Returns:			Integer 0;
//*	Tasks				(1) Seeds the Random number generator
//*					(2) Calls Program Init function for Title etc.
//*					(3) Call DeckMakeDriver to Test MakeDeck and DeckShuff.
{
	srand((unsigned)time(NULL));		 //�õ����������ʼ�����������
	int Card_Number=0;						
	Program_Init();					     //��ʾ�˵�
	DeckMakeDriver();					//���ó�����Ҫ�㷨�������������Ҫ��������
	prog_close();						//��ͣ�������У�ʹ�û��ܹ��鿴�м�����н��
	return 1;
}

Playing_Card::Playing_Card()			//�˿��๹�캯��
{
	for(int i=1;i<=3;i++)				//��ʼ���˿��Ƶ���ֵ������
	{
		m_Face[i]=' ';			//����ֵΪ�գ�������ֵ
	}
	m_Suit=' ';					//ʹ��ɫΪ�գ������ɫ
	m_Value=NULL;					//���˿��Ƶ�ʵ����ֵΪ0������
}

void Program_Init()				//��ӡ�˵�
{
	Center_Text("<�˿�����Ϸ>");
	cout<<endl;
	Center_Text("(C++)2021,ͯ��");
	cout<<endl;
	Center_Text("����<Return>���Կ�ʼ...");
	cin.get();
}

char Get_Key()				//�����û�ָ��
{
	char x;
	x=cin.get();
	cout<<endl;
	return x;
}

void Playing_Card::showcard()		//��ӡ�˿��ƣ����ţ�����ֵ����ɫ
{
	cout<<"  ";			//���ƴ�ӡ��ʽ
	cout<<m_Face;			//��ӡ�˿���ֵ
	cout.width(1);			//��ӡ�������
	cout<<m_Suit;			//��ӡ�˿˻�ɫ
	cout<<" ";				//���ƴ�ӡ��ʽ
}

void Center_Text(char ShellText[80])	//ʹ�ò˵����������ʾ
{
	int length;
	int center;
	length=strlen(ShellText);	//��ȡ��ӡ�ַ�����С
	center=(80-length)/2;		//������Ļ������Ϊ80����ȡ�ַ����ڸ��е���ʼλ��
	for(;center!=0;center--)	//���ַ���ǰ����ո�
	{
		_cputs(" ");
	}
	_cputs(ShellText);
}

int get_number()		//�����û�ָ����ͣ�
{
	int Input_Integer=0;
	Center_Text("������һ����0~53֮�������������54���˳�.");
	cout<<endl;
	cin>>Input_Integer;
	return Input_Integer;	//�����û��������������
}

void Playing_Card::Card_Make(int num) 
//���ݲ���num����һ���˿ˣ�num��ͬ�����ɵ���ֵ��ɫ��ͬ
{
	int i=0;
	char j;
	int face_num=num%13;	//�˿��Ƶ���ֵ����0��12
	switch(face_num)
	//����ֵ����10ʱ����J��Q��K���棬��ֵΪ�㣬��A����
	{
	case 0: strcpy(m_Face," A");break;
	case 9: strcpy(m_Face,"10");break;
	case 10: strcpy(m_Face," J");break;
	case 11: strcpy(m_Face," Q");break;
	case 12: strcpy(m_Face," K");break;
	default:
		j=char(face_num+49);	//������ֵʹ�ö�ӦASCII���ʾ		
		if(i<3)
		{
			m_Face[i]=' ';i++;
			m_Face[i]=j;i++;
			m_Face[i]=NULL;
			break;
		}
	}
	if(num<=12)m_Suit=6;				//��1-13�����Ǻ���
	if(num>12&&num<=25)m_Suit=3;		//��14-26�����Ǻ���
	if(num>25&&num<=38)m_Suit=5;		//��27-39������÷��
	if(num>38&&num<=51)m_Suit=4;		//��40-52�����Ƿ���
	if(num>51&&num<=52)
	{
		strcpy(m_Face," S");
		m_Suit=1;		//��53����С��
	}
	if(num>52&&num<=53)
	{	
		strcpy(m_Face," B");
		m_Suit=2;		//��54���Ǵ���
	}
	if(face_num<=9)m_Value=face_num+1;	//����������������ֵ���Σ�1
	if(face_num>=10)m_Value=10;
}

void DeckMakeDriver()	//��Ҫ�����������
{
	Deck deck_1;				//�������deck_1
	deck_1.MakeDeck();			//��54���˿˸�ֵ
	deck_1.ShowDeck();			//��һ��ʾ��54����
	Get_Key();					//��ͣ����
	deck_1.DeckShuff(250);		//�����ɵ���ϴ��250��
	deck_1.ShowDeck();			// ��ӡϴ�õ���
	cout<<endl<<endl<<endl;
	char y;
	do
	{
		deck_1.Deal_One();	//���⸱�ƵĿ�ʼλ��ɾ��һ����
		cout<<endl;		
		cout<<endl<<endl<<"ѡ��Yɾ��һ���ƣ�ѡ��N�˳�"<<endl;
		cin>>y;		//ѯ���Ƿ����ɾ��
		y=toupper(y);
	}	
	while(y=='Y');
}

void Deck::MakeDeck()	//�����ɵ�54���������ֵ				
{
	m_lastdelt=53;		//����ֵ������Ϊ����ÿ���˿��ƵĲ���								
	while(m_lastdelt>-1)	//�ж��Ƿ�������һ���˿��ƣ�54���ƣ�
	{
		m_cardarray[m_lastdelt].Card_Make(m_lastdelt);  //����ÿ���˿˵����ɺ��������θ�ֵ
		m_lastdelt--;			//������һ���˿˺�ʹ�����ɲ�����һ
	}
}

void Deck::ShowDeck()	//��ӡһ���˿�
{
	int index=m_lastdelt+1;		//�Ը�λ��Ϊ��һ���ƣ���ͷ��ʾ�⸱��
	int newline=0;
	Center_Text("������һ����");
	cout<<endl;
	while(index<54)
	{
		if(newline%12==0) cout<<endl;	//ÿ��ӡ12�Ż�һ����
		m_cardarray[index].showcard();		//�������˳��������ʾ
		newline++;	
		index++;
	}
}

int getRandInt(int min,int max)		//����������֮���һ���������ֵ
{
	int numToReturn;
	numToReturn=rand();		//��ȡ���ֵ
	numToReturn=numToReturn%(max-min+1)+min; //�����ֵ�ķ�Χ������2������֮��
	return numToReturn;
}

void Deck::DeckShuff(int times)   //ϴ�ƣ�timesΪ����
{
	int x,split;   //split�Ƿֿ��������ֵ�λ�ã����ϲ��֡��²���
	Center_Text("ϴ��");
	cout<<endl;
	for(x=0;x<=times;x++)					
	{
		split=getRandInt(20,35);				
		Deck topdeck;				//������һ����
		Deck bottomdeck;			//�����ڶ�����
		int i;
		int bottomdeckindex=1;
		int topdeckindex=1;
		for(i=0;i<=split-1;)	//����һ���˿˵��ϱ߲��ֵ�������ֵ���ڶ����˿���
		{
			topdeck.m_cardarray[topdeckindex]=this->m_cardarray[i];
			topdeckindex++;
			i++;
		}
		for(i=(split);i<54;)	//����һ���˿˵��±߲��ֵ�������ֵ���ڶ����˿���
		{
			bottomdeck.m_cardarray[bottomdeckindex]=this->m_cardarray[i];
			bottomdeckindex++;
			i++;
		}
		int deckoutindex=0;				
		int numcardstomovetop;
		int numcardstomovebottom;
		int j;
		int h=0;
		bottomdeckindex=54-split;	//�ڶ����Ƶ�����
		topdeckindex=split;			//��һ���Ƶ�����
		while(deckoutindex<=53)
		{
			numcardstomovetop=getRandInt(2,7);
			//�ӵ�һ���Ƴ�ȡ����������2~7֮��������
			numcardstomovebottom=getRandInt(2,7);
			//ͬ���ڵڶ����Ƴ�ȡ����������2~7֮��������
			for(j=0;j<=numcardstomovebottom;j++)	//��0��ʼѭ��numcardstomovebottom��
			{
				if(bottomdeckindex>0)	//���ڶ�����û��ѭ����ʱ����		
				{
					this->m_cardarray[deckoutindex]=bottomdeck.m_cardarray[bottomdeckindex];
					//�ӵڶ����Ƶ����������ʼ���������һ���˿��Ƹ�ֵ
					deckoutindex++;
					bottomdeckindex--;
				}
				for(h=0;h<=numcardstomovetop;h++)	//�ڶ����˿��Ƹ�ֵ���֮�󣬶Ե�һ�����ظ�����
				{			
					if((topdeckindex>0)&&(deckoutindex<=52))
						
					{		
						this->m_cardarray[deckoutindex]=topdeck.m_cardarray[topdeckindex];
						deckoutindex++;
						topdeckindex--;
					}
				}
			}
		}
	}
	this->m_lastdelt=-1;	//��ɾ�����Ƶ�������ԭΪ-1��δɾ����			
}

void prog_close()	//������ͣ
{
	cout<<endl<<endl;
	cout<<"����<Return>������..."<<endl;
	cout<<endl<<endl;
	Get_Key();		
	cin.get();
}

void Deck::Remove_Card()
{
	m_cardarray[m_lastdelt]= Playing_Card();	
}

void Deck::Deal_One()
{
	if(m_lastdelt!=53)		//��δ��������ɾ����ʱ����		
	{
		m_lastdelt++;	//ɾ��������+1
		cout.width(5);	//���ƴ�ӡ����
		cout<<"    ɾ����";
		m_cardarray[m_lastdelt].showcard();	//��ʾɾ���Ƶ����漰��ɫ
	}
	else
	{
			cout << "�⸱��ȫ��ɾ������";
			prog_close();
	}
}

Deck::Deck()		//��ʼ��һ���˿��ƣ���54���ƾ�����				
{
	int lastdelt = 0;
	int i;
	for(i=0;i<=51;i++)
	{
		m_cardarray[1] = Playing_Card();	 //����һ����ʱ����ֵ   
	}								
}								
