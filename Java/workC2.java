/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:47:32
 * @FilePath: \\Git_Regan\\Java\\workC2.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
import java.util.Arrays;

public class workC2{
    public static void main(String[] args)
    {
        arrayreserve array=new arrayreserve();
        int[] a={1,2,3,4,5,6,7,8,9};
        array.reserve(a);
        System.out.println(Arrays.toString(a));
    }
    public static class arrayreserve{
        public int[] reserve(int a[]){
            int length=a.length;
            for(int i=0;i<length/2;i++){
                int temp=a[i];
                a[i]=a[length-i-1];
                a[length-i-1]=temp;
            }
            return a;
        }
    }
}