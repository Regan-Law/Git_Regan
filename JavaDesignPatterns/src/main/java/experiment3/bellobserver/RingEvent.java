package experiment3.bellobserver;

import java.io.Serial;
import java.util.EventObject;

// 铃声事件类
public class RingEvent extends EventObject{
    @Serial
    private static final long serialVersionUID=1L;
    private boolean sound;

    public RingEvent(Object source,boolean sound){
        super(source);
        this.sound=sound;
    }

    public boolean getSound(){
        return sound;
    }

    public void setSound(boolean sound){
        this.sound=sound;
    }
}