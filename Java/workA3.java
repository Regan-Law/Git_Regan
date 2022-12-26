import java.util.Scanner;

public class workA3{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入金字塔的层数");
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
		{          
			for(int j=i;j<n;j++){
				System.out.print(" ");
            }
			for(int k=0;k<2*i-1;k++){
				System.out.print("*");
            }
			System.out.print("\n");
        }
        sc.close();
    }
}