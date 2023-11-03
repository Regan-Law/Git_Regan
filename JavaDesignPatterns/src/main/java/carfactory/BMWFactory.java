package carfactory;

public class BMWFactory implements CarFactory{
    public Car manufactureCar(){
        return new BMW();
    }
}