#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080 

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

unsigned long long pow36[11];

void calc_pow_36();
unsigned long long base36encode(std::string);
std::string base36decode(unsigned long long message);

char base36chars[37] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

std::string caesar_encode(std::string);
std::string caesar_decode(std::string);
char caesarchars[26] = "DEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char const *argv[]) {
    calc_pow_36();

    int server_fd, new_socket, valread; 
    struct sockaddr_in address; 
    int opt = 1; 
    int addrlen = sizeof(address); 
       
    // Creating socket file descriptor 
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) { 
        perror("socket failed"); 
        exit(EXIT_FAILURE); 
    } else {
        std::cout << argv[0] << " : " << "SOCKET CREATED SUCCESSFULLY" << std::endl;
    }
       
    // Forcefully attaching socket to the port 8080 
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
        perror("setsockopt"); 
        exit(EXIT_FAILURE); 
    } 

    address.sin_family = AF_INET; 
    address.sin_addr.s_addr = INADDR_ANY; 
    address.sin_port = htons( PORT ); 
       
    // Forcefully attaching socket to the port 8080 
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) { 
        perror("bind failed"); 
        exit(EXIT_FAILURE); 
    }  else {
        std::cout << argv[0] << " : " << "BIND SUCCESSFUL TO PORT " << PORT << std::endl;
    }

    if (listen(server_fd, 3) < 0) { 
        perror("listen"); 
        exit(EXIT_FAILURE); 
    } else {
        std::cout << argv[0] << " : " << "NOW LISTENING" << std::endl;
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen))<0) { 
        perror("accept"); 
        exit(EXIT_FAILURE); 
    } else {
        std::cout << argv[0] << " : CLIENT ACCEPTED" << std::endl;
    }
    
    char buffer[1024] = {0};

    // fetch the operation from the client
    while (true) {
        bzero(buffer, 1024);

        valread = read( new_socket , buffer, sizeof(buffer));
        std::string operation(buffer);

        std::cout << argv[0] << " : OPERATION RECIEVED : " << buffer << std::endl;

        if (operation == "STO") {
            std::ofstream outfile;
            outfile.open("STORE.dat", std::ios::out);

            bzero(buffer, 1024);
            read(new_socket, buffer, sizeof(buffer));
            std::string recieved(buffer);

            std::string encoded = caesar_encode(recieved);

            if (encoded == "") {
                write(new_socket, "FAILED", sizeof("FAILED"));
            } else {
                write(new_socket, "SUCCESS", sizeof("SUCCESS"));
                outfile << encoded;
                std::cout << argv[0] << " : ENCODED : " << encoded << std::endl;
            }
            outfile.close();
        } else if (operation == "FET") {
            std::ifstream infile;
            infile.open("STORE.dat", std::ios::in);
            std::string val;
            infile >> val;

            std::string decoded_val = caesar_decode(val);
            write(new_socket, decoded_val.c_str(), decoded_val.size());

            infile.close();
        } else {
            break;
        }
    }

    // Close the Server File Descriptor
    close(server_fd);

    return 0; 
}

std::string caesar_encode(std::string message) {
    std::string encoded("");
    for (char& c : message) {
        encoded.push_back(caesarchars[c-'a']);
    }

    return encoded;
}
std::string caesar_decode(std::string encoded) {
    std::string decoded("");
    for (char& c : encoded) {
        decoded.push_back(c-'D' + 'A');
    }

    return decoded;

}

void calc_pow_36() {
    pow36[0] = 1;
    
    for (int i = 0 ; i <= 9 ; i++) {
        pow36[i+1] = pow36[i] * 36ull; 
    }
}

unsigned long long base36encode(std::string message) {
    unsigned long long n;
    unsigned long long encoded = 0;

    std::reverse(message.begin(), message.end());

    int i = 0;
    for (char& c : message) {
        if (c >= '0' and c <= '9') {
            n = c - '0';
        } else if (c >= 'A' and c <= 'Z') {
            n = c - 'A' + 10;
        } else if (c >= 'a' and c <= 'z') {
            n = c - 'a' + 10;
        } else {
            return 0;
        }
        encoded += pow36[i] * n;
        i++;
    }

    return encoded;
}

std::string base36decode(unsigned long long message) {
    std::string decoded("");

    while(message != 0) {
        decoded.push_back(base36chars[message % 36]);
        message /= 36;
    }

    std::reverse(decoded.begin(), decoded.end());

    return decoded;
}