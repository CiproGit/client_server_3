#include "../include/server.h"
#include <iostream>
#include <QThread>

using namespace std;

namespace communication {
	Server::Server() {
		this->timer.setInterval(5000);
		connect(&(this->timer), SIGNAL(timeout()), this, SLOT(on_timeout()));
	}

	Server::~Server() {
		this->tcp_server.close();
	}

	void Server::salutation() {
		QByteArray outgoing_message = QByteArray("Hello there!");
		cout << "Outgoing message: " << QString(outgoing_message).toStdString() << '\n';
		cout << this->tcp_socket->write(outgoing_message) << " bytes sent\n" << endl;
		this->tcp_socket->flush();

		QThread::sleep(1);
	}

	void Server::question() {
		QByteArray outgoing_message = QByteArray("Answer to the ultimate question of life, the universe and everything?");
		cout << "Outgoing message: " << QString(outgoing_message).toStdString() << '\n';
		cout << this->tcp_socket->write(outgoing_message) << " bytes sent\n" << endl;
		this->tcp_socket->flush();
	}

	void Server::answer() {
		this->tcp_socket->waitForReadyRead();
		QByteArray ingoing_message = this->tcp_socket->readAll();
		cout << ingoing_message.size() << " bytes received\n";
		cout << "Ingoing message: " << QString(ingoing_message).toStdString() << '\n' << endl;
	}

	bool Server::start() {
		if (this->tcp_server.listen(QHostAddress(HOST_ADDRESS), PORT)) {
			cout << "Server listening...\n" << endl;
		}
		else {
			cerr << "Error: server not listening" << endl;
			return false;
		}

		this->timer.start();

		this->tcp_server.waitForNewConnection(-1);
		this->tcp_socket = this->tcp_server.nextPendingConnection();

		salutation();
		question();
		answer();

		return true;
	}

	void Server::on_timeout() {
		QByteArray outgoing_message = QByteArray("Don't panic");
		cout << "Outgoing message: " << QString(outgoing_message).toStdString() << '\n';
		cout << this->tcp_socket->write(outgoing_message) << " bytes sent\n" << endl;
		this->tcp_socket->flush();
	}
} // namespace communication
