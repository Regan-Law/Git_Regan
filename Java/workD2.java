abstract class Shape {

    public abstract void zhouchang();

    public abstract void area();

    private double dLong = 0;
    private double width = 0;
    private double height = 0;

    public double getdLong() {
        return dLong;
    }

    public void setdLong(double dLong) {
        this.dLong = dLong;
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

}

class Circle extends Shape {
    static double IP = 3.14;

    public void zhouchang() {
        System.out.println(2 * IP * this.getHeight());
    }

    public void area() {
        System.out.println(IP * IP * this.getHeight());
    }

    public void cha() {
        System.out.print("Բ���ܳ���");
        zhouchang();
        System.out.print("Բ�������");
        area();
    }

    public Circle(double height) {
        System.out.print("�Զ���ֵ��");
        this.setHeight(height);
    }
}

class Rect extends Shape {
    public void zhouchang() {
        System.out.println("�ܳ�Ϊ��" + (double) 2 * this.getdLong() + (double) 2 * this.getWidth());
    }

    public void area() {
        System.out.println("���Ϊ��" + this.getdLong() * this.getWidth());
    }

    public void cha() {
        double result = this.getdLong() - this.getWidth();
        String shape = "��Ϊ" + this.getdLong() + "��Ϊ" + this.getWidth();
        String str;
        if (result > 0) {
            str = ",��ͼ��Ϊ�����Ρ�";
        } else {
            str = ",�����ڿ���ͼ��Ϊ�����Ρ�";
        }
        System.out.println(shape + str);
    }

    public Rect(double dlong, double width) {
        System.out.print("�Զ���ֵ��");
        this.setdLong(dlong);
        this.setWidth(width);
    }
}

class Squ extends Rect {
    public Squ(double dlong, double width) {
        super(dlong, width);
    }
}

public class workD2 {
    public static void main(String args[]) {
        Rect rect = new Rect(20, 20);
        rect.cha();

        Circle circle = new Circle(15);
        circle.cha();

    }
}