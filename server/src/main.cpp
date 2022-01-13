#include "../include/server.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "**********************\n";
	cout << "*       SERVER       *\n";
	cout << "**********************\n" << endl;

	QApplication app(argc, argv);

	cout << "Starting server..." << endl;
	communication::Server server;
	if (!server.start()) return EXIT_FAILURE;
	app.exec();

	cout << "Closing server..." << endl;
	server.~Server();

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
