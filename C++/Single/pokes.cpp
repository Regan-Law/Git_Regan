#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

class Playing_Card//扑克牌类,表示一张扑克牌的面值、花色和与之相联系的操作
{
private:
	int m_Value;//扑克的实际面值,用整型值表示,从1开始,1~13
	char m_Face[3];//扑克的数字大小,用字符串的形式表示,为A,2,3,…,10,J,Q,K
	char m_Suit;//扑克的花色（黑、红、梅、方）
public:
	Playing_Card();//构造函数,初始化扑克对象,实际上是将对象清零
	void showcard();//显示扑克牌对象的面值,花色
	void Card_Make(int);//为一张扑克牌对象赋予特定的面值和花色
	friend class PerDeck;//定义类PerDeck为类Playing_Card的友元类
};

class Deck	//一副扑克(54张)类
{
private:
	Playing_Card m_cardarray[54];//一副扑克由54张扑克牌构成
	int m_lastdelt;//标记这副扑克牌删除的张数
public:
	Deck();//构造函数,初始化一副扑克牌对象,实际上是将其内的54张扑克牌清零
	void MakeDeck();//生成一副扑克,即对其内的54张扑克赋予正确的面值及花色
	void ShowDeck();//依次逐张显示这副牌
	void DeckShuff(int);//洗牌,其参数是洗牌的次数
	void Remove_Card();//将删除的那张扑克牌的内容清零,使这张牌在屏幕上显示不出来
	friend class PerDeck;//定义类PerDeck为类Deck的友元类
};

class PerDeck
{
	Playing_Card m_Card[20];//最多有20张牌
	int nNum;//实际张数
public:
	PerDeck(){}
	void MakeperDeck(Deck&,int);//对象初始化,参数为指定的那副牌及实际赋值个数
	void Show();//显示
	void SortFace();//按面值排序
	void SortSuit();//按花色排序
	int Delete(int n);//删除序号为n的那一张
};

void PerDeck::MakeperDeck(Deck&deck_3,int n)
{
	nNum=n;//初始化当前对象的实际张数
	static int i=0;//标记为每个人发牌的其始位置
	for(int k=0;k<nNum;k++)m_Card[k]=deck_3.m_cardarray[i+k];//用创建好的那副牌为当前对象发牌
	i+=nNum;//为一个人发牌后起始位置向后跳nNum个
}

void PerDeck::Show()//显示玩家的牌面
{
	int j=0;
	if(nNum==0)cout<<"已无牌!"<<endl;//如果玩家无牌输出提示信息
	else
		{
			for(int i=0;i<nNum;i++)
			{
				if(j%11==0)cout<<endl;//每行输出11张牌
				m_Card[i].showcard();
		        j++;
			}
		}
}

int PerDeck::Delete(int n)//删除序号为n的那一张
{
	if(n>=nNum)return 0;//判断是否删牌
	else
	{
		for(int i=n;i<nNum;i++)m_Card[i]=m_Card[i+1];//删除指定的牌
	    nNum--;//删除一张牌后将实际张数减1
        return 1;
	}
}

void PerDeck::SortFace()//按面值排序
{
	Playing_Card record;//产生一个临时对象
	for(int j=0;j<nNum-1;j++)
		for(int i=j+1;i<nNum;i++)
			if(m_Card[j].m_Value>m_Card[i].m_Value)
			{record=m_Card[i];m_Card[i]=m_Card[j];m_Card[j]=record;}	
}

void PerDeck::SortSuit()//按花色排序
{
	Playing_Card record;//产生一个临时对象
	for(int j=0;j<nNum-1;j++)
		for(int i=j+1;i<nNum;i++)
			if(m_Card[j].m_Suit>m_Card[i].m_Suit)
			{record=m_Card[i];m_Card[i]=m_Card[j];m_Card[j]=record;}
}

class PlayDeck
{
	PerDeck m_deck[4];//一共是四个人玩牌
public:
	PlayDeck(){}
	void PlayCard(Deck&);//用指定的那副牌对四个人分别赋值
	void Show();//显示
	int DeleteOne(int row,int column);//删除一张,参数为第row个人的第column张牌
	int DeleteAll(int,int,int,int);//删除一轮,参数分别代表四个人各删除哪一张
	void SortDeckFace();//对整副牌面值排序
    void SortDeckSuit();//对整副牌花色排序
};

