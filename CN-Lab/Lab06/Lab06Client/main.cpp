// Client side C/C++ program to demonstrate Socket programming
#include <iostream>
#include <string>

#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define IPADDR "127.0.0.1"
#define BUFSIZE 1024

/**
 * Client Side code, connects to the server,
 * sends the input from stdin to server
 * recieves from server and prints the data
*/
int main(int argc, char const *argv[]) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE] = {0};

    std::cout << "CLIENT" << std::endl;

    // create the socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // create the structure member values
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, IPADDR, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    // infinite loop
    while (true) {
        std::string hello;

        std::cout << "Enter the Message to be sent to server : ";
        std::cin >> hello;

        send(sock, hello.c_str(), hello.size(), 0);

        std::cout << "Message sent to Server !\n"
                  << std::endl;

        valread = read(sock, buffer, BUFSIZE);
        printf("Recieved from Server : %s\n\n", buffer);

        // zero the buffer
        bzero(buffer, sizeof(buffer));
    }

    return 0;
}