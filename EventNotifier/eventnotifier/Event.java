/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

package eventnotifier;

public abstract class Event
{

    public static final int LOW = 1;
    public static final int MODERATE = 2;
    public static final int CRITICAL = 3;
    public int priority;

    Event()
    {
        priority = LOW;
    }

    Event(int aPriority)
    {
        if (aPriority < LOW) {
            priority = LOW;
        }
        else if (aPriority > CRITICAL) {
            priority = CRITICAL;
        }
        else {
            priority = aPriority;
        }
    }
}
