/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

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
