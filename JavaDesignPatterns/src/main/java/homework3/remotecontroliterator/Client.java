package homework3.remotecontroliterator;

public class Client{
    public static void main(String[] args){
        ChannelCollection channels=new ChannelCollectionImpl();
        channels.addChannel(new Channel("CCTV-1"));
        channels.addChannel(new Channel("CCTV-2"));
        channels.addChannel(new Channel("CCTV-3"));
        channels.addChannel(new Channel("CCTV-4"));
        channels.addChannel(new Channel("CCTV-5"));

        ChannelIterator iterator=channels.iterator();

        while(iterator.hasNext()){
            Channel channel=iterator.next();
            System.out.println(channel.getName());
        }
    }
}