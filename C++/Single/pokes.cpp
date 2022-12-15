#include<iostream>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
using namespace std;

class Playing_Card//�˿�����,��ʾһ���˿��Ƶ���ֵ����ɫ����֮����ϵ�Ĳ���
{
private:
	int m_Value;//�˿˵�ʵ����ֵ,������ֵ��ʾ,��1��ʼ,1~13
	char m_Face[3];//�˿˵����ִ�С,���ַ�������ʽ��ʾ,ΪA,2,3,��,10,J,Q,K
	char m_Suit;//�˿˵Ļ�ɫ���ڡ��졢÷������
public:
	Playing_Card();//���캯��,��ʼ���˿˶���,ʵ�����ǽ���������
	void showcard();//��ʾ�˿��ƶ������ֵ,��ɫ
	void Card_Make(int);//Ϊһ���˿��ƶ������ض�����ֵ�ͻ�ɫ
	friend class PerDeck;//������PerDeckΪ��Playing_Card����Ԫ��
};

class Deck	//һ���˿�(54��)��
{
private:
	Playing_Card m_cardarray[54];//һ���˿���54���˿��ƹ���
	int m_lastdelt;//����⸱�˿���ɾ��������
public:
	Deck();//���캯��,��ʼ��һ���˿��ƶ���,ʵ�����ǽ����ڵ�54���˿�������
	void MakeDeck();//����һ���˿�,�������ڵ�54���˿˸�����ȷ����ֵ����ɫ
	void ShowDeck();//����������ʾ�⸱��
	void DeckShuff(int);//ϴ��,�������ϴ�ƵĴ���
	void Remove_Card();//��ɾ���������˿��Ƶ���������,ʹ����������Ļ����ʾ������
	friend class PerDeck;//������PerDeckΪ��Deck����Ԫ��
};

class PerDeck
{
	Playing_Card m_Card[20];//�����20����
	int nNum;//ʵ������
public:
	PerDeck(){}
	void MakeperDeck(Deck&,int);//�����ʼ��,����Ϊָ�����Ǹ��Ƽ�ʵ�ʸ�ֵ����
	void Show();//��ʾ
	void SortFace();//����ֵ����
	void SortSuit();//����ɫ����
	int Delete(int n);//ɾ�����Ϊn����һ��
};

void PerDeck::MakeperDeck(Deck&deck_3,int n)
{
	nNum=n;//��ʼ����ǰ�����ʵ������
	static int i=0;//���Ϊÿ���˷��Ƶ���ʼλ��
	for(int k=0;k<nNum;k++)m_Card[k]=deck_3.m_cardarray[i+k];//�ô����õ��Ǹ���Ϊ��ǰ������
	i+=nNum;//Ϊһ���˷��ƺ���ʼλ�������nNum��
}

void PerDeck::Show()//��ʾ��ҵ�����
{
	int j=0;
	if(nNum==0)cout<<"������!"<<endl;//���������������ʾ��Ϣ
	else
		{
			for(int i=0;i<nNum;i++)
			{
				if(j%11==0)cout<<endl;//ÿ�����11����
				m_Card[i].showcard();
		        j++;
			}
		}
}

int PerDeck::Delete(int n)//ɾ�����Ϊn����һ��
{
	if(n>=nNum)return 0;//�ж��Ƿ�ɾ��
	else
	{
		for(int i=n;i<nNum;i++)m_Card[i]=m_Card[i+1];//ɾ��ָ������
	    nNum--;//ɾ��һ���ƺ�ʵ��������1
        return 1;
	}
}

void PerDeck::SortFace()//����ֵ����
{
	Playing_Card record;//����һ����ʱ����
	for(int j=0;j<nNum-1;j++)
		for(int i=j+1;i<nNum;i++)
			if(m_Card[j].m_Value>m_Card[i].m_Value)
			{record=m_Card[i];m_Card[i]=m_Card[j];m_Card[j]=record;}	
}

void PerDeck::SortSuit()//����ɫ����
{
	Playing_Card record;//����һ����ʱ����
	for(int j=0;j<nNum-1;j++)
		for(int i=j+1;i<nNum;i++)
			if(m_Card[j].m_Suit>m_Card[i].m_Suit)
			{record=m_Card[i];m_Card[i]=m_Card[j];m_Card[j]=record;}
}

class PlayDeck
{
	PerDeck m_deck[4];//һ�����ĸ�������
public:
	PlayDeck(){}
	void PlayCard(Deck&);//��ָ�����Ǹ��ƶ��ĸ��˷ֱ�ֵ
	void Show();//��ʾ
	int DeleteOne(int row,int column);//ɾ��һ��,����Ϊ��row���˵ĵ�column����
	int DeleteAll(int,int,int,int);//ɾ��һ��,�����ֱ�����ĸ��˸�ɾ����һ��
	void SortDeckFace();//����������ֵ����
    void SortDeckSuit();//�������ƻ�ɫ����
};

