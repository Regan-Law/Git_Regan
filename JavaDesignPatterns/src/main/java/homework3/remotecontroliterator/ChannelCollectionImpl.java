package homework3.remotecontroliterator;

import java.util.ArrayList;
import java.util.List;

public class ChannelCollectionImpl implements ChannelCollection{
    private List<Channel> channels=new ArrayList<>();

    @Override
    public void addChannel(Channel c){
        channels.add(c);
    }

    @Override
    public void removeChannel(Channel c){
        channels.remove(c);
    }

    @Override
    public ChannelIterator iterator(){
        return new ChannelIteratorImpl(channels);
    }
}