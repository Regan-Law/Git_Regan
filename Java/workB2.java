/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:46:43
 * @FilePath: \\Git_Regan\\Java\\workB2.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
public class workB2 {
    public static class Person {
        String name;
        int age;
        boolean gender;
        Person partner;

        public Person(String name,int age,boolean gender,Person partner) {
            this.name=name;
            this.age=age;
            this.gender=gender;
            this.partner=partner;
        }
        public void marry(Person p) {
            if(this.gender==p.gender) {
                System.out.println("ͬ�Բ��ܽ��");
                return;
            } else if(this.gender==true&&this.age<24) {
                System.out.println("�з�����С��24 �����ܽ��");
                return;
            } else if(this.gender==false&&this.age<22) {
                System.out.println("Ů������С��22 �����ܽ��");
                return;
            } else if(p.gender==true&&p.age<24) {
                System.out.println("�з�����С��24 �����ܽ��");
                return;
            } else if(p.gender==false&&p.age<22) {
                System.out.println("Ů������С��22 �����ܽ��");
                return;
            } else if(this.partner !=null||p.partner !=null) {
                System.out.println("ĳһ���ѻ飬���ܽ��");
                return;
            } else {
                System.out.println("��ϲ���ɹ�");
                this.partner=p.partner;
                p.partner=this.partner;
                return;
            }
        }
    }
    public static void main(String[] args) {
        Person p1=new Person("����",25,true,null);
        Person p2=new Person("С��",23,false,null);
        Person p3=new Person("����",22,true,null);
        p1.marry(p2);
        p1.marry(p3);
        p2.marry(p3);      
    }
}