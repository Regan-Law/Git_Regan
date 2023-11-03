package experiment2.engineadapter;

public class client{
    public static void main(String[] args){
        Car car=new Car("./src/main/java/Experiment2/EngineAdapter/adapter-config.xml");
        car.drive();
    }
}