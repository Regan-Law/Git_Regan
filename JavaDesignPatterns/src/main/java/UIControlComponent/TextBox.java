package UIControlComponent;

public class TextBox extends Component{
    private String name;

    public TextBox(String name){
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
        System.out.println("文本框显示："+this.name);

    }

}