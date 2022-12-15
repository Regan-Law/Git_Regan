//public class workB4{
//    public static class Animal{
//        private String name;
//        private int legs;
//        public Animal(){
//            this.name="AAA";
//            this.legs=4;
//        }
//        public Animal(String name,int legs){
//            this.name=name;
//            this.legs=legs;
//        }
//        public void move(){
//            System.out.println(name+" Moving!!\n");
//        }
//        public void move(int n){
//            while(n>0){
//                System.out.println(name+" Moving!!");
//                n--;
//            }
//        }
//    }
//    public static class Fish extends Animal{
//        private String name;
//        private int legs;
//        public Fish(String name){
//            this.name=name;
//            this.legs=0;
//        }
//        public void move(){
//            System.out.println(name+"Swimming!!");
//        }
//    }
//    public static void main(String args[])
//    {
//        Fish f=new Fish("ÈýÎÄÓã");
//        f.move();
//    }
//}