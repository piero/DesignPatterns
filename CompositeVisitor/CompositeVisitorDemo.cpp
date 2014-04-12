#include <iostream>
#include "Composite.hpp"
#include "DumpVisitor.hpp"
#include "DumpTreeVisitor.hpp"
#include "CountVisitor.hpp"
#include "XmlVisitor.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Node root("root");

	Node etc("etc"); root.add(&etc);
	Leaf hosts("hosts"); etc.add(&hosts);
	Node apache("apache"); etc.add(&apache);
	Leaf httpd("httpd.conf"); apache.add(&httpd);

	Node home("home"); root.add(&home);
	Node admin("admin"); home.add(&admin);
	Leaf doc("document.txt"); admin.add(&doc);

	Node piero("piero"); home.add(&piero);
	Leaf song("song.mp3"); piero.add(&song);

	DumpVisitor dumpVisitor;
	root.accept(dumpVisitor);

	cout << endl << "[?] Press ENTER to continue..." << endl;
	cin.ignore(1);

	DumpTreeVisitor dumpTreeVisitor;
	root.accept(dumpTreeVisitor);

	cout << endl << "[?] Press ENTER to continue..." << endl;
	cin.ignore(1);

	CountVisitor countVisitor;
	root.accept(countVisitor);

	std::cout << "There are " << countVisitor.getNodeCount() << " nodes." << std::endl;
	std::cout << "There are " << countVisitor.getLeafCount() << " leaves." << std::endl;

	cout << endl << "[?] Press ENTER to continue..." << endl;
	cin.ignore(1);

	XmlVisitor xmlVisitor;
	root.accept(xmlVisitor);

	std::cout << xmlVisitor.getXml() << std::endl;
}
