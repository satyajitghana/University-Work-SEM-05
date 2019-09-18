// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

#include <iostream>
   
bool authenticated() {
    using namespace std;

    std::string pass("meow123");

    cout << "Enter the auth pass : ";
    std::string input;
    cin >> input;

    return pass == input;
    
}

int main(int argc, char const *argv[]) { 
    if (not authenticated()) {
        std::cout << "AUTH ERROR !" << std::endl;
        exit(EXIT_FAILURE);
    }

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
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) { 
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

    while(true) {

        std::cout << "1.STORE\t2.FETCH\t3.EXIT\nCHOICE : ";
        int choice;
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << "Enter the message to send : " << std::endl;
                std::string input;
                std::cin.ignore();
                std::getline(std::cin, input);

                send(sockfd, "STO", sizeof("STO"), 0);
                send(sockfd, input.c_str(), input.size(), 0);
                std::cout << argv[0] << " : INPUT MESSAGE SENT !" << std::endl;

                bzero(buffer, sizeof(buffer));
                recv(sockfd, buffer, sizeof(buffer), 0);

                std::cout << argv[0] << " : RECIEVED FROM SERVER : " << buffer << std::endl;
            } break;
            case 2: {
                send(sockfd, "FET", sizeof("FET"), 0);
                std::cout << argv[0] << " : FETCH INSTRUCTION SENT !" << std::endl;

                bzero(buffer, sizeof(buffer));
                recv(sockfd, buffer, sizeof(buffer), 0);

                std::cout << argv[0] << " : RECIEVED FROM SERVER : " << buffer << std::endl;
            } break;
            default: {
                send(sockfd, "EXIT", sizeof("EXIT"), 0);
                close(sockfd);
                exit(EXIT_SUCCESS);
            }
        }
    }

    return 0; 
} 