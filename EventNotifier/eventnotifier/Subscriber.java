package eventnotifier;

public abstract class Subscriber
{

    public Subscriber(String id)
    {
        name = id;
    }

    public String getName()
    {
        return name;
    }

    abstract void inform(Event event);

    String name;
}
