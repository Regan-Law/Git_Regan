abstract class Animal {
    public int legs;

    public Animal(int legs) {
        this.legs = legs;
    }

    public void walk() {
        System.out.println("this animal is walking");
    }

    public void eat() {
        System.out.println("eat");
    }
}

class Spider extends Animal implements Pet {
    private String name;

    public void Spiders(String name) {
        this.name = name;
    }

    public Spider(int legs) {
        super(legs);
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void play() {
        System.out.println("Spider is playing");
    }

    public void eat() {
        System.out.println("Spider is eatting");
    }
}

interface Pet {
    void setName(String name);

    String getName();

    static void play() {
        System.out.println(" is playing");
    }
}

class Cat extends Animal implements Pet{
	public Cat(int legs) {
		super(legs);
	}
	public void Cats() {
		
	}
	private String name;
	public void cat(String name) {
		this.name=name;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name ) {
		this.name=name;
	}
	public void play() {
		System.out.println("cat is playing ");
	}
	public void eat() {
		System.out.println("cat is eatting");
	}
 
}
class Fish extends Animal implements Pet{
	private String name;
	public void Fishs(String name) {
		this.name=name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getName() {
		return name;
	}
	public Fish(int legs) {
		super(legs);
	}
	public void eat() {
		System.out.println("Fish is eatting");
	}
	public void walk() {
		System.out.println("Fish is walking");
	}
}
public class workD1 {
    public static void main(String args[]) {
        Animal a;
		a=new Spider(8);
		a.walk();
		a.eat();
		a=new Cat(4);
		a.walk();
		a.eat();
		Pet p;
		p=new Fish(9);
		p.setName("fish");
		System.out.print(p.getName());
		Pet.play();
    }
}