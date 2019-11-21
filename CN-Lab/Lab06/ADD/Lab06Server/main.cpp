#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include <iostream>
#include <string>

#define PORT 8080
#define BUFSIZE 1024

/**
 * Server Side code, takes input from stdin and sends it to the client
 * Recieves data from client and prints it.
*/
int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFSIZE] = {0};

    std::cout << "SERVER" << std::endl;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // assign the structure members
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen to connections, max 3
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // accept connection
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // keep running until the server or the client is closed
    while (true) {
        // zero the buffer
        bzero(buffer, sizeof(buffer));

        read(new_socket, buffer, BUFSIZE);
        printf("Operation : %s\n\n", buffer);

        std::cout << "Operation : " << buffer << "\n"
                  << std::endl;

        if (std::string(buffer) == "STOP") {
            std::cout << "STOP" << std::endl;
            exit(EXIT_SUCCESS);
        } else if (std::string(buffer) == "ADDI") {
            char opd[20];
            read(new_socket, opd, 20);
            int op1 = atoi(opd);
            read(new_socket, opd, 20);
            int op2 = atoi(opd);

            int sum =
        } else if (std::string(buffer) == "ADDF") {
        }
    }

    return 0;
}