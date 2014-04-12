package eventnotifier;

public class FaultEvent extends Event
{

    public FaultEvent()
    {
        super(Event.LOW);
    }

    public FaultEvent(int aPriority)
    {
        super(aPriority);
    }
}
