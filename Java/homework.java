import java.util.Scanner;

public class homework {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int fn=fib(n);
        System.out.println("쳲��������еĵ�"+n+"����Ϊ:"+fn);
        sc.close();
    }

    public static int fib(int n) {
        int fn=0;
        if(n==1||n==2) {
            fn=1;
        } else {
            fn=fib(n-1)+fib(n-2);
        }
        return fn;
    }
}
