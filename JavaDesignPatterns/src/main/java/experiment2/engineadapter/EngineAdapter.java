package experiment2.engineadapter;

public class EngineAdapter implements Engine{
    private Engine engine;

    public EngineAdapter(Engine engine){
        this.engine=engine;
    }

    public void drive(){
        engine.drive();
    }
}