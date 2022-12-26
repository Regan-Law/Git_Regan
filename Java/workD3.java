/*
 * @Author: ReganLaw 609607745@qq.com
 * @Date: 2022-12-15 13:19:52
 * @LastEditors: ReganLaw 609607745@qq.com
 * @LastEditTime: 2022-12-26 18:48:28
 * @FilePath: \\Git_Regan\\Java\\workD3.java
 * @Description: 
 * 
 * Copyright (c) 2022 by ReganLaw 609607745@qq.com, All Rights Reserved. 
 */
class Train implements Transport {
    public double calculation(double weight, double mile) {
        double cost;
        if (mile <= 900) {
            cost = weight * mile * 250;
        } else {
            cost = weight * mile * 300;
        }
        return cost;
    }
}

class Truck implements Transport {
    public double calculation(double weight, double mile) {
        if (mile > 1000 || weight > 60) {
            return -1.0;
        } else {
            double cost = weight * mile * 120;
            return cost;
        }
    }

}

interface Transport {
    final int PLANE = 1;
    final int TRAIN = 2;
    final int TRUCK = 3;

    double calculation(double weight, double mile);
}

class Plane implements Transport {
    public double calculation(double weight, double mile) {
        if (mile > 500) {
            double cost = weight * mile * 750;
            return cost;
        } else {
            return -1.0;
        }
    }
}

public class workD3 {
    public static void main(String[] args) {
        Transport transport = new Plane();
        System.out.println("飞机运费\t" + transport.calculation(20, 700));
        transport = new Train();
        System.out.println("火车运费\t" + transport.calculation(20, 700));
        transport = new Truck();
        System.out.println("货车运费\t" + transport.calculation(20, 700));
    }
}