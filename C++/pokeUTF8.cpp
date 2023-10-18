#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;
//class PerDeck
//{
//	Playing_Card m_Card[20];	//最多有20张牌
//	int nNum;	//实际张数
//	public:
//	void Show();	//显示
//	void SortFace();	//按面值排序
//	void SortSuit();	//按花色排序
//	int Delete(int n);	//删除序号为n的那一张扑克
//};

class Playing_Card    //扑克类
{
private:
	int m_Value;	//扑克的实际面值，用整型表示，从1开始，1~13
	char m_Face[3];  //扑克的数字大小
	char m_Suit;    //扑克的花色（黑、红、梅、方）
	//黑桃标记的ASCII码为6, 红桃标记的ASCII码为3, 方块标记的ASCII码为4,梅花标记的ASCII码为5。
public:
	Playing_Card();		//构造函数，用来将对象清零
	void showcard();	//显示扑克对象的面值、花色
	void Card_Make(int);//创建扑克,为一张扑克牌的对象赋予特定的面值及花色
};

class Deck	//一副扑克（54张）
{
private:
	Playing_Card m_cardarray[54];			//创建扑克类的对象
	int m_lastdelt;					//标记这副扑克牌删除的张数
public:
	Deck();					//构造函数，将其内的52张牌清零a
	void MakeDeck();		//生成一副扑克，对其内的54张牌赋予面值及花色
	void Deal_One();		//从这副牌的开头删除一张牌
	void ShowDeck();		//依次打印扑克的牌面
	void DeckShuff(int);	//洗牌，参数为洗牌次数
	void Remove_Card();		//删除已使用的扑克，使删除的那张牌的内容清零
};							
//函数声明
void Program_Init();					//菜单
void Center_Text(char[]);				//使得菜单界面居中
int get_number();						//接收用户整型数值指令
char Get_Key();							//接收用户字符型指令
void DeckMakeDriver();					
//程序主要算法，内部调用多个函数，包括生成扑克，洗牌，删除等
int getRandInt(int min,int max);		//取得两参数之间的整型随机数值
void prog_close();						//暂停程序运行，使用户能够查看中间的运行结果

int main()				//主函数
//*	Returns:			Integer 0;
//*	Tasks				(1) Seeds the Random number generator
//*					(2) Calls Program Init function for Title etc.
//*					(3) Call DeckMakeDriver to Test MakeDeck and DeckShuff.
{
	srand((unsigned)time(NULL));		 //得到随机数，初始化随机数种子
	int Card_Number=0;						
	Program_Init();					     //显示菜单
	DeckMakeDriver();					//调用程序主要算法，包含程序的主要操作过程
	prog_close();						//暂停程序运行，使用户能够查看中间的运行结果
	return 1;
}

Playing_Card::Playing_Card()			//扑克类构造函数
{
	for(int i=1;i<=3;i++)				//初始化扑克牌的面值，清零
	{
		m_Face[i]=' ';			//令面值为空，清零面值
	}
	m_Suit=' ';					//使花色为空，清楚花色
	m_Value=0;					//是扑克牌的实际面值为0，清零
}

void Program_Init()				//打印菜单
{
	Center_Text("<扑克牌游戏>");
	cout<<endl;
	Center_Text("(C++)2021,童言");
	cout<<endl;
	Center_Text("单击<Return>键以开始...");
	cin.get();
}

char Get_Key()				//接收用户指令
{
	char x;
	x=cin.get();
	cout<<endl;
	return x;
}

void Playing_Card::showcard()		//打印扑克牌（单张）的面值及花色
{
	cout<<"   ";			//控制打印格式
	cout<<m_Face;			//打印扑克面值
	cout.width(1);			//打印宽度限制
	cout<<m_Suit;			//打印扑克花色
	cout<<" ";				//控制打印格式
}

void Center_Text(char ShellText[80])	//使得菜单界面居中显示
{
	int length;
	int center;
	length=strlen(ShellText);	//获取打印字符串大小
	center=(80-length)/2;		//整个屏幕的列数为80，获取字符串在该行的起始位置
	for(;center!=0;center--)	//在字符串前输出空格
	{
		_cputs(" ");
	}
	_cputs(ShellText);
}

int get_number()		//接收用户指令（整型）
{
	int Input_Integer=0;
	Center_Text("请输入一个在0~53之间的整数，输入54以退出.");
	cout<<endl;
	cin>>Input_Integer;
	return Input_Integer;
}

void Playing_Card::Card_Make(int num) 
//根据参数num生成一张扑克，num不同，生成的面值或花色不同
{
	int i=0;
	char j;
	int face_num=num%13;	//扑克牌的面值，从0到12
	switch(face_num)	
	//当面值大于10时，用J，Q，K代替，面值为零，用A代替
	{
	case 0: strcpy(m_Face," A");break;
	case 9: strcpy(m_Face,"10");break;
	case 10: strcpy(m_Face," J");break;
	case 11: strcpy(m_Face," Q");break;
	case 12: strcpy(m_Face," K");break;
	default:
		j=char(face_num+49);	//其他面值使用对应ASCII码表示		
		if(i<3)
		{
			m_Face[i]=' ';i++;
			m_Face[i]=j;i++;
			m_Face[i]='0';
			break;
		}
	}
	if(num<=12)m_Suit=6;				//第1-13张牌是黑桃
	if(num>12&&num<=25)m_Suit=3;		//第14-26张牌是红桃
	if(num>25&&num<=38)m_Suit=5;		//第27-39张牌是梅花
	if(num>38&&num<=51)m_Suit=4;		//第40-52张牌是方块
	if(num>51&&num<=53)m_Suit=1;		//第53张是小王
	if(num>53&&num<=54)m_Suit=2;		//第54张是大王
	if(face_num<=9)m_Value=face_num+1;	//计算机从零计数，面值依次＋1
	if(face_num>=10)m_Value=10;
}

void DeckMakeDriver()	//主要程序操作函数
{
	Deck deck_1;				//定义对象deck_1
	deck_1.MakeDeck();			//对54张扑克赋值
	deck_1.ShowDeck();			//逐一显示这54张牌
	Get_Key();					//暂停程序
	deck_1.DeckShuff(250);		//对生成的牌洗牌250次
	deck_1.ShowDeck();			// 打印洗好的牌
	cout<<endl<<endl<<endl;
	char y;
	do
	{
		deck_1.Deal_One();	//从这副牌的开始位置删除一张牌
		cout<<endl;		
		cout<<endl<<endl<<"选择Y删除一张牌，选择N退出"<<endl;
		cin>>y;		//询问是否继续删除
		y=toupper(y);
	}	
	while(y=='Y');
}

void Deck::MakeDeck()	//对生成的54张牌逐个赋值				
{
	m_lastdelt=53;		//赋初值，该牌为生成每张扑克牌的参数								
	while(m_lastdelt>-1)	//判断是否生成完一副扑克牌（54张牌）
	{
		m_cardarray[m_lastdelt].Card_Make(m_lastdelt);  //调用每张扑克的生成函数，依次赋值
		m_lastdelt--;			//生成完一张扑克后使其生成参数减一
	}
}

void Deck::ShowDeck()	//打印一副扑克
{
	int index=m_lastdelt+1;		//以该位置为第一张牌，从头显示这副牌
	int newline=0;
	Center_Text("完整的一副牌");
	cout<<endl;
	while(index<=53)
	{
		if(newline%11==0) cout<<endl;	//每打印11张换一次行
		m_cardarray[index].showcard();		//按数组的顺序依次显示
		newline++;	
		index++;
	}
}

int getRandInt(int min,int max)		//返回两参数之间的一个整型随机值
{
	int numToReturn;
	numToReturn=rand();		//获取随机值
	numToReturn=numToReturn%(max-min+1)+min; //将随机值的范围调整到2个参数之间
	return numToReturn;
}

void Deck::DeckShuff(int times)   //洗牌，times为次数
{
	int x,split;   //split是分开成两部分的位置，如上部分、下部分
	Center_Text("洗牌");
	cout<<endl;
	for(x=0;x<=times;x++)					
	{
		split=getRandInt(20,35);				
		Deck topdeck;				//创建第一副牌
		Deck bottomdeck;			//创建第二副牌
		int i;
		int bottomdeckindex=1;
		int topdeckindex=1;
		for(i=0;i<=split-1;)	//将第一副扑克的上边部分的张数赋值到第二副扑克中
		{
			topdeck.m_cardarray[topdeckindex]=this->m_cardarray[i];
			topdeckindex++;
			i++;
		}
		for(i=(split);i<54;)	//将第一副扑克的下边部分的张数赋值到第二副扑克中
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
		bottomdeckindex=54-split;	//第二副牌的张数
		topdeckindex=split;			//第一副牌的张数
		while(deckoutindex<=53)
		{
			numcardstomovetop=getRandInt(2,7);
			//从第一副牌抽取的张数，是2~7之间的随机数
			numcardstomovebottom=getRandInt(2,7);
			//同样在第二副牌抽取的张数，是2~7之间的随机数
			for(j=0;j<=numcardstomovebottom;j++)	//从0开始循环numcardstomovebottom次
			{
				if(bottomdeckindex>0)	//当第二副牌没有循环完时继续		
				{
					this->m_cardarray[deckoutindex]=bottomdeck.m_cardarray[bottomdeckindex];
					//从第二副牌的最后张数开始，依次向第一副扑克牌赋值
					deckoutindex++;
					bottomdeckindex--;
				}
				for(h=0;h<=numcardstomovetop;h++)	//第二副扑克牌赋值完成之后，对第一副牌重复操作
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
	this->m_lastdelt=-1;	//将删除的牌的张数复原为-1（未删除）			
}

void prog_close()	//程序暂停
{
	cout<<endl<<endl;
	cout<<"单击<Return>键继续..."<<endl;
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
	if(m_lastdelt!=53)		//当未将整副牌删除完时继续		
	{
		m_lastdelt++;	//删除的张数+1
		cout.width(5);	//控制打印长度
		cout<<"    删除牌";
		m_cardarray[m_lastdelt].showcard();	//显示删除牌的牌面及花色
	}
	else
	{
			cout << "这副牌全部删除完了";
			prog_close();
	}
}

Deck::Deck()		//初始化一副扑克牌，将54张牌均清零				
{
	int lastdelt = 0;
	int i;
	for(i=0;i<=51;i++)
	{
		m_cardarray[1] = Playing_Card();	 //构造一个临时对象赋值   
	}								
}								
