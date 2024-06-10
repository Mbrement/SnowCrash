#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 6969

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    const char *hello = "Bonjour, je suis le serveur !\n";

    // Création du socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attache le socket à l'adresse et au port spécifiés
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
	listen(server_fd, 3);

    // Lecture du message du client
	int fd = open("./result", O_RDWR);
	while (1)
	{
	new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)	;
	recv(new_socket, buffer, 1024, 0);
    read(new_socket, buffer, 1024);

    write(fd, buffer, strlen(buffer));
	}
    
    return 0;
}
