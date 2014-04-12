/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

package eventnotifier;

import java.io.IOException;

public class EventNotifierDemo
{

    public static void main(String[] args)
    {
        PagingSystem ps = new PagingSystem();  // My subscriber

        // Add filter for CRITICAL events
        CriticalFaultFilter criticalFilter = new CriticalFaultFilter();
        EventService.instance().subscribe(FaultEvent.class, criticalFilter, ps);

        waitForUserInput("\nSending CRITICAL event.");

        FaultEvent criticalEvent = new FaultEvent(FaultEvent.CRITICAL);
        EventService.instance().publish(criticalEvent);

        waitForUserInput("\nSending LOW event.");

        FaultEvent lowEvent = new FaultEvent(FaultEvent.LOW);
        EventService.instance().publish(lowEvent);  // This will be ignored

        waitForUserInput("\nSending MODERATE event.");

        FaultEvent moderateEvent = new FaultEvent(FaultEvent.MODERATE);
        EventService.instance().publish(moderateEvent);  // This will be ignored

        waitForUserInput("\nAdding filter and sending another MODERATE event.");

        // Add filter for MODERATE events
        ModerateFaultFilter moderateFilter = new ModerateFaultFilter();
        EventService.instance().subscribe(FaultEvent.class, moderateFilter, ps);

        EventService.instance().publish(moderateEvent);
    }

    public static void waitForUserInput(final String message)
    {
        System.out.println(message);
        System.out.println("Press ENTER to continue...");
        try {
            System.in.read();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
