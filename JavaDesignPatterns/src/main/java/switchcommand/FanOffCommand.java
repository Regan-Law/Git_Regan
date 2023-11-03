package switchcommand;

public class FanOffCommand implements Command{
    private Fan fan;

    public FanOffCommand(Fan fan){
        this.fan=fan;
    }

    @Override
    public void execute(){
        fan.turnOff();
    }
}