package Experiment2.EngineAdapter;

public class client{
    public static void main(String[] args){
        Engine electricEngine=new ElectricEngine();
        EngineAdapter electricEngineAdapter=new EngineAdapter(electricEngine);
        Car electricCar=new Car(electricEngineAdapter);
        electricCar.drive();

        Engine solarEngine=new SolarEngine();
        EngineAdapter solarEngineAdapter=new EngineAdapter(solarEngine);
        Car solarCar=new Car(solarEngineAdapter);
        solarCar.drive();
    }
}