import java.util.Scanner;

public class workA1 {
    public static void main(String args[]) {
        Scanner sc=new Scanner(System.in);
        System.out.println("������ѧ���ɼ���");
        int score=sc.nextInt();
        switch(score/10) {
            case(9):
                System.out.println("�ȼ�A");
                break;
            case(8):
                System.out.println("�ȼ�B");
                break;
            case(7):
                System.out.println("�ȼ�C");
                break;
            case(6):
                System.out.println("�ȼ�D");
                break;
            default:
                System.out.println("�ȼ�E");
                break;
        }
;
        sc.close();
    }
}
