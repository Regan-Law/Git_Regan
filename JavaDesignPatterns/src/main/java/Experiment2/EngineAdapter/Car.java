package Experiment2.EngineAdapter;

import org.w3c.dom.Document;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;

public class Car{
    private EngineAdapter engineAdapter;

    public Car(String configFile){
        try{
            DocumentBuilderFactory factory=DocumentBuilderFactory.newInstance();
            DocumentBuilder builder=factory.newDocumentBuilder();
            Document document=builder.parse(new File(configFile));

            String adapterClass=document.getElementsByTagName("class").item(0).getTextContent();
            String engineClass=document.getElementsByTagName("class").item(1).getTextContent();

            Engine engine=(Engine)Class.forName(engineClass).getDeclaredConstructor().newInstance();
            engineAdapter=(EngineAdapter)Class.forName(adapterClass).getDeclaredConstructor(Engine.class).newInstance(engine);
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public void drive(){
        engineAdapter.drive();
    }
}