package experiment3.bellobserver;

// 具体观察者类
public class StudentEventListener implements BellEventListener{
    public void heardBell(RingEvent event){
        if(event.getSound()){
            System.out.println("同学们上课了...");
        }else{
            System.out.println("同学们下课了...");
        }
    }
}