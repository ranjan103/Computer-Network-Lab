// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 
#include <time.h>
int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	struct sockaddr_in serv_addr; 
	//int *hello = 0;
	 char *hello[100] = "Tell me current date"; 
	char buffer[1024] = {0}; 
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
	{ 
		printf("\n Socket creation error \n"); 
		return -1; 
	} 

	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 
	
	// Convert IPv4 and IPv6 addresses from text to binary form 
	if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
	{ 
		printf("\nInvalid address/ Address not supported \n"); 
		return -1; 
	} 

	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
	{ 
		printf("\nConnection Failed \n"); 
		return -1; 
	}

	while(1)
	{
		printf("Enter the string:");
		scanf("%s",&hello);
		send(sock , hello , strlen(hello) , 0 );
		valread = read( sock , buffer, 1024); 
		printf("%s\n",buffer ); 

	} 
	// send(sock , hello , strlen(hello) , 0 ); 
	// time_t t = time(NULL);
 //    struct tm tm = *localtime(&t); 
	//printf("now: %d-%d-%d %d:%d:%d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	//printf("Hello message sent\n"); 
	// valread = read( sock , buffer, 1024); 
	// printf("%s\n",buffer ); 
	return 0; 
} 
