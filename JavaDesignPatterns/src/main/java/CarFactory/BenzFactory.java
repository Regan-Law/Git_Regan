package CarFactory;

public class BenzFactory extends CarFactory{
    public Car manufactureCar(){
        Car car=new BenzCar();
        return car;
    }
}