void PlayDeck::PlayCard(Deck&deck_2)//���ĸ��˷���
{
	for(int i=0;i<2;i++)m_deck[i].MakeperDeck(deck_2,14);//ǰ�����˷�14����
	for(int j=2;j<4;j++)m_deck[j].MakeperDeck(deck_2,13);//�������˷�13����
}

void PlayDeck::Show()//��ʾ�ĸ���ҵ���
{
	for(int i=0;i<4;i++)
	{
		cout<<endl;
		cout<<"���"<<i+1<<"����:";
		m_deck[i].Show();
	}
	cout<<endl<<endl;
}

int PlayDeck::DeleteOne(int row,int column)//ɾ��һ��,����Ϊ��row���˵ĵ�column����
{
	return m_deck[row-1].Delete(column-1);
}

int PlayDeck::DeleteAll(int a,int b,int c,int d)//ɾ��һ��,�����ֱ�����ĸ��˸�ɾ����һ��
{
	return m_deck[0].Delete(a-1)+m_deck[1].Delete(b-1)+m_deck[2].Delete(c-1)+m_deck[3].Delete(d-1);
}

void PlayDeck::SortDeckFace()//���ĸ��˵��ư���ֵ����
{
	m_deck[0].SortFace();
	m_deck[1].SortFace();
	m_deck[2].SortFace();
	m_deck[3].SortFace();
}

void PlayDeck::SortDeckSuit()//���ĸ��˵��ư���ɫ����
{
	m_deck[0].SortSuit();
	m_deck[1].SortSuit();
	m_deck[2].SortSuit();
	m_deck[3].SortSuit();
}

void Program_Init();//�����ʼ��,�����ʼ����Ϣ

int main();//������
void Center_Text(char []);//������(�ַ���)����Ļ����ʾ��һ�е��м�λ��
void Get_Key();//�����û�������ַ�
void DeckMakeDriver();/*�������Ҫ�㷨,�ڲ����ö������,���������˿���,
ϴ��,ɾ��,�������Ҫ����*/
int getRandInt(int min,int max);//ȡ��������������������ֵ
void prog_close();//��ͣ��������,���û��鿴�м����н��
		
int main()
{
	srand((unsigned)time(NULL));//��ʼ�����������		
	Program_Init();//��ʾ�����ʼ����ʾ��Ϣ
	DeckMakeDriver();//���ó������Ҫ�㷨,�����������Ҫ��������
	prog_close();//��ͣ��������,���û��鿴���н��					
	return 1;									
}

Playing_Card::Playing_Card()			//�˿��ƶ���Ĺ��캯��
{
		int i;
		for(i=0;i<3;)					//��ʼ���˿��Ƶ���ֵ,����
		{
			m_Face[i]=' ';
			i++;
		}
		m_Suit=' ';					//��ʼ���˿��ƵĻ�ɫ,����
		m_Value=0;
}

void Program_Init()//����һ��ʼ���е���ʾ��Ϣ
{
	Center_Text("�˿�����Ϸ\n");
    Center_Text("�������:ͯ��");
	cout<<endl<<endl;
	Get_Key();
}

void Get_Key()//�Ӽ��̽����û�������ַ�
{
	cout<<endl;
	Center_Text("�������������");
	getch();
    cout<<endl;
}

void Playing_Card::showcard()//����Ļ����ʾһ���˿��Ƶ���ֵ����ɫ
{		
	cout<<"   ";
	cout<<m_Face;//��ʾ��ֵ       
	cout.width(1);
	cout<<m_Suit;//��ʾ��ɫ
	cout<<" ";
}

void Center_Text(char ShellText[80])//����������(�ַ���)����Ļ�Ͼ�����ʾ
{
	int length;
	int center;
	length=strlen(ShellText);//ȡ������ʾ�ַ����Ĵ�С
	center=(80-length)/2;//������Ļ������Ϊ80,ȡ���ַ����ڸ��е���ʼλ��
	for(;center!=0;center--)//���ַ���ǰ����ո�
	{
		cout<<" ";
	}
	cout<<ShellText;
}

