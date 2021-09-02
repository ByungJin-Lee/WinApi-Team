#include "Communication.h"

RESULT createServer(unsigned short port)
{        
    RESULT result;
    SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == INVALID_SOCKET) {
        result.ok = FALSE;
        return result;
    }

    sockaddr_in setting = createAddr(nullptr, port);
       
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
    if (listen(socket, 5) == -1) {
        result.ok = FALSE;
        return result;
    }            
    SOCKET client;
    SOCKADDR_IN clientaddr;
    int addlen = sizeof(clientaddr);
    
    client = accept(socket, (sockaddr*)&clientaddr, &addlen);
    result.ok = TRUE;
    result.socket = client;
    result.setting = clientaddr;

    return result;
}

sockaddr_in createAddr(char *ip, unsigned short port)
{
    struct sockaddr_in dest;    
    memset(&dest, 0, sizeof(sockaddr_in));
    dest.sin_family = SINF;
    dest.sin_port = htons(port);
    dest.sin_addr.S_un.S_addr = (ip == nullptr) ? htonl(INADDR_ANY) : inet_addr(ip);
    return dest;
}

RESULT createSocket(sockaddr_in dest)
{
    RESULT result;
    SOCKET fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == INVALID_SOCKET) {
        result.ok = FALSE;
        return result;
    }
    if (connect(fd, (sockaddr*)&dest, sizeof(sockaddr_in)) == -1) {
        result.ok = FALSE;
        return result;
    }
    result.ok = TRUE;
    result.setting = dest;
    result.socket = fd;
    return result;
}

char* getIpFromAddr(char* store, sockaddr_in addr)
{
    sprintf(store, "%s", inet_ntoa(addr.sin_addr));
    return store;
}

char* getInfoFromAddr(char* store, sockaddr_in addr)
{    
    sprintf(store, "%s %d", inet_ntoa(addr.sin_addr), ntohs(addr.sin_port));
    return store;
}
