package experiment3.bellobserver;

public class Client{
    public static void main(String[] args){
        BellEventSource bell=new BellEventSource(); // 铃（事件源）
        bell.addPersonListener(new TeacherEventListener()); // 注册监听器（老师）
        bell.addPersonListener(new StudentEventListener()); // 注册监听器（学生）
        bell.ring(true);
        System.out.println("\n------------------------\n");
        bell.ring(false);
    }
}