void Playing_Card::Card_Make(int num)/*���ݲ���num����һ���˿���,num��ͬ,���ɵ�
										 ��ֵ��ɫ��ͬ*/
{

	int i=0;
	char j;
	int face_num=num%13;//�˿��Ƶ���ֵ,��0��12
	if(num==52)strcpy(m_Face," S");//������ɫ��ΪS
	else if(num==53)strcpy(m_Face," B");//С����ɫ��ΪB
	else
	{
	switch(face_num)				//����ֵ����10ʱ,��J,Q,K����,��ֵΪ0,��A����
	{
	case 0:strcpy(m_Face," A");break;
	case 9:strcpy(m_Face,"10");break;
	case 10:strcpy(m_Face," J");break;
	case 11:strcpy(m_Face," Q");break;
	case 12:strcpy(m_Face," K");break;
	default:
		j=char(face_num+49);			//��������ֵ,�ö�Ӧ��ASCII���ʾ

		if(i<3)
		{
			m_Face[i]=' ';i++;
			m_Face[i]=j;i++;
			m_Face[i]=NULL;
			break;
		}
	}
	}
	//�˿��ƵĻ�ɫ,�ֱ��ú���,����,÷��,�����ASCII�����
	if(num<=12)m_Suit=6;//����
	if(num>12&&num<=25)m_Suit=3;//����
	if(num>25&&num<=38)m_Suit=5;//÷��
	if(num>38&&num<=51)m_Suit=4;//����
	if(num==52)m_Suit=1;//С��
	if(num==53)m_Suit=2;//����
	if(num==52)m_Value=14;//С����ֵ��Ϊ14
	else if(num==53)m_Value=15;//������ֵ��Ϊ15
	else m_Value=face_num+1;//A����ֵʵ������1��ʾ,������ֵ���μ�1
}

void DeckMakeDriver()//��Ҫ�����������,���ö������,�������һ����,ϴ��,��ʾ,ɾ���Ȳ���
{
	Deck deck_1;//����һ���˿��ƶ���,����54����,��ʱ���е��˿��ƾ�δ��ֵ
	PlayDeck man;//����һ����
	deck_1.MakeDeck();		//��54���˿��Ƹ�ֵ
	deck_1.ShowDeck();//��һ��ʾ��54����
   	Get_Key();//��ͣ����,���û��鿴��ʾ���
	system("cls");//����
	deck_1.DeckShuff(250);		//�����ɵ��⸱��ϴ��250��
	deck_1.ShowDeck();//��һ��ʾ��ϴ�õ�54����
	Get_Key();//��ͣ����,���û��鿴��ʾ���
	system("cls");//����
	man.PlayCard(deck_1);//����
	int Memory=0;
	for(;;)
	{
		man.Show();//��ʾ�ĸ��˵���
		Center_Text("******�˵�******\n");		//��ӡ�˵�
		Center_Text("*1:ɾ��һ����*\n");
		Center_Text("*2:ɾ��һ����*\n");
		Center_Text("*3:��ɫ����*\n");
		Center_Text("*4:��ֵ����*\n");
		Center_Text("*5:�˳�����*\n");
		Center_Text("****************\n");
        cout<<"��ѡ��˵����Ӧ���ܵ�һ������:\n";
		int n;
		char str[30];
A:		cin>>n;
		cin.getline(str,30);
		if(strlen(str)>=1)
		{
			cerr<<"�������,����������:"<<endl;
			goto A;
		}
        if(!cin)
		{
			char str[30];
		    cin.clear();
			cin.getline(str,30);
			cerr<<"�������,����������:"<<endl;
			goto A;
		}
		switch(n)//�ж�ִ�еĲ���
		{
		case 1://ִ��ɾ��һ���ƵĲ���
				int a,b;
				char str[30];
B:				cout<<"������ɾ���ڼ����˵ĵڼ�����"<<endl;
			    cin>>a>>b;
			    cin.getline(str,30);
				if(strlen(str)>=2)
				{
					cerr<<"�������,����������:"<<endl;
				    goto B;
				}
				while(!cin)
				{
					char str[30];
					cin.clear();
					cin.getline(str,30);
					cerr<<"�������,����������:"<<endl;
				    goto B;
				}
				Memory+=man.DeleteOne(a,b);
				break;
		case 2://ִ��ɾ��һ���ƵĲ���
				int c,d,e,f;
				char str1[30];
D:				cout<<"����������ɾ���ĸ��˵ĵڼ�����"<<endl;
				cin>>c>>d>>e>>f;
				cin.getline(str1,30);
				if(strlen(str1)>=2)
				{
					cerr<<"�������,����������:"<<endl;
			        goto D;
				}
				while(!cin)
				{
					char str[30];
					cin.clear();
					cin.getline(str,30);
					cerr<<"�������,����������:"<<endl;
				    goto D;
				}
				Memory+=man.DeleteAll(c,d,e,f);
				break;
		case 3:
			man.SortDeckSuit();//ִ�а���ɫ����
			break;
		case 
			4:man.SortDeckFace();//ִ�а���ֵ����
			break;
		case 5:
			exit(0);//ִ���˳�����
		default:
			cerr<<"�������,����������:"<<endl;
			goto A;
		}
		system("cls");//����
		if(Memory==54)break;//�ж�ѭ����������
	}
	cout<<endl<<endl<<endl;
}				

