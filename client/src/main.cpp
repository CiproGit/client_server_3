#include "../include/client.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	cout << "**********************\n";
	cout << "*       CLIENT       *\n";
	cout << "**********************\n" << endl;

	QApplication app(argc, argv);

	cout << "Starting client..." << endl;
	communication::Client client;
	if (!client.start()) return EXIT_FAILURE;
	app.exec();

	cout << "Closing client..." << endl;
	client.~Client();

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
