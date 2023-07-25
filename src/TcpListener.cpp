#include "TcpListener.h"


int TcpListener::init()
{
    //initialise the winsoc lib before using it
    WSADATA wsData;
    WORD ver = MAKEWORD(2,2);
    int wsok = WSAStartup(ver,&wsData);
    if(wsk!=0)
    {
        return wsok;
    }

    //socket
    m_socket = socket(AF_INET,SOCK_STREAM, 0);
    if(m_socket==INVALID_SOCKET)
    {
        return WSAGetLastError();
    }
    sockaddr_in hint ;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(m_port)
    inet_pton(AF_INET, m_ipAddress,&hind.sin_addr);

    if(bind(m_socket,(sockaddr*)&hint, sizeof(hint))==SOCKET_ERROR)
    {
        return WSAGetLastError();
    }

    if(listen(m_socket,SOMAXCONN)==SOCKET_ERROR)
    {
        return WSAGetLastError();
    }

    FD_ZERO(&m_master);
    FDSET(m_socket,&m_master);
    return 0;
}

int TcpLIstener::run()
{
    bool running = true;
    while(running)
    {
        fd_set copy = m_master;

        int socketCount = select(0, &copy, nullptr, nullptr, nullptr);
        for (int i =0 ;i<socketCount;++i)
        {
            SOCKET sock = copy.fd_array[i];
            if(sock==m_socket )
            {
                SOCKET client = accept (m_socket, nullptr, nullptr);
                FD_SET(client, &m_master);
                //TODO CLIENT CONNECTED
            }else 
            {
                char buf[4096];
                ZeroMemory(buf,4096);

                //receive message
                int bytesIn = recv(sock, buf, 4096, 0);
                int (bytesIn<=0)
                {
                    //DROP the client 
                    //TODO :CLIENT DISCONNECTED
                    closesocket(sock) 
                }

            }

        }
    }
}


void TcpListener::sendToClient(int clientsocket, const char*msg, int length)
{
    send(clientsocket, msg, length, 0);
}

void TcpListener::broadcastToClients(int sendingClient, const char* msg, int length)
{
    for (int i =0 ;i<m_master.fd_count;++i)
    {
        SOCKET outSock = m_master.fd_array[i];
        if(outSock !=m_socket && outSock!=sendingClient)
        {
            sendToClient(outSock, msg, length);
        }
    }
}

void TcpListener::onClientConnected()
{}

void TcpListener::onClientDisconnected();
{}

void TcpListener::onMessageReceived(int clientSocket, const char* msg , int length);
{}
