/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

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
