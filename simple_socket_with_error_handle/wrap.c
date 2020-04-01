#include "wrap.h"

void perr_exit(const char* s) {
	perror(s);
	exit(-1);
}

int Accept(int fd, struct sockaddr* addr, socklen_t* addr_len_ptr) {
	int n=-1;
	while(1) {
		n=accept(fd, addr, addr_len_ptr);
		if (n<0) {
			if ((errno==ECONNABORTED) || (errno == EINTR)) {
				continue;
			}
			else {
				perr_exit("accept error");
			}
		}
		else break;
	}
	return n;
}

int Bind(int fd, const struct sockaddr* addr, socklen_t addr_len) {
	int n;
	if ( (n=bind(fd, addr, addr_len)) < 0) {
		perr_exit("bind error");
	}
	return n;
}

int Connect(int fd, const struct sockaddr* addr, socklen_t addr_len) {
	int n;
	printf("--------------in wrap before connect()\n");
	n=connect(fd, addr, addr_len);
	printf("--------------in wrap connect() return %d\n", n);
	if (n<0) {
		perr_exit("connect exit");
	}
	return 0;
}

int Listen(int fd, int backlog) {
	int n;
	if ((n=listen(fd, backlog)) < 0) {
		perr_exit("listen error");
	}
	return n;

}

int Socket(int family, int type, int protocol) {
	int n;
	if ( (n=socket(family, type, protocol))<0 ) 
		perr_exit("socket error");
	return n;
}

ssize_t Read(int fd, void *ptr, size_t count) {
	ssize_t n=-1;
	while(1) {
		n=read(fd, ptr, count);
		if (n==-1) {
			if (errno=EINTR) continue;
			else break;
		}
		else break;
	}
	return n;
}

ssize_t Write(int fd, void *ptr, size_t count) {
	ssize_t n=-1;
	while(1) {
		 n=write(fd, ptr, count);
		 if (n==-1&&errno==EINTR) continue;
		 else break;
	}
	return n;
}

int Close(int fd) {
	int n;
	n=close(fd);
	if (n==-1) perr_exit("close error");
	else return n;
}


