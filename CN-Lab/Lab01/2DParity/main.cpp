#include <iostream>
#include <string>
#include <vector>

#include "parity.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T> &input) {
	for (auto const& i: input) {
		os << i << " ";
	}
	return os;
}

// 2D Parity Program
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

    unsigned short splits;
    std::cout << "Enter how many splits you want : ";
    std::cin >> splits;

    // create the parity data object
    ParityData pdata(sender_data, splits, parity_option);

    std::cout << "Enter the Data from Receiver(row-wise) with parity bits : ";
    std::getline(std::cin, input_line);
    input_line.clear();
    std::getline(std::cin, input_line);
    for (const char &c : input_line) {
        if (c != ' ') {
            receiver_data.push_back(c-'0');
        }
    }
    
    // check if the data received is correct
    bool is_correct = pdata.check_with_received(receiver_data);

    is_correct ? std::cout << "CORRECT" : std::cout << "INVALID";

    std::cout << std::endl;
}

// OUTPUT
// Enter the Data from Sender : 1100
// Enter Parity (E/O) : e
// Enter how many splits you want : 2
// Enter the Data from Receiver with parity bits : 11000011
// CORRECT