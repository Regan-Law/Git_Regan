#include<iostream>
using namespace std;
class HString{
   private:
     char *ch;// *elem 
     int length;  //listsize length
   public:
     HString(){ch=NULL;length=0;}              //创建空串
    
     void StrAssign(HString &s,char *str);         //串赋值
     void StrCopy(HString &s,HString t);          //把串t拷贝给私有成员s
     int StrLength(HString s){return s.length;}              //返回串的长度；
     int StrCompare(HString s,HString t);  //串的比较，若s==t，则返回0；若s>t，则返回值>0；否则返回值<0;
     void StrConcat(HString &s,HString s1,HString s2); //两个串s1和s2的连接；
     void SubString(HString &sub,HString s,int pos, int len); //用sub返回串s中第pos个字符开始长度为len的子串；
     void StrInsert(HString &s,int pos,HString t);   //在串s的第pos个字符前插入串t;
     void StrDelete(HString &s,int pos,int len);   //删除串s中第pos个字符开始长度为len的子串;
     void StrReplace(HString &s,int pos,int len,HString t); //将s中第pos字符开始的len个字符子串用串t替换；
     void LongestSameStr(HString s,int &pos,int &max);
 // 计算 s 中出现的第一个最长的连续相同字符的开始位置和最大的相同字符串长度。
     void print(HString s){
          for(int i=0;i<s.length;i++)
             cout<<s.ch[i];
           cout<<endl;
      }   
};
                                                          
void HString::StrAssign(HString &s,char *str){         
   char *c=str;                                                     
   int i;                                                      
   for(i=0;*c!='\0';c++)          //求str的长度
       i++;
   if(!i){                         //str为空串
       s.ch=NULL;
       s.length=0;
         
   }
   else{                         //str为非空串
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
   if(!len){                        //空子串        
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
   if(pos<1||pos>s.length+1)    //参数不正确，无法插入
      return;
   char *ch=new char[s.length+t.length];
   for(i=0;i<pos-1;i++)        //将s.ch[0..pos-2]复制到ch
     ch[i]=s.ch[i];
   for(i=0;i<t.length;i++)      //将t[0..t.length-1]复制到ch
     ch[i+pos-1]=t.ch[i];
   for(i=pos-1;i<s.length;i++)  //将s[pos-1..s.length-1]复制到ch
     ch[t.length+i]=s.ch[i];
   delete []s.ch;                                             
   s.ch=ch;                                                            
   s.length+=t.length;                                                   
}                                                                                    

void HString::StrDelete(HString &s,int pos,int len){
   int i;
   if(pos<1||pos>s.length||i+pos>s.length+1)  //参数不正确，无法删除
      return;
   char *ch=new char[s.length-len];
   for(i=0;i<pos-1;i++)                   //将s.ch[0..pos-2]复制到ch
     ch[i]=s.ch[i];
   for(i=pos+len-1;i< s. length;i++)          //将s.ch[pos+len-1..s.length-1]复制到ch
     ch[i-len]=s.ch[i];
   delete []s.ch;                                         
   s.ch=ch;                                  
   s.length-=len;                                              
}                                                                 

void HString::StrReplace(HString &s,int pos,int len,HString t){
   int i;
   if(pos<1||pos>s.length||pos+len-1>s.length)    //参数不正确，不作操作
      return;
   char *ch=new char[s.length-len+t.length];
   for(i=0;i<pos-1;i++)                      //将s.ch[0..pos-2]复制到ch
      ch[i]=s.ch[i];
   for(i=0;i<t.length;i++)                    //将t.ch[0..t.length-1] 复制到ch
      ch[pos+i-1]=t.ch[i];
   for(i=pos+len-1;i<s.length;i++)            //将s.ch[pos+len-1..s.length-1] 复制到ch
      ch[t.length+i-len]=s.ch[i];
   delete []s.ch;
   s.ch=ch;
   s.length= s.length-len+t.length;
}
void  HString:: LongestSameStr(HString s,int &pos,int &max){ 
//pos为所查找字符串的开始位置，max为最大长度
   int len=1,i=0,start=0;
   pos=0;max=0;
   while(i<s.length-1)
     if(s.ch[i]==s.ch[i+1]){
        len++;
        i++;
     }
     else{                      //上一个字符串查找结束
        if(max<len){            //当前所查字符串长度大，更新max
            max=len;
            pos=start;
        }
     i++;                       //初始化查找下一个字符串的位置和长度
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

