#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <string.h>

#define SERV_IP "127.0.0.1"
#define SERV_PORT 6666

int main() {
	struct sockaddr_in serv_addr, clie_addr;
	socklen_t clie_addr_len;
	char buf[BUFSIZ], clie_ip[BUFSIZ];
	int n;

	int lfd=socket(AF_INET, SOCK_STREAM, 0);

	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	
	bind(lfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	
	listen(lfd, 128);
	
	clie_addr_len=sizeof(clie_addr);
	int cfd=accept(lfd, (struct sockaddr*)&clie_addr, &clie_addr_len);

	printf("434\n");
	printf("client IP:%s, client port:%d\n", 
	inet_ntop(AF_INET,&clie_addr.sin_addr.s_addr, clie_ip, sizeof(clie_ip)),
	ntohs(clie_addr.sin_port));	
	printf("%s %d\n", clie_ip, strlen(clie_ip));

	while(1) {
		n=read(cfd, buf, sizeof(buf));
		for(int i=0; i<n; i++) 
			buf[i]=toupper(buf[i]);
		write(cfd, buf, n);
	}

	close(cfd);
	close(lfd);
	return 0;
}
