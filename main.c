#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "defines.h"

#define RECV_BUFSIZE 1024

void error(char *msg) {
  perror(msg);
  exit(1);
}

int main ( int argc, char **argv ) {
	int sockfd;
	int optval;
	struct sockaddr_in6 serveraddr;
	int clientlen; // length of client address
	struct sockaddr_in6 clientaddr;
	char buf[RECV_BUFSIZE+1];
	
	sockfd = socket(AF_INET6, SOCK_DGRAM, 0);
	if (sockfd < 0) 
		error("ERROR opening socket");

	// allow fast rebind for debugging
	setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval , sizeof(int));
	
	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin6_family = AF_INET6;
	serveraddr.sin6_addr = in6addr_any;
	serveraddr.sin6_port = htons((unsigned short)PNRP_UDP_PORT);
	
	// bind UDP socket
	if (bind(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) 
		error("ERROR on binding");
	
	clientlen = sizeof(clientaddr);
	unsigned int n;
	char clientipv6str[INET6_ADDRSTRLEN];
	char clienthostname[256];
	char clientport[256];
	while(1) {
		n = recvfrom(sockfd, buf, RECV_BUFSIZE, 0, (struct sockaddr *) &clientaddr, &clientlen);
		if (n < 0)
			error("ERROR in recvfrom");
		
		// put zero behind it to terminate it!
		buf[n] = '\0';
		
		getnameinfo((struct sockaddr *)&clientaddr, sizeof(clientaddr), clienthostname, sizeof(clienthostname), clientport, sizeof(clientport), NI_DGRAM);
		inet_ntop(AF_INET6, clientaddr.sin6_addr.s6_addr, clientipv6str, INET6_ADDRSTRLEN);
		
		printf("server received datagram from host: %s port: %s (ip: %s)\n",  clienthostname, clientport, clientipv6str);
		printf("server received %d/%d bytes: %s\n", (unsigned int)strlen(buf), n, buf);
	}
	
    printf("Testing out CMake\n");
    return 0;
}