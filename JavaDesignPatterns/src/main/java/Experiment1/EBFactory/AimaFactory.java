package Experiment1.EBFactory;

public class AimaFactory implements BikeFactory{
    public Bike produce(){
        return new Aima();
    }
}