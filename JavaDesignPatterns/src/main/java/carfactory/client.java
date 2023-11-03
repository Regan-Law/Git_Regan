package carfactory;

public class client{
    public static void main(String[] args){
        CarFactory bmwFactory=new BMWFactory();
        Car bmwCar=bmwFactory.manufactureCar();
        bmwCar.run();

        CarFactory benzFactory=new BenzFactory();
        Car benzCar=benzFactory.manufactureCar();
        benzCar.run();
    }
}