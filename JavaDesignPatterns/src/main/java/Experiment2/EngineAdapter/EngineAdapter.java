package Experiment2.EngineAdapter;

public class EngineAdapter implements Engine{
    private Engine engine;

    public EngineAdapter(Engine engine){
        this.engine=engine;
    }

    public void drive(){
        engine.drive();
    }
}