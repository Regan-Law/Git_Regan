package ProductHierarchy;

public class UNIXFactory implements AbstractFactory{
    public Button createButton(){
        return new UNIXButton();
    }

    public Text createText(){
        return new UNIXText();
    }
}