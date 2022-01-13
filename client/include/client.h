#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>

namespace communication {
	const QString SERVER_ADDRESS = "127.0.0.1";
	const quint16 PORT = 50000;

	class Client : public QObject{
		Q_OBJECT
	private:
		QTcpSocket *tcp_socket;
	public:
		Client();
		virtual ~Client();
		bool start() const;
	public slots:
		void on_readyRead();
	};
} // namespace communication

#endif // CLIENT_H
