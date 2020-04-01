#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include "wrap.h"

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6666

int main() {
	int cfd;
	struct sockaddr_in serv_addr;
	socklen_t sock_addr_len;
	char buf[BUFSIZ];

	cfd=Socket(AF_INET, SOCK_STREAM, 0);

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(SERV_PORT);
	inet_pton(AF_INET, SERV_IP, &serv_addr.sin_addr.s_addr);

	//serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);

	Connect(cfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	while(1) {
		fgets(buf, sizeof(buf), stdin);
		Write(cfd, buf, strlen(buf));
		int n=Read(cfd, buf, sizeof(buf));
		Write(STDOUT_FILENO, buf, n);
	}

	return 0;
}

