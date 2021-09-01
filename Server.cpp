#include "Server.h"

RESULT createServer(unsigned short port)
{        
    RESULT result;
    SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        result.ok = FALSE;
        return result;
    }
    struct sockaddr_in setting;    
    memset(&setting, 0, sizeof(setting));
    setting.sin_family = SINF;
    setting.sin_port = htons(port);
    setting.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
   
    if (bind(fd, (struct sockaddr*)&setting, sizeof(setting)) == -1) {
        result.ok = FALSE;
        return result;
    }   

    result.ok = TRUE;
    result.socket = fd;
    result.setting = setting;
    return result;
}

RESULT acceptClient(SOCKET socket)
{
    RESULT result;
    if (listen(socket, 1) == -1) {
        result.ok = FALSE;
        return result;
    }            
    SOCKET client;
    SOCKADDR_IN clientaddr;
    int addlen = sizeof(clientaddr);

    client = accept(socket, (struct sockaddr*)&clientaddr, &addlen);
    result.ok = TRUE;
    result.socket = client;
    result.setting = clientaddr;

    return result;
}

sockaddr_in createDest(char *ip, short port)
{
    struct sockaddr_in dest;    
    memset(&dest, 0, sizeof(struct sockaddr_in));
    dest.sin_family = SINF;
    dest.sin_port = htons(port);
    dest.sin_addr.S_un.S_addr = inet_addr(ip);
    return dest;
}

RESULT createSocket(struct sockaddr_in dest)
{
    RESULT result;
    SOCKET fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd == -1) {
        result.ok = FALSE;
        return result;
    }
    if (connect(fd, (sockaddr*)&dest, sizeof(struct sockaddr_in)) == -1) {
        result.ok = FALSE;
        return result;
    }
    result.ok = TRUE;
    return result;
}

void displayInfoAddress(char* save, sockaddr_in addr)
{    
    sprintf(save, "%s %d", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
}
