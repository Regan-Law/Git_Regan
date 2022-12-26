public class workB1{
    public static void main(String[] args)
    {
        TeacherTest tt=new TeacherTest();
        tt.info();
        tt.salary();
    }
    public static class Teacher{
        String name;
        String sex;
        int age;
        double salary;
        public Teacher(String name,String sex,int age,double salary){
            this.name=name;
            this.sex=sex;
            this.age=age;
            this.salary=salary;
        }
        public void add(){
            salary+=5000;
        }
    }
    public static class TeacherTest{
        Teacher t=new Teacher("蒋平","男",33,3500);
        public void info(){
            System.out.println("姓名："+t.name+" 性别："+t.sex+" 年龄："+t.age);
        }
        public void salary(){
            t.add();
            System.out.println("教师涨薪后的薪水为："+t.salary);
        }
    }
}
