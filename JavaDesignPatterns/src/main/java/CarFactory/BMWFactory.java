package CarFactory;

public class BMWFactory implements CarFactory{
    public Car manufactureCar(){
        return new BMW();
    }
}