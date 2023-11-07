package homework3.remotecontroliterator;

import java.util.List;

public class ChannelIteratorImpl implements ChannelIterator{
    private List<Channel> channels;
    private int position=0;

    public ChannelIteratorImpl(List<Channel> channels){
        this.channels=channels;
    }

    @Override
    public boolean hasNext(){
        return position<channels.size();
    }

    @Override
    public Channel next(){
        Channel channel=channels.get(position);
        position++;
        return channel;
    }
}