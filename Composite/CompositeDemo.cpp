#include "Composite.hpp"

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

	root.dump();
}
