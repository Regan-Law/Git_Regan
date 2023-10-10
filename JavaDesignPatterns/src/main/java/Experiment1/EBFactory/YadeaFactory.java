package Experiment1.EBFactory;

public class YadeaFactory implements BikeFactory{
    public Bike produce(){
        return new Yadea();
    }
}