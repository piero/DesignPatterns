/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COLLECTOR_H_
#define COLLECTOR_H_

#include <Composite.h>

namespace perception
{

class Collector
{
public:
    virtual ~Collector() {};

    /**
     * Collect data relevant to Perception.
     * Data are appended to the container (passed as argument).
     *
     * @param data Data container.
     */
    virtual void collectData(Composite& data) = 0;
};

} /* namespace perception */

#endif /* COLLECTOR_H_ */
