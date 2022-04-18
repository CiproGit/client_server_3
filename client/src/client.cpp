#include "../include/client.h"
#include <iostream>

using namespace std;

namespace communication {
	Client::Client() {
		this->tcp_socket = new QTcpSocket();
		connect(this->tcp_socket, SIGNAL(readyRead()), this, SLOT(on_readyRead()));
	}

	Client::~Client() {
		this->tcp_socket->close();
		delete this->tcp_socket;
	}

	bool Client::start() const {
		this->tcp_socket->connectToHost(SERVER_ADDRESS, PORT);
		if (this->tcp_socket->waitForConnected()) {
			cout << "Connected to the server" << endl;
			return true;
		}
		else {
			cerr << "Error: not connected to the server" << endl;
			return false;
		}
	}

	void Client::on_readyRead() {
		QByteArray ingoing_message = this->tcp_socket->readAll();
		cout << ingoing_message.size() << " bytes received\n";
		cout << "Ingoing message: " << QString(ingoing_message).toStdString() << endl;

		if (ingoing_message == "Answer to the ultimate question of life, the universe and everything?") {
			QByteArray outgoing_message = QByteArray("42");
			cout << "Outgoing message: " << QString(outgoing_message).toStdString() << '\n';
			cout << this->tcp_socket->write(outgoing_message) << " bytes sent" << endl;
		}
	}
} // namespace communication
