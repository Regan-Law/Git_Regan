package Experiment2.EngineAdapter;

public class Car{
    private EngineAdapter engineAdapter;

    public Car(EngineAdapter engineAdapter){
        this.engineAdapter=engineAdapter;
    }

    public void drive(){
        engineAdapter.drive();
    }
}