/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef PERCEPTIONEVENT_H_
#define PERCEPTIONEVENT_H_

#include <string>
#include "Exceptions.h"

namespace perception
{

/**
 * This is the base container of all Perception events.
 */
class PerceptionEvent
{
public:
    /**
     * Constructor.
     *
     * @param category Event category [0-99]
     * @param type Event type [0-9999]
     * @param module Module generating the event [0-99]
     * @param description Optional description
     *
     * @throw IllegalParameterError If at least one parameter is invalid.
     */
    PerceptionEvent(unsigned short category,
                    unsigned short type,
                    unsigned short module,
                    std::string description = "");

    virtual ~PerceptionEvent();

    /**
     * Get the event code.
     *
     * Format: xx-yyyy-zz [category-type-module] with 0-padding.
     *
     * @return The event code, as a string.
     */
    const std::string getCode();

    /**
     * Get the event description.
     *
     * @return The event description, as a string.
     */
    const std::string getDescription() const;

protected:

    /**
     * Check if parameters are valid.
     *
     * @throw IllegalParameterError If some parameter is not valid.
     */
    void validateParameters();

    /**
     * Get the current system time (Unix time).
     *
     * @return the current system time, in Unix time.
     */
    unsigned long getCurrentTime();

    /**
     * Calculate the time difference between two timestamps (Unix time);
     *
     * @return The time difference, in milliseconds.
     */
    unsigned long calculateTimeDifference(const unsigned long& t1, const unsigned long& t2);

    const unsigned short _category;
    const unsigned short _type;
    const unsigned short _module;
    const std::string _description;

    unsigned long _timestamp;   // Time of event generation (Unix time)
    unsigned long _duration;    // Event duration, in milliseconds
};

} /* namespace perception */
#endif /* PERCEPTIONEVENT_H_ */
