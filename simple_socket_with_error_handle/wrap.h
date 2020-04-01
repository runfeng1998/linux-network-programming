#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>

void perr_exit(const char* s);

int Accept(int, struct sockaddr*,socklen_t*);

int Bind(int,const struct sockaddr*, socklen_t);

int Connect(int, const struct sockaddr*, socklen_t);

int Listen(int, int);

int Socket(int, int, int);

ssize_t Write(int, void*, size_t);

ssize_t Read(int, void*, size_t);

int Close(int);
