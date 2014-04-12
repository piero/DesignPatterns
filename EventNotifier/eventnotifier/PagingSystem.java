/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

package eventnotifier;

public class PagingSystem extends Subscriber
{
    public PagingSystem()
    {
        super("PagingSystem");
    }

    @Override
    public void inform(Event event)
    {
        // Assumes that this subscriber has only subscribed to FaultEvent
        FaultEvent faultEvent = (FaultEvent) event;

        // Respond to the event
        System.out.println("[Paging System] Fault Event occurred (" + faultEvent.priority + ")");
    }
}