void Deck::MakeDeck()			//�����ɵ�54���������ֵ
{
	m_lastdelt=53;				//����ֵ,��ֵ��Ϊ����ÿ���˿��ƵĲ���
	while(m_lastdelt>-1)			//�ж��Ƿ������54����
	{										
		m_cardarray[m_lastdelt].Card_Make(m_lastdelt);/*����ÿ���˿��Ƶ����ɺ���,����
														��ÿ���˿��Ƹ�ֵ,ֱ��������һ���˿���*/
		m_lastdelt--;							//������һ���˿��ƺ�ı����ɵĲ���				 
	}										
}

void Deck::ShowDeck()//��ʾһ���˿���
{
	int index=m_lastdelt+1;//�Ը�λ��Ϊ��һ����,��ͷ��ʾ�⸱�˿���
	int newline=0;	
	Center_Text("������һ����");
	cout<<endl;
	while(index<=53)
	{
		if(newline%11==0) cout<<endl;//ÿ��ʾ11�����һ���س�
		m_cardarray[index].showcard();			//�������˳��������ʾ
		newline++;
		index++;
	}
}

int getRandInt(int min,int max)//������������֮���һ���������ֵ
{
	int numToReturn;
	numToReturn=rand();//ȡ�����ֵ
	numToReturn=numToReturn%(max-min+1)+min;/*�����ֵ�ķ�Χ��
														 ������������֮��*/
   	return numToReturn;
}

void Deck::DeckShuff( int times)//ϴ��,����Ϊϴ�ƴ���
{
	int x,split;//split�Ƿֿ��������ֵ�λ�ã����ϲ��֡��²���
	Center_Text("ϴ��");
	cout<<endl;
	for(x=0;x<=times;x++)			//��ʼѭ��,ÿѭ��һ�ν���ȫ������һ��
	{	
		split=getRandInt(20,35);		//���ѡȡsplit��ֵ
		Deck topdeck;					//���������˿��ƶ���
		Deck bottomdeck;
		int i;
		int bottomdeckindex=1;
		int topdeckindex=1;
		for(i=0;i<=split-1;)	/*����ʼ���Ǹ��˿��Ƶ��ϱ߲��ֵ�������ֵ��
								�����ɵ��˿��ƶ�����*/
		{
			topdeck.m_cardarray[topdeckindex]=this->m_cardarray[i];
			topdeckindex++;	
			i++;
		}
		for(i=(split);i<54;)/*ͬ������ʼ�Ǹ��˿��Ƶ��±߲��ֵ�������ֵ��
								�����ɵ��˿��ƶ�����*/
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
			bottomdeckindex=54-split;		//�²����Ǹ��˿��Ƶ�����
		topdeckindex=split;				//�ϲ����Ǹ��˿��Ƶ�����
		while(deckoutindex<=53)
		{
			numcardstomovetop=getRandInt(2,7);//���ϲ��ֳ�ȡ����������2-7֮��������
			numcardstomovebottom=getRandInt(2,7);	//ͬ�����²��ֳ�ȡ������,��2-7֮��������
			for(j=0;j<=numcardstomovebottom;j++)	//��0��ʼѭ��numcardstomovebottom��	
			{
				if(bottomdeckindex>0)				//���²����Ǹ���û��ѭ����ʱ����
				{
					this->m_cardarray[deckoutindex]=bottomdeck.m_cardarray[bottomdeckindex];
					/*���²����Ǹ��Ƶ����������ʼ,�������ʼ���˿��Ƹ�ֵ*/
					deckoutindex++;
					bottomdeckindex--;
				}
				for(h=0;h<=numcardstomovetop;h++)/*�²��ֵ��Ǹ��˿��Ƹ�ֵ��ɺ�,��
												   �ϲ��ֵ��Ǹ�����ͬ���Ĳ���*/
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
	this->m_lastdelt=-1;		//��ɾ���Ƶ�������ԭΪ-1(δɾ��)
}

void prog_close()//������ͣ,�ΰ�һ������
{
	cout<<endl<<endl;
	Get_Key();
	cout<<endl<<endl;
}
Deck::Deck()				//��ʼ��һ���˿���,��54���˿��ƾ�����
{
	int i;
	for(i=0;i<=53;i++)
	{
		m_cardarray[1]=Playing_Card();	//����һ����ʱ����ֵ			
	}
}
