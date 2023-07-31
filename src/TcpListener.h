#pragma once 
#include <iostream>
#include <string>
#include <sstream>
#include <WS2tcpip.h>


class TcpListener
{
public: 
    //initialize the listener
    int init();
    
    //run the listener 
    int run();

    TcpListener(const char* ipAddress, int port):m_ipAddress(ipAddress), m_port(port)
    {}



protected:
    //Handler for client connections 
    virtual void onClientConnected();

    //Handler for client disconnections 
    virtual void onClientDisconnected();

    //Handler for when a message is recieved from the client 
    virtual void onMessageReceived(int clientSocket, const char* msg , int length);

    //send a message to a client
    void sentToClient(int clientSocket, const char* msg, int length);
    
    //Boradcast a message from a client
    void broadcastToClient(int sendingClient, const char* msg, int length)

private:
    const char* m_ipAddress;//server ip address
    int m_port; //port number
    int m_socket; //listening socket file descriptor 
    fd_set m_master; //master file descriptor


}