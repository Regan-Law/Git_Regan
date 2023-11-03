package switchcommand;

public class Client{
    public static void main(String[] args){
        Light light=new Light();
        Fan fan=new Fan();

        Command lightOnCommand=new LightOnCommand(light);
        Command lightOffCommand=new LightOffCommand(light);
        Command fanOnCommand=new FanOnCommand(fan);
        Command fanOffCommand=new FanOffCommand(fan);

        RemoteControl remoteControl=new RemoteControl();

        remoteControl.setCommand(lightOnCommand);
        remoteControl.pressButton(); // Light is on

        remoteControl.setCommand(fanOnCommand);
        remoteControl.pressButton(); // Fan is on

        remoteControl.setCommand(lightOffCommand);
        remoteControl.pressButton(); // Light is off

        remoteControl.setCommand(fanOffCommand);
        remoteControl.pressButton(); // Fan is off
    }
}