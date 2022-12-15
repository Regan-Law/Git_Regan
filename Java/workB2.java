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
                System.out.println("同性不能结婚");
                return;
            } else if(this.gender==true&&this.age<24) {
                System.out.println("男方年龄小于24 ，不能结婚");
                return;
            } else if(this.gender==false&&this.age<22) {
                System.out.println("女方年龄小于22 ，不能结婚");
                return;
            } else if(p.gender==true&&p.age<24) {
                System.out.println("男方年龄小于24 ，不能结婚");
                return;
            } else if(p.gender==false&&p.age<22) {
                System.out.println("女方年龄小于22 ，不能结婚");
                return;
            } else if(this.partner !=null||p.partner !=null) {
                System.out.println("某一方已婚，不能结婚");
                return;
            } else {
                System.out.println("恭喜结婚成功");
                this.partner=p.partner;
                p.partner=this.partner;
                return;
            }
        }
    }
    public static void main(String args[]) {
        Person p1=new Person("张三",25,true,null);
        Person p2=new Person("小红",23,false,null);
        Person p3=new Person("李四",22,true,null);
        p1.marry(p2);
        p1.marry(p3);
        p2.marry(p3);      
    }
}