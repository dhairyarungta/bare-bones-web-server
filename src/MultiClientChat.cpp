#include "MultiClientChat.h"
#include <string>

virtual void onClientConnected(int clientSocket)
{
    string welcomeMsg = "Welcome to the Awesome Chat Server \r\n";
    sendToClient(clientSocket, welcomeMsg.c_str(), welcomeMsg.size()+1);

}


virtual void onClientDisconnected(int clientSocket)
{

}


virtual void onMessageReceived(int clientSocket, const char* msg , int length)
{
    broadcastToClient(clientSocket, msg, length)
}

