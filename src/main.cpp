#include "MultiClientChat.h"

void main()
{
    WebServer webserver("0.0.0.0", 54000);
    if(webserver.init()!=0)
        return;
    
    webserver.run();
    system("pause");

}