void PlayDeck::PlayCard(Deck&deck_2)//给四个人发牌
{
	for(int i=0;i<2;i++)m_deck[i].MakeperDeck(deck_2,14);//前两个人发14张牌
	for(int j=2;j<4;j++)m_deck[j].MakeperDeck(deck_2,13);//后两个人发13张牌
}

void PlayDeck::Show()//显示四个玩家的牌
{
	for(int i=0;i<4;i++)
	{
		cout<<endl;
		cout<<"玩家"<<i+1<<"的牌:";
		m_deck[i].Show();
	}
	cout<<endl<<endl;
}

int PlayDeck::DeleteOne(int row,int column)//删除一张,参数为第row个人的第column张牌
{
	return m_deck[row-1].Delete(column-1);
}

int PlayDeck::DeleteAll(int a,int b,int c,int d)//删除一轮,参数分别代表四个人各删除哪一张
{
	return m_deck[0].Delete(a-1)+m_deck[1].Delete(b-1)+m_deck[2].Delete(c-1)+m_deck[3].Delete(d-1);
}

void PlayDeck::SortDeckFace()//将四个人的牌按面值排序
{
	m_deck[0].SortFace();
	m_deck[1].SortFace();
	m_deck[2].SortFace();
	m_deck[3].SortFace();
}

void PlayDeck::SortDeckSuit()//将四个人的牌按花色排序
{
	m_deck[0].SortSuit();
	m_deck[1].SortSuit();
	m_deck[2].SortSuit();
	m_deck[3].SortSuit();
}

void Program_Init();//程序初始化,输出初始化信息

int main();//主函数
void Center_Text(char []);//将参数(字符串)在屏幕上显示在一行的中间位置
void Get_Key();//接收用户键入的字符
void DeckMakeDriver();/*程序的主要算法,内部调用多个函数,包括生成扑克牌,
洗牌,删除,排序等主要操作*/
int getRandInt(int min,int max);//取得在两参数间的整型随机值
void prog_close();//暂停程序运行,供用户查看中间运行结果
		
int main()
{
	srand((unsigned)time(NULL));//初始化随机数种子		
	Program_Init();//显示程序初始化提示信息
	DeckMakeDriver();//调用程序的主要算法,包含程序的主要操作过程
	prog_close();//暂停程序运行,供用户查看运行结果					
	return 1;									
}

Playing_Card::Playing_Card()			//扑克牌对象的构造函数
{
		int i;
		for(i=0;i<3;)					//初始化扑克牌的面值,清零
		{
			m_Face[i]=' ';
			i++;
		}
		m_Suit=' ';					//初始化扑克牌的花色,清零
		m_Value=0;
}

void Program_Init()//程序一开始运行的提示信息
{
	Center_Text("扑克牌游戏\n");
    Center_Text("程序设计:童言");
	cout<<endl<<endl;
	Get_Key();
}

void Get_Key()//从键盘接收用户键入的字符
{
	cout<<endl;
	Center_Text("单击任意键继续");
	getch();
    cout<<endl;
}

void Playing_Card::showcard()//在屏幕上显示一张扑克牌的面值及花色
{		
	cout<<"   ";
	cout<<m_Face;//显示面值       
	cout.width(1);
	cout<<m_Suit;//显示花色
	cout<<" ";
}

void Center_Text(char ShellText[80])//将函数参数(字符串)在屏幕上居中显示
{
	int length;
	int center;
	length=strlen(ShellText);//取得欲显示字符串的大小
	center=(80-length)/2;//整个屏幕的列数为80,取得字符串在该行的其始位置
	for(;center!=0;center--)//在字符串前输出空格
	{
		cout<<" ";
	}
	cout<<ShellText;
}

