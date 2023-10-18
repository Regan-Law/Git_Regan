package UIControlComponent;

public class Button extends Component{
    private final String name;

    public Button(String name){
        this.name=name;
    }

    public void add(Component component){
    }

    public void remove(Component component){
    }

    public Component getChild(int i){
        return null;
    }

    public void display(){
        System.out.println("按钮显示："+this.name);
    }
}