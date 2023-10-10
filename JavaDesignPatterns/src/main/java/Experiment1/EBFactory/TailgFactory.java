package Experiment1.EBFactory;

public class TailgFactory implements BikeFactory{
    public Bike produce(){
        return new Tailg();
    }
}