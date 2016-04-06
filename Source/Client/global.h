#ifndef GLOBAL_H
#define GLOBAL_H
#include <winsock2.h>
#include <iostream>
#include "circularbuffer.h"


#define BUFMAX  128
#define BUFSIZE 8192
#define DATA_BUFSIZE 8192
#define MAXADDRSTR  16

#define TIMECAST_ADDR "234.5.6.7"
#define TIMECAST_PORT 8910

typedef struct _SOCKET_INFORMATION {
   OVERLAPPED Overlapped;
   SOCKET Socket;
   CHAR Buffer[DATA_BUFSIZE];
   WSABUF DataBuf;
   DWORD BytesSEND;
   DWORD BytesRECV;
} SOCKET_INFORMATION, * LPSOCKET_INFORMATION;

static SOCKET hSocket;
extern struct CircularBuffer CBuf;

#endif // GLOBAL_H