/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

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
