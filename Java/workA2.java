import java.util.Scanner;

public class workA2{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int sumf=0,nf=1;
        for(int i=0;i<10;i++){
            nf*=i+1;
            sumf+=nf;
        }
        System.out.println("����forѭ������1~10�Ľ׳�Ϊ��"+sumf);
        int sumw=0;
        int x=1,nw=1;
        while(x<11){
            nw*=x;
            x++;
            sumw+=nw;
        }
        System.out.println("����whileѭ������1~10�Ľ׳�Ϊ��"+sumw);
        sc.close();
    }
}
