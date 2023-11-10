package homework3.cmmobserver;

import java.util.ArrayList;
import java.util.List;

public class Cat{
    private List<Observer> observers=new ArrayList<>();

    public void add(Observer observer){
        observers.add(observer);
    }

    public void meow(){
        System.out.println("猫大叫一声");
        for(Observer observer: observers){
            observer.update();
        }
    }
}