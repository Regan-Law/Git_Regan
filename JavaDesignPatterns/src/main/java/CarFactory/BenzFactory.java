package CarFactory;

public class BenzFactory implements CarFactory{
    public Car manufactureCar(){
        return new BenzCar();
    }
}