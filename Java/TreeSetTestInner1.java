/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:45:37
 * @FilePath: \\Git_Regan\\Java\\TreeSetTestInner1.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
import java.util.*;

public class TreeSetTestInner1 {
    public static void main(String[] args) {
        TreeSet<String>s=new TreeSet<String>(new MyComparatorup());
        TreeSet<String>sr=new TreeSet<String>(new MyComparatordown());
        s.add("HashSet");
        s.add("ArrayList");
        s.add("TreeMap");
        s.add("HashMap");
        s.add("TreeSet");
        s.add("LinkedList");

        sr.add("HashSet");
        sr.add("ArrayList");
        sr.add("TreeMap");
        sr.add("HashMap");
        sr.add("TreeSet");
        sr.add("LinkedList");
        System.out.println("ÉýÐò:");
        Iterator<String>it=s.iterator();
        while(it.hasNext()) {
            System.out.println(it.next());
        }
        System.out.println("½µÐò:");
        Iterator<String>itersr=sr.iterator();
        while(itersr.hasNext()) {
            System.out.println(itersr.next());
        }
    }
    static class MyComparatorup implements Comparator<String>{

        public int compare(String o1,String o2) {
            return o1.compareTo(o2);
        }
    }
    static class MyComparatordown implements Comparator<String>{

        public int compare(String o1,String o2) {
            return o2.compareTo(o1);
        }
    }
}
