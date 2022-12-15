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
        System.out.print("圆的周长：");
        zhouchang();
        System.out.print("圆的面积：");
        area();
    }

    public Circle(double height) {
        System.out.print("自动赋值：");
        this.setHeight(height);
    }
}

class Rect extends Shape {
    public void zhouchang() {
        System.out.println("周长为：" + (double) 2 * this.getdLong() + (double) 2 * this.getWidth());
    }

    public void area() {
        System.out.println("面积为：" + this.getdLong() * this.getWidth());
    }

    public void cha() {
        double result = this.getdLong() - this.getWidth();
        String shape = "长为" + this.getdLong() + "宽为" + this.getWidth();
        String str;
        if (result > 0) {
            str = ",此图形为长方形。";
        } else {
            str = ",长等于宽，此图形为正方形。";
        }
        System.out.println(shape + str);
    }

    public Rect(double dlong, double width) {
        System.out.print("自动赋值：");
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