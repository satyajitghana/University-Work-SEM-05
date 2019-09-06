#include <iostream>

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>

void help(char* name);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        help(argv[0]);
        return EXIT_FAILURE;
    }

    // open the source file
    int source_fd;
    if ((source_fd = open(argv[1], O_RDONLY)) < 0) {
        std::cout << argv[0] << " cannot open : " << argv[1] << std::endl;

        exit(EXIT_FAILURE);
    }

    // open the destination file
    int dest_fd;
    if ((dest_fd = open(argv[2], O_WRONLY | O_CREAT)) < 0) {
        std::cout << argv[0] << " cannot open : " << argv[2] << std::endl;

        // if ((dest_fd = open(argv[2], O_CREAT)) < 0) {
        //     std::cout << argv[0] << " cannot create : " << argv[2] << std::endl;
        //     exit(EXIT_FAILURE);
        // } else {
        //     close(dest_fd);
        //     if ((dest_fd = open(argv[2], O_WRONLY)) < 0) {
        //         std::cout << argv[0] << " cannot open : " << argv[2] << std::endl;
        //         exit(EXIT_FAILURE);
        //     }
        // }

        exit(EXIT_FAILURE);
    }

    // buffer
    char buffer[1024];

    while (read(source_fd, buffer, 1024)) {
        using namespace std;
        cout << buffer;

        write(dest_fd, buffer, strlen(buffer));

        memset(buffer, 0, sizeof(buffer));
    }
}

void help(char* name) {
    std::cout << "USAGE : " << name << " <source_file> <dest_file>" << std::endl;
    std::cout << "Example : " << name << " meow.txt boww.txt" << std::endl;
}
