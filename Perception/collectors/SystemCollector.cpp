/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#include "SystemCollector.h"

namespace perception
{

SystemCollector::SystemCollector()
{}


SystemCollector::~SystemCollector()
{}


void SystemCollector::collectData(Composite& data)
{
    getDeviceId(data);
    getDeviceTypeId(data);
    getFirmware(data);
    getChipset(data);
    getManufacturer(data);
    getModelName(data);
    getOperatingSystem(data);
    getOSLoadTime(data);
}

} /* namespace perception */
