package UIControlComponent;

import java.util.ArrayList;

public class Container extends Component{
    private final String name;

    private final ArrayList<Component> componentList=new ArrayList<>();

    public Container(String name){
        this.name=name;
    }

    public void add(Component component){
        this.componentList.add(component);
    }

    public void remove(Component component){
        this.componentList.remove(component);
    }

    public Component getChild(int i){
        return this.componentList.get(i);
    }

    public void display(){
        for(Component component: this.componentList){
            component.display();
        }
    }
}