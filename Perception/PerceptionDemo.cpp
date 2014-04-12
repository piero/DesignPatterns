/*
 * This code is released under GPLv2 License.
 *
 * http://www.gnu.org/licenses/gpl-2.0.txt
 *
 */

#ifdef __linux__
# include <CollectorFactoryLinux.h>
#elif defined __APPLE__
# include <CollectorFactoryOsx.h>
#endif

#include <DumpVisitor.h>
#include <JsonVisitor.h>

#include <iostream>

using namespace std;
using namespace perception;

int main(int argc, char *argv)
{
    CollectorFactory *factory = 0;

#ifdef __linux__
    factory = new CollectorFactoryLinux();
#elif defined __APPLE__
    factory = new CollectorFactoryOsx();
#endif

    NetworkCollector *netCollector = factory->createNetworkCollector();

    CompositeNode data("networking");
    netCollector->collectData(data);

    DumpVisitor dumpVisitor;
    data.accept(dumpVisitor);

    cout << "[?] Press ENTER to continue..." << endl;
    cin.ignore(1);

    JsonVisitor jsonVisitor;
    data.accept(jsonVisitor);
    cout << jsonVisitor.getJsonRepresentation() << endl;

    delete netCollector;
    delete factory;
}
