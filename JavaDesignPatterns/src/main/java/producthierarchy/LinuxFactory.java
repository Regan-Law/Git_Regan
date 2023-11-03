package producthierarchy;

public class LinuxFactory implements AbstractFactory{
    public Button createButton(){
        return new LinuxButton();
    }

    public Text createText(){
        return new LinuxText();
    }
}