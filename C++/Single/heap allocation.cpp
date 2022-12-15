#include<iostream>
using namespace std;
class HString{
   private:
     char *ch;// *elem 
     int length;  //listsize length
   public:
     HString(){ch=NULL;length=0;}              //�����մ�
    
     void StrAssign(HString &s,char *str);         //����ֵ
     void StrCopy(HString &s,HString t);          //�Ѵ�t������˽�г�Աs
     int StrLength(HString s){return s.length;}              //���ش��ĳ��ȣ�
     int StrCompare(HString s,HString t);  //���ıȽϣ���s==t���򷵻�0����s>t���򷵻�ֵ>0�����򷵻�ֵ<0;
     void StrConcat(HString &s,HString s1,HString s2); //������s1��s2�����ӣ�
     void SubString(HString &sub,HString s,int pos, int len); //��sub���ش�s�е�pos���ַ���ʼ����Ϊlen���Ӵ���
     void StrInsert(HString &s,int pos,HString t);   //�ڴ�s�ĵ�pos���ַ�ǰ���봮t;
     void StrDelete(HString &s,int pos,int len);   //ɾ����s�е�pos���ַ���ʼ����Ϊlen���Ӵ�;
     void StrReplace(HString &s,int pos,int len,HString t); //��s�е�pos�ַ���ʼ��len���ַ��Ӵ��ô�t�滻��
     void LongestSameStr(HString s,int &pos,int &max);
 // ���� s �г��ֵĵ�һ�����������ͬ�ַ��Ŀ�ʼλ�ú�������ͬ�ַ������ȡ�
     void print(HString s){
          for(int i=0;i<s.length;i++)
             cout<<s.ch[i];
           cout<<endl;
      }   
};
                                                          
void HString::StrAssign(HString &s,char *str){         
   char *c=str;                                                     
   int i;                                                      
   for(i=0;*c!='\0';c++)          //��str�ĳ���
       i++;
   if(!i){                         //strΪ�մ�
       s.ch=NULL;
       s.length=0;
         
   }
   else{                         //strΪ�ǿմ�
       s.ch=new char[i];
       for(int j=0;j<i;j++)
         s.ch[j]=str[j];
       s.length=i;                                       
   }                                                 
}                                                       
 
void HString::StrCopy(HString &s,HString t){        
  s.ch=new char[t.length];                          
  for(int i=0;i<t.length;i++)
     s.ch[i]=t.ch[i];
  s.length=t.length;
}                                                            
  
int HString::StrCompare(HString s,HString t){                        
  for(int i=0;i<s.length&&i<t.length;i++)                       
     if(s.ch[i]!=t. ch[i]) return s.ch[i]-t.ch[i];     
  return s.length-t.length;

}

void HString::StrConcat(HString &s,HString s1,HString s2){
  s.ch=new char[s1.length+s2.length];           
  s.length=s1.length+s2.length;                                 
  int i;                                                 
  for( i=0;i<s1.length;i++)                      
    s.ch[i]=s1.ch[i];                             
  for(i=0;i<s2.length;i++)
    s.ch[i+s1.length]=s2.ch[i];
}

void HString::SubString(HString &sub,HString s,int pos, int len){
   if(pos<1||pos>s.length||len<0||len>s.length-pos+1) return;
   if(!len){                        //���Ӵ�        
      sub.ch=NULL;                                                  
      sub.length=0;                             
	  return;                                                         
   }                                                 
   sub.ch=new char[len];                        
   for(int i=0;i<len;i++)
      sub.ch[i]=s.ch[pos+i-1];             
   sub.length=len;                    
}                                     
                                        
void HString::StrInsert(HString &s,int pos,HString t){
   int i;
   if(pos<1||pos>s.length+1)    //��������ȷ���޷�����
      return;
   char *ch=new char[s.length+t.length];
   for(i=0;i<pos-1;i++)        //��s.ch[0..pos-2]���Ƶ�ch
     ch[i]=s.ch[i];
   for(i=0;i<t.length;i++)      //��t[0..t.length-1]���Ƶ�ch
     ch[i+pos-1]=t.ch[i];
   for(i=pos-1;i<s.length;i++)  //��s[pos-1..s.length-1]���Ƶ�ch
     ch[t.length+i]=s.ch[i];
   delete []s.ch;                                             
   s.ch=ch;                                                            
   s.length+=t.length;                                                   
}                                                                                    

void HString::StrDelete(HString &s,int pos,int len){
   int i;
   if(pos<1||pos>s.length||i+pos>s.length+1)  //��������ȷ���޷�ɾ��
      return;
   char *ch=new char[s.length-len];
   for(i=0;i<pos-1;i++)                   //��s.ch[0..pos-2]���Ƶ�ch
     ch[i]=s.ch[i];
   for(i=pos+len-1;i< s. length;i++)          //��s.ch[pos+len-1..s.length-1]���Ƶ�ch
     ch[i-len]=s.ch[i];
   delete []s.ch;                                         
   s.ch=ch;                                  
   s.length-=len;                                              
}                                                                 

void HString::StrReplace(HString &s,int pos,int len,HString t){
   int i;
   if(pos<1||pos>s.length||pos+len-1>s.length)    //��������ȷ����������
      return;
   char *ch=new char[s.length-len+t.length];
   for(i=0;i<pos-1;i++)                      //��s.ch[0..pos-2]���Ƶ�ch
      ch[i]=s.ch[i];
   for(i=0;i<t.length;i++)                    //��t.ch[0..t.length-1] ���Ƶ�ch
      ch[pos+i-1]=t.ch[i];
   for(i=pos+len-1;i<s.length;i++)            //��s.ch[pos+len-1..s.length-1] ���Ƶ�ch
      ch[t.length+i-len]=s.ch[i];
   delete []s.ch;
   s.ch=ch;
   s.length= s.length-len+t.length;
}
void  HString:: LongestSameStr(HString s,int &pos,int &max){ 
//posΪ�������ַ����Ŀ�ʼλ�ã�maxΪ��󳤶�
   int len=1,i=0,start=0;
   pos=0;max=0;
   while(i<s.length-1)
     if(s.ch[i]==s.ch[i+1]){
        len++;
        i++;
     }
     else{                      //��һ���ַ������ҽ���
        if(max<len){            //��ǰ�����ַ������ȴ󣬸���max
            max=len;
            pos=start;
        }
     i++;                       //��ʼ��������һ���ַ�����λ�úͳ���
     start=i;
     len=1;
  }  
}

int main( ){
   HString ss,st,sw;
   char *ch=new char[255];
   cin>>ch; 
   ss.StrAssign(ss,ch);
   st.StrCopy(st,ss);
   cout<<ss.StrCompare(ss,st)<<endl;
   st.StrInsert(ss,3,st);
   ss.print(ss);
   sw.StrConcat (sw,ss,st);
   ss.print(sw);
   sw.SubString(sw,ss,4,4);
   ss.print(sw);
   sw.StrDelete(ss,4,3);
   ss.print(ss);
   sw.StrReplace(ss,2,3,st);
   ss.print(ss);
   int max,pos;
   sw.LongestSameStr(ss,pos,max);
   cout<<max<<' '<<pos;
   return 0;
}

