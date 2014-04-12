/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifndef SYSTEMCOLLECTOR_H_
#define SYSTEMCOLLECTOR_H_

#include "Collector.h"

namespace perception
{

class SystemCollector: public perception::Collector
{
public:
    SystemCollector();
    virtual ~SystemCollector();

    virtual void collectData(Composite& data);

protected:
    virtual void getDeviceId(Composite& data) = 0;         // Unique ID for each device
    virtual void getDeviceTypeId(Composite& data) = 0;     // Amazon-provided unique ID for each device type
    virtual void getFirmware(Composite& data) = 0;         // Client application version
    virtual void getChipset(Composite& data) = 0;          // Chipset name
    virtual void getManufacturer(Composite& data) = 0;     // Manufacturer name
    virtual void getModelName(Composite& data) = 0;        // Model name
    virtual void getOperatingSystem(Composite& data) = 0;  // Name of the underlying operating system
    virtual void getOSLoadTime(Composite& data) = 0;       // How long the device took to boot

    /**
     * 4-bit flag denoting the cause for reboot.
     *
     * 0x01 - Boot after firmware upgrade
     * 0x10 - Boot after abnormal shutdown
     * TODO TODO TODO
     *
     * @param data
     */
    virtual void getBootFlags(Composite& data) = 0;
};


} /* namespace perception */

#endif /* SYSTEMCOLLECTOR_H_ */
