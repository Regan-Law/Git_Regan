package AnimalAdapter;

public class Adapter implements Cat, Dog{
    private Cat cat;
    private Dog dog;

    public Adapter(Cat cat){
        this.cat=cat;
    }

    public Adapter(Dog dog){
        this.dog=dog;
    }

    public void cry(){
        cat.catchMouse();
    }

    public void catchMouse(){
        dog.cry();
    }
}