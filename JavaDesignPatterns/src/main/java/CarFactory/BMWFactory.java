package CarFactory;

public class BMWFactory extends CarFactory{
    public Car manufactureCar(){
        Car car=new BMW();
        return car;
    }
}