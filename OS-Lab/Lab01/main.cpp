#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

void print_proc_details() {
    std::cout << "Process id : [ " << getpid() << " ]" << std::endl;
    std::cout << "Parent Process id : [ " << getppid() << " ]"<< std::endl;
}

int main(int, char**) {
    long long a, b, res;

    // print_proc_details();

    std::cout << "Enter two numbers : ";
    std::cin >> a >> b;

    pid_t pid;

    if (pid = fork()) {
        // parent process
        // do addition here
        print_proc_details();
        res = a + b;
        std::cout << a << " + " << b << " = " << res << std::endl;
        std::cout << std::endl;

        exit(EXIT_SUCCESS);
    } else {
        // child process
        // do subtraction here
        print_proc_details();
        res = a - b;
        std::cout << a << " - " << b << " = " << res << std::endl;
        std::cout << std::endl;

        if(pid = fork()) {
            // the child itself
            if (fork() == 0) {
                print_proc_details();
                res = a * b;
                std::cout << a << " * " << b << " = " << res << std::endl;
                std::cout << std::endl;
                
                exit(EXIT_SUCCESS);
            }
        } else {
            // child's child
            print_proc_details();
            res = a / b;
            std::cout << a << " / " << b << " = " << res << std::endl;
            std::cout << std::endl;
            
            exit(EXIT_SUCCESS);
        }

        exit(EXIT_SUCCESS);
    }
}
