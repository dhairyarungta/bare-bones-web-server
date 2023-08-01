#include "WebServer.h"
#include <string> 
#include <iostream>
#include<sstream>
#include <fstream>
#include <vector>
#include <istream>
#include <iterator>

void WebServer::onClientConnected(int clientSocket)
{

}

void WebServer::onClientDisconnected(int clientSocket)
{

}

void WebServer::onMessageReceived(int clientSocket, const char* msg , int length)
{
    //GET/index.html HTTP/1.1
    std::istringstream iss(msg);
    std::vector<std::string> parsed((std::istream_iterator<string>(iss)), std::istream_iterator<std::string())



    std::string content = "<h1>404 Not found<h1>";
    std::string htmlFile = "/index.html";
    int errorcode = 404;

    if(parsed.size()>=3 && parsed[0]=="GET")
    {   
        htmlFile = parsed[1];
        if(htmlFile == "/")
        {
            htmlFile = "/index.html";
        }


    }

        std::ifstream f(".\\wwwroot"+parsed[1]);     
        if(f.good())
        {    
            std::string str((std::istreambuf_iterator<char>(f)),std::istreambuf_iterator<char>())
            content = str;
            errorcode = 200;
        }
        f.close();


    std::ostringstream oss ;
    oss<<"HTTP/1.1 "<< errorcode<<" OK\r\n";
    oss<<"Cache-Control: no-cache, private\r\n";
    oss<<"Content-Type: text/plain\r\n";
    oss<<"Content-Length: 5\r\n";
    oss<<"\r\n";
    oss<<content;

    std::string output = oss.str();
    int size = output.size()+1;


    sendToClient(clientSocket, output.c_str(),size);

}

