package experiment3.bellobserver;

// 具体观察者类
public class TeacherEventListener implements BellEventListener{
    public void heardBell(RingEvent event){
        if(event.getSound()){
            System.out.println("老师上课了...");
        }else{
            System.out.println("老师下课了...");
        }
    }
}