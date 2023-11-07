package experiment3.bellobserver;

import java.util.ArrayList;
import java.util.List;

// 目标类
public class BellEventSource{
    private List<BellEventListener> listeners=new ArrayList<>();

    public void addPersonListener(BellEventListener listener){
        listeners.add(listener);
    }

    public void ring(boolean sound){
        String type=sound ? "上课铃" : "下课铃";
        System.out.println(type+"响！");
        RingEvent event=new RingEvent(this,sound);
        notifies(event);
    }

    protected void notifies(RingEvent event){
        BellEventListener listener;
        for(BellEventListener bellEventListener: listeners){
            listener=bellEventListener;
            listener.heardBell(event);
        }
    }
}