void Playing_Card::Card_Make(int num)/*根据参数num生成一张扑克牌,num不同,生成的
										 面值或花色不同*/
{

	int i=0;
	char j;
	int face_num=num%13;//扑克牌的面值,从0到12
	if(num==52)strcpy(m_Face," S");//大王花色赋为S
	else if(num==53)strcpy(m_Face," B");//小王花色赋为B
	else
	{
	switch(face_num)				//当面值大于10时,用J,Q,K代替,面值为0,用A代替
	{
	case 0:strcpy(m_Face," A");break;
	case 9:strcpy(m_Face,"10");break;
	case 10:strcpy(m_Face," J");break;
	case 11:strcpy(m_Face," Q");break;
	case 12:strcpy(m_Face," K");break;
	default:
		j=char(face_num+49);			//其它的面值,用对应的ASCII码表示

		if(i<3)
		{
			m_Face[i]=' ';i++;
			m_Face[i]=j;i++;
			m_Face[i]=NULL;
			break;
		}
	}
	}
	//扑克牌的花色,分别用红桃,黑桃,梅花,方块的ASCII码替代
	if(num<=12)m_Suit=6;//红桃
	if(num>12&&num<=25)m_Suit=3;//黑桃
	if(num>25&&num<=38)m_Suit=5;//梅花
	if(num>38&&num<=51)m_Suit=4;//方块
	if(num==52)m_Suit=1;//小王
	if(num==53)m_Suit=2;//大王
	if(num==52)m_Value=14;//小王面值赋为14
	else if(num==53)m_Value=15;//大王面值赋为15
	else m_Value=face_num+1;//A的面值实际上用1表示,其余面值依次加1
}

void DeckMakeDriver()//主要程序操作部分,调用多个函数,完成生成一副牌,洗牌,显示,删除等操作
{
	Deck deck_1;//生成一副扑克牌对象,内有54张牌,此时所有的扑克牌均未赋值
	PlayDeck man;//产生一局牌
	deck_1.MakeDeck();		//对54张扑克牌赋值
	deck_1.ShowDeck();//逐一显示这54张牌
   	Get_Key();//暂停运行,供用户查看显示结果
	system("cls");//清屏
	deck_1.DeckShuff(250);		//对生成的这副牌洗牌250次
	deck_1.ShowDeck();//逐一显示这洗好的54张牌
	Get_Key();//暂停运行,供用户查看显示结果
	system("cls");//清屏
	man.PlayCard(deck_1);//发牌
	int Memory=0;
	for(;;)
	{
		man.Show();//显示四个人的牌
		Center_Text("******菜单******\n");		//打印菜单
		Center_Text("*1:删除一张牌*\n");
		Center_Text("*2:删除一轮牌*\n");
		Center_Text("*3:花色排序*\n");
		Center_Text("*4:面值排序*\n");
		Center_Text("*5:退出程序*\n");
		Center_Text("****************\n");
        cout<<"请选择菜单里对应功能的一个整数:\n";
		int n;
		char str[30];
A:		cin>>n;
		cin.getline(str,30);
		if(strlen(str)>=1)
		{
			cerr<<"输入错误,请重新输入:"<<endl;
			goto A;
		}
        if(!cin)
		{
			char str[30];
		    cin.clear();
			cin.getline(str,30);
			cerr<<"输入错误,请重新输入:"<<endl;
			goto A;
		}
		switch(n)//判断执行的操作
		{
		case 1://执行删除一张牌的操作
				int a,b;
				char str[30];
B:				cout<<"请输入删除第几个人的第几张牌"<<endl;
			    cin>>a>>b;
			    cin.getline(str,30);
				if(strlen(str)>=2)
				{
					cerr<<"输入错误,请重新输入:"<<endl;
				    goto B;
				}
				while(!cin)
				{
					char str[30];
					cin.clear();
					cin.getline(str,30);
					cerr<<"输入错误,请重新输入:"<<endl;
				    goto B;
				}
				Memory+=man.DeleteOne(a,b);
				break;
		case 2://执行删除一轮牌的操作
				int c,d,e,f;
				char str1[30];
D:				cout<<"请依次输入删除四个人的第几张牌"<<endl;
				cin>>c>>d>>e>>f;
				cin.getline(str1,30);
				if(strlen(str1)>=2)
				{
					cerr<<"输入错误,请重新输入:"<<endl;
			        goto D;
				}
				while(!cin)
				{
					char str[30];
					cin.clear();
					cin.getline(str,30);
					cerr<<"输入错误,请重新输入:"<<endl;
				    goto D;
				}
				Memory+=man.DeleteAll(c,d,e,f);
				break;
		case 3:
			man.SortDeckSuit();//执行按花色排序
			break;
		case 
			4:man.SortDeckFace();//执行按面值排序
			break;
		case 5:
			exit(0);//执行退出程序
		default:
			cerr<<"输入错误,请重新输入:"<<endl;
			goto A;
		}
		system("cls");//清屏
		if(Memory==54)break;//判断循环结束条件
	}
	cout<<endl<<endl<<endl;
}				

void Deck::MakeDeck()			//对生成的54张牌逐个赋值
{
	m_lastdelt=53;				//赋初值,该值作为生成每张扑克牌的参数
	while(m_lastdelt>-1)			//判断是否产生完54张牌
	{										
		m_cardarray[m_lastdelt].Card_Make(m_lastdelt);/*调用每张扑克牌的生成函数,依次
														对每张扑克牌赋值,直到生成完一副扑克牌*/
		m_lastdelt--;							//生成完一张扑克牌后改变生成的参数				 
	}										
}

void Deck::ShowDeck()//显示一副扑克牌
{
	int index=m_lastdelt+1;//以该位置为第一张牌,从头显示这副扑克牌
	int newline=0;	
	Center_Text("完整的一副牌");
	cout<<endl;
	while(index<=53)
	{
		if(newline%11==0) cout<<endl;//每显示11张输出一个回车
		m_cardarray[index].showcard();			//按数组的顺序依次显示
		newline++;
		index++;
	}
}

int getRandInt(int min,int max)//返回两个参数之间的一个整型随机值
{
	int numToReturn;
	numToReturn=rand();//取得随机值
	numToReturn=numToReturn%(max-min+1)+min;/*将随机值的范围调
														 整到两个参数之间*/
   	return numToReturn;
}

void Deck::DeckShuff( int times)//洗牌,参数为洗牌次数
{
	int x,split;//split是分开成两部分的位置，如上部分、下部分
	Center_Text("洗牌");
	cout<<endl;
	for(x=0;x<=times;x++)			//开始循环,每循环一次将牌全部重排一遍
	{	
		split=getRandInt(20,35);		//随机选取split的值
		Deck topdeck;					//生成两副扑克牌对象
		Deck bottomdeck;
		int i;
		int bottomdeckindex=1;
		int topdeckindex=1;
		for(i=0;i<=split-1;)	/*将初始的那副扑克牌的上边部分的张数赋值到
								新生成的扑克牌对象中*/
		{
			topdeck.m_cardarray[topdeckindex]=this->m_cardarray[i];
			topdeckindex++;	
			i++;
		}
		for(i=(split);i<54;)/*同样将初始那副扑克牌的下边部分的张数赋值到
								新生成的扑克牌对象中*/
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
			bottomdeckindex=54-split;		//下部分那副扑克牌的张数
		topdeckindex=split;				//上部分那副扑克牌的张数
		while(deckoutindex<=53)
		{
			numcardstomovetop=getRandInt(2,7);//从上部分抽取的张数，是2-7之间的随机数
			numcardstomovebottom=getRandInt(2,7);	//同样从下部分抽取的张数,是2-7之间的随机数
			for(j=0;j<=numcardstomovebottom;j++)	//从0开始循环numcardstomovebottom次	
			{
				if(bottomdeckindex>0)				//当下部分那副牌没有循环完时继续
				{
					this->m_cardarray[deckoutindex]=bottomdeck.m_cardarray[bottomdeckindex];
					/*从下部分那副牌的最后张数开始,依次向初始的扑克牌赋值*/
					deckoutindex++;
					bottomdeckindex--;
				}
				for(h=0;h<=numcardstomovetop;h++)/*下部分的那副扑克牌赋值完成后,对
												   上部分的那副牌做同样的操作*/
				{	
					if((topdeckindex>0)&&(deckoutindex<=54))
					{		
						this->m_cardarray[deckoutindex]=topdeck.m_cardarray[topdeckindex];
						deckoutindex++;
						topdeckindex--;
					}
				}
			}
		}
	}	
	this->m_lastdelt=-1;		//将删除牌的张数复原为-1(未删除)
}

void prog_close()//程序暂停,任按一键继续
{
	cout<<endl<<endl;
	Get_Key();
	cout<<endl<<endl;
}
Deck::Deck()				//初始化一副扑克牌,将54张扑克牌均清零
{
	int i;
	for(i=0;i<=53;i++)
	{
		m_cardarray[1]=Playing_Card();	//构造一个临时对象赋值			
	}
}
