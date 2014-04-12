package eventnotifier;

import java.util.Enumeration;
import java.util.Vector;

public class EventService {

    // Prevents direct instantiation of the event service
    private EventService() {
        eventClass = Event.class;
        subscriptions = new Vector<Subscription>();
    }
    static private EventService singleton = null;

    // Provides well-known access point to singleton EventService
    static public EventService instance() {
        if (singleton == null) {
            singleton = new EventService();
        }
        return singleton;
    }

    public void publish(Event event) {
        for (Enumeration<Subscription> elems = subscriptions.elements(); elems.hasMoreElements();) {
            Subscription subscription = (Subscription) elems.nextElement();
            if (subscription.eventType.isAssignableFrom(event.getClass())
                    && (subscription.filter == null || subscription.filter.apply(event))) {
                subscription.subscriber.inform(event);
            }
        }
    }

    public void subscribe(Class<?> eventType, Filter filter, Subscriber subscriber) throws InvalidEventTypeException {
        System.out.println("[ES] Subscribing " + subscriber.getName());
        if (!eventClass.isAssignableFrom(eventType)) {
            throw new InvalidEventTypeException();
        }

        // Prevent duplicate subscriptions
        Subscription subscription = new Subscription(eventType, filter, subscriber);
        if (!subscriptions.contains(subscription)) {
            subscriptions.addElement(subscription);
        }
    }

    public void unsubscribe(Class<?> eventType, Filter filter, Subscriber subscriber) throws InvalidEventTypeException {
        if (!eventClass.isAssignableFrom(eventType)) {
            throw new InvalidEventTypeException();
        }
        subscriptions.removeElement(new Subscription(eventType, filter, subscriber));
    }
    private Class<Event> eventClass;
    protected Vector<Subscription> subscriptions;
}

// Stores information about a single subscription
class Subscription {
    public Subscription(Class<?> anEventType, Filter aFilter, Subscriber aSubscriber) {
        eventType = anEventType;
        filter = aFilter;
        subscriber = aSubscriber;
    }
    public Class<?> eventType;
    public Filter filter;
    public Subscriber subscriber;
}


