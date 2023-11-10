package homework3.cmmobserver;

public class Client{
    public static void main(String[] args){
        Cat cat=new Cat();
        Mouse mouse=new Mouse();
        Master master=new Master();
        cat.add(mouse);
        cat.add(master);
        cat.meow();
    }
}