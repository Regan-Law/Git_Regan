public class DivisionByZero {
    void division(){
        int a=10;
        int b=0;
        try {
            System.out.println(a/b);
        }catch(ArithmeticException e) {
            System.out.println("error");
            e.printStackTrace();
        }finally {
            System.out.println("over");
        }
    }
    void division1() throws ArithmeticException {
		int a=10;
        int b=0;
        System.out.println(a/b);
	}
    public static void main(String[] args) {
        DivisionByZero er= new DivisionByZero();
        er.division();
        try {
            er.division1();
        } catch (ArithmeticException e) {
            System.out.println("error");
        } finally{
            System.out.println("over");
        }
    }
}
