package experiment1.ebfactory;

public class client{
    public static void main(String[] args){
        BikeFactory aimaFactory=new AimaFactory();
        Bike aimabike=aimaFactory.produce();
        aimabike.show();

        BikeFactory yadeaFactory=new YadeaFactory();
        Bike yadeabike=yadeaFactory.produce();
        yadeabike.show();

        BikeFactory tailgFactory=new TailgFactory();
        Bike tailgbike=tailgFactory.produce();
        tailgbike.show();

    }
}