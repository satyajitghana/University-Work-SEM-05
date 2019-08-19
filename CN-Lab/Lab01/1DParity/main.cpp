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

    std::cout << "Parity Bit : " << pdata.get_parity_bit() << std::endl;

    std::cout << "Data Transmitted : " << input_line << pdata.get_parity_bit() << std::endl;

    std::cout << "Enter the Data from Receiver : ";
    std::cin.ignore();
    std::getline(std::cin, input_line);
    unsigned short parity_bit = input_line.back() - '0';
    input_line.pop_back();
    for (const char &c : input_line) {
        if (c != ' ') {
            receiver_data.push_back(c-'0');
        }
    }

    bool is_correct = pdata.check_with_received(receiver_data, parity_bit);

    is_correct ? std::cout << "CORRECT" : std::cout << "INVALID";

    std::cout << std::endl;
}
