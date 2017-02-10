/*
 * Copyright (C) 2016 Daniel Nicoletti <dantti12@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB. If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */
#ifndef CUTEENGINE_H
#define CUTEENGINE_H

#include <QObject>
#include <QElapsedTimer>
#include <Cutelyst/Engine>

#include "socket.h"

using namespace Cutelyst;

class QTcpServer;

namespace CWSGI {

struct SocketInfo {
    QString serverName;
    Protocol *protocol;
    bool localSocket;
    qintptr socketDescriptor = 0;
};

class WSGI;
class Protocol;
class CWsgiEngine : public Engine
{
    Q_OBJECT
public:
    explicit CWsgiEngine(Application *app, int workerCore, const QVariantMap &opts, WSGI *wsgi);

    virtual int workerId() const;

    inline void processSocket(Socket *sock) {
        processRequest(*sock);
    }

    void setTcpSockets(const std::vector<SocketInfo> &sockets);

    void listen();

    void postFork();

    int m_workerId = 0;

    virtual bool init();

Q_SIGNALS:
    void initted();
    void started();
    void shutdown();

protected:
    virtual bool finalizeHeadersWrite(Context *c, quint16 status,  const Headers &headers, void *engineData);

    virtual qint64 doWrite(Context *c, const char *data, qint64 len, void *engineData);

private:
    void serverShutdown();

    friend class ProtocolHttp;
    friend class ProtocolFastCGI;

    std::vector<SocketInfo> m_sockets;
    QByteArray m_lastDate;
    QElapsedTimer m_lastDateTimer;
    WSGI *m_wsgi;
};

}

#endif // CUTEENGINE_H
