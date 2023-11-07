package homework3.remotecontroliterator;

public interface ChannelCollection{
    void addChannel(Channel c);

    void removeChannel(Channel c);

    ChannelIterator iterator();
}