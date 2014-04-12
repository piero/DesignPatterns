/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef COLLECTORFACTORYOSX_H_
#define COLLECTORFACTORYOSX_H_

#include <CollectorFactory.h>
#include "OsxNetworkCollector.h"

namespace perception
{

class CollectorFactoryOsx : public perception::CollectorFactory
{
public:
    CollectorFactoryOsx();
    virtual ~CollectorFactoryOsx();

    virtual NetworkCollector* createNetworkCollector();
    virtual SystemCollector* createSystemCollector();
};

} /* namespace perception */

#endif /* COLLECTORFACTORYOSX_H_ */
