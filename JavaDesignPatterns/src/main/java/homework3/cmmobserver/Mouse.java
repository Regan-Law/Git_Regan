package homework3.cmmobserver;

public class Mouse implements Observer{
    @Override
    public void update(){
        System.out.println("老鼠开始逃跑");
    }
}