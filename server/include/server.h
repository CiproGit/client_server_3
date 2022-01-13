#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QString>
#include <QTimer>

namespace communication {
	const QString HOST_ADDRESS = "127.0.0.1";
	const quint16 PORT = 50000;

	class Server : public QObject{
		Q_OBJECT
	private:
		QTcpServer tcp_server;
		QTcpSocket *tcp_socket;
		QTimer timer;

		void salutation();
		void question();
		void answer();
	public:
		Server();
		virtual ~Server();
		bool start();
	public slots:
		void on_timeout();
	signals:
	};
} // namespace communication

#endif // SERVER_H
