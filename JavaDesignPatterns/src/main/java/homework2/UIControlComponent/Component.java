package UIControlComponent;

public abstract class Component{
    public void add(Component c){
        throw new UnsupportedOperationException();
    }

    public void remove(Component c){
        throw new UnsupportedOperationException();
    }

    public Component getChild(int index){
        throw new UnsupportedOperationException();
    }

    public abstract void display();
}