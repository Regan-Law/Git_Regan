package homework3.cmmobserver;

public class Master implements Observer{
    @Override
    public void update(){
        System.out.println("主人被惊醒");
    }
}