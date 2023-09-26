package CarFactory;

public abstract class CarFactory extends client{
    public abstract Car manufactureCar();

    public void run(){
        Car car=this.manufactureCar();
        car.run();
    }

}