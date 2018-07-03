#include <iostream>
#include <algorithm>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/epoll.h>
int main(int argc, char **argv)
{
	int Socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	struct sockaddr_in SockAddr;
	SockAddr.sin_family = AF_INET;
	SockAddr.sin_port = htons(12121);
	SockAddr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
	connect(Socket, (struct sockaddr *)(&SockAddr), sizeof(SockAddr));
	char Buffer[30];
	printf("Insert progname: \n");
	scanf("%s",Buffer);
	send(Socket, Buffer,30,MSG_NOSIGNAL);
	recv(Socket, Buffer,30,MSG_NOSIGNAL);
	shutdown(Socket, SHUT_RDWR);//закрываем соединение и клиента и сервера
	close(Socket);
	printf("%s\n",Buffer);

	return 0;
}