package experiment1.ebfactory;

public class AimaFactory implements BikeFactory{
    public Bike produce(){
        return new Aima();
    }
}