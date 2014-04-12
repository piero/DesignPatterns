package eventnotifier;

public class ModerateFaultFilter implements Filter
{
    public boolean apply(Event event)
    {
        // Assumes that this filter is used only with subscriptions to
        // FaultEvent
        FaultEvent faultEvent = (FaultEvent) event;
        return (faultEvent.priority == Event.MODERATE);
    }
}