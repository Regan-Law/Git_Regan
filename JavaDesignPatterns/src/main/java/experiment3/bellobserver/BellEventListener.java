package experiment3.bellobserver;

import java.util.EventListener;

// 抽象观察者类
public interface BellEventListener extends EventListener{
    public void heardBell(RingEvent event);
}