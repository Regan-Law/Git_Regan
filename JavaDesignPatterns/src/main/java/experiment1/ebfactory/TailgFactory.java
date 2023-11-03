package experiment1.ebfactory;

public class TailgFactory implements BikeFactory{
    public Bike produce(){
        return new Tailg();
    }
}