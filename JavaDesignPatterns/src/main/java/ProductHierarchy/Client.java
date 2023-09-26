package ProductHierarchy;

public class Client{
    public static void main(String[] args){
        AbstractFactory factory=new WindowsFactory();
        Button button=factory.createButton();
        Text text=factory.createText();
        button.print();
        text.print();
    }
}