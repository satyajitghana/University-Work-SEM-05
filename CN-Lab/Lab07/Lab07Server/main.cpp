#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    } else {
        std::cout << argv[0] << " : "
                  << "SOCKET CREATED SUCCESSFULLY" << std::endl;
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    } else {
        std::cout << argv[0] << " : "
                  << "BIND SUCCESSFUL TO PORT " << PORT << std::endl;
    }

    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    } else {
        std::cout << argv[0] << " : "
                  << "NOW LISTENING" << std::endl;
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t *)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    } else {
        std::cout << argv[0] << " : CLIENT ACCEPTED" << std::endl;
    }

    char buffer[1024] = {0};

    // fetch the operation from the client
    while (true) {
        bzero(buffer, 1024);

        valread = read(new_socket, buffer, sizeof(buffer));
        std::string operation(buffer);
        if (operation.empty()) {
            break;
        }

        std::cout << argv[0] << " : RECIEVED : " << buffer << std::endl;

        std::cout << "Enter the index of the byte from above frames which had "
                     "error\nenter -1 if there was no error :  ";
        int idx;
        std::cin >> idx;
        std::cin.ignore();

        std::string recieved(buffer);
        if (idx != -1) {
            recieved = recieved.substr(0, idx);
        }

        write(new_socket, recieved.c_str(), recieved.size());
    }

    // Close the Server File Descriptor
    close(server_fd);

    return 0;
}
