package AnimalAdapter;

public class Client{
    public static void main(String[] args){
        Dog dog=new DogImpl();
        Cat cat=new CatImpl();
        Adapter catAdapter=new Adapter(cat);
        Adapter dogAdapter=new Adapter(dog);
        System.out.print("狗学");
        catAdapter.cry();
        System.out.print("猫学");
        dogAdapter.catchMouse();
    }
}