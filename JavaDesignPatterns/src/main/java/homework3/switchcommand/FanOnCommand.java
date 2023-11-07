package homework3.switchcommand;

public class FanOnCommand implements Command{
    private Fan fan;

    public FanOnCommand(Fan fan){
        this.fan=fan;
    }

    @Override
    public void execute(){
        fan.turnOn();
    }
}