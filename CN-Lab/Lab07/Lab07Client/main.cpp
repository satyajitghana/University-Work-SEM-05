// Client side C/C++ program to demonstrate Socket programming
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080

#include <iostream>

int main(int argc, char const *argv[]) {
    std::cout << "Enter the ARQ Mechanism to use " << std::endl;
    std::cout
        << "1.Stop And Wait\t2.Go Back N\3.Selective Repeat\nYour Choice : "
        << std::endl;
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    int sockfd = 0, valread;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    } else {
        std::cout << argv[0] << " : SOCKET CREATED " << std::endl;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    } else {
        std::cout << argv[0] << " : ADDRESS CONVERTED" << std::endl;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    } else {
        std::cout << argv[0] << " : CONNECTION ESTABLISHED" << std::endl;
    }

    char buffer[1024] = {0};

    // create the data (20frames)
    std::string frames("");

    for (int i = 0; i < 20; i++) frames.push_back(std::rand() % 10 + '0');

    std::cout << argv[0] << " : FRAMES TO TRANSMIT\n" << frames << std::endl;

    switch (choice) {
        case 1: {
        } break;
        case 2: {
            int windowSize;
            std::cout << "Enter the window size : ";
            std::cin >> windowSize;
            std::cin.ignore();
            int N = windowSize;

            std::string::iterator start = frames.begin();
            std::string::iterator end = frames.begin() + N >= frames.end()
                                            ? frames.end()
                                            : frames.begin() + N;

            while (true) {
                std::string to_transmit(start, end);
                std::cout << "TRANSMITTING : " << to_transmit << std::endl;

                if (to_transmit.empty()) {
                    break;
                }

                write(sockfd, to_transmit.c_str(), to_transmit.size());

                bzero(buffer, sizeof(buffer));
                read(sockfd, buffer, sizeof(buffer));
                std::string recieved(buffer);

                std::cout << "SERVER RECIEVED : " << recieved << std::endl;

                // error has occured
                int idx = recieved.size();

                start += idx;
                end = start + N >= frames.end() ? frames.end() : start + N;
            }

        } break;
        case 3: {
        } break;
        default: {
            send(sockfd, "EXIT", sizeof("EXIT"), 0);
            close(sockfd);
            exit(EXIT_SUCCESS);
        }
    }

    close(sockfd);
    exit(EXIT_SUCCESS);

    return 0;
}