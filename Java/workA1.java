import java.util.Scanner;

public class workA1 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("请输入学生成绩：");
        int score=sc.nextInt();
        switch(score/10){
            case (9) -> System.out.println("等级A");
            case (8) -> System.out.println("等级B");
            case (7) -> System.out.println("等级C");
            case (6) -> System.out.println("等级D");
            default -> System.out.println("等级E");
        }
        sc.close();
    }
}
