public class workB3{
    public static class Animal{
        private String name;
        private int legs;
        public Animal(){
            this.name="AAA";
            this.legs=4;
        }
        public Animal(String name,int legs){
            this.name=name;
            this.legs=legs;
        }
        public void move(){
            System.out.println(name+" Moving!!\n");
        }
        public void move(int n){
            while(n>0){
                System.out.println(name+" Moving!!");
                n--;
            }
        }
    }
    public static void main(String[] args)
    {
        Animal a = new Animal();
        a.move();
        a.move(5);
        System.out.println("\n");
        Animal b=new Animal("BBB",8);
        b.move();
        b.move(3);
    }
}