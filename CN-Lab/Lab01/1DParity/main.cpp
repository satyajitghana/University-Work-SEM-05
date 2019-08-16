#include <iostream>
#include <string>
#include <vector>

#include "parity.hpp"

int main(int, char**) {

    std::vector<unsigned short> sender_data;
    std::vector<unsigned short> receiver_data;

    std::string input_line;
    std::cout << "Enter the Data from Sender : ";
    std::getline(std::cin, input_line);
    for (const char &c : input_line) {
        if (c != ' ') {
            sender_data.push_back(c-'0');
        }
    }
    char parity;
    std::cout << "Enter Parity (E/O) : ";
    std::cin >> parity;

    PARITY_OPTION parity_option = parity == 'e' ? EVEN : ODD;

    ParityData pdata(sender_data, parity_option);

    std::cout << "Enter the Data from Receiver : ";
    std::getline(std::cin, input_line);
    input_line.clear();
    std::cin.sync();
    std::getline(std::cin, input_line);
    for (const char &c : input_line) {
        if (c != ' ') {
            receiver_data.push_back(c-'0');
        }
    }
    std::cout << "Enter Parity Bit : ";
    unsigned short parity_bit;
    std::cin >> parity_bit;
    
    bool is_correct = pdata.check_with_received(receiver_data, parity_bit);

    is_correct ? std::cout << "CORRECT" : std::cout << "INVALID";

    std::cout << std::endl;
}
