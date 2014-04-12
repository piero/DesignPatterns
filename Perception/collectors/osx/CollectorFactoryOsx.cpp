/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "CollectorFactoryOsx.h"

namespace perception
{

CollectorFactoryOsx::CollectorFactoryOsx()
{}


CollectorFactoryOsx::~CollectorFactoryOsx()
{}

NetworkCollector* CollectorFactoryOsx::createNetworkCollector()
{
    return new OsxNetworkCollector();
}


SystemCollector* CollectorFactoryOsx::createSystemCollector()
{
    // TODO
    return 0;
}

} /* namespace perception */
