/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:50:50
 * @FilePath: \\Git_Regan\\Java\\workA3.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
import java.util.Scanner;

public class workA3{
    public static void main(String[] args)
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