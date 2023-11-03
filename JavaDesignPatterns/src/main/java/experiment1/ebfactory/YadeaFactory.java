package experiment1.ebfactory;

public class YadeaFactory implements BikeFactory{
    public Bike produce(){
        return new Yadea();
    }
}