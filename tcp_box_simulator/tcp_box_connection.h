#ifndef TCP_BOX_CONNECTION_H
#define TCP_BOX_CONNECTION_H

#include <QObject>
#include <QTcpSocket>
#include <QList>

static const int MaxBufferSize = 1024000;
static const char SeparatorToken = '?';

class tcp_box_connection : public QTcpSocket
{
    Q_OBJECT
public:
    explicit tcp_box_connection(QObject *par = 0);
    ~tcp_box_connection();
    Q_DISABLE_COPY(tcp_box_connection)

private slots:
    void processReadyRead();

    void fc_sendAll();
    void fc_sendActSet();

private:
    int readDataIntoBuffer(const char sep=SeparatorToken, int maxSize = MaxBufferSize);
    bool readCommand();
    bool parseArguments();
    void processData();

    QString fc_buildAll();
    void simulate_delay(unsigned long low = 100, unsigned long high = 200);

private:
    QByteArray buffer;
};

#endif // TCP_BOX_CONNECTION_H
