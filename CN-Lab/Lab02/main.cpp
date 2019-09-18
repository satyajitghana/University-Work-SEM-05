#include <iostream>
#include <bitset>
#include <vector>

#include "crc_lib.hpp"

/**
 * Implement :
 * CRC-8
 * CRC-10
 * CRC-16
 * CRC-32
 */


std::ostream& operator<<(std::ostream& out, std::vector<std::bitset<8>> message) {
    for (auto& byte : message) {
        out << byte << " ";
    }

    return out;
}

int main(int, char**) {

    std::cout << "Enter your message (in binary) : ";
    std::string input;
    std::getline(std::cin, input);

    // pad extra zero to make the number of bits a multiple of 8
    unsigned to_pad = input.size() % 8 != 0 ? (8 - input.size() % 8) : 0;
    for (int i = 0 ; i < to_pad ; i++) {
        input = "0"+input;
    }

    std::vector<std::bitset<8>> message;

    for (int i = 0 ; i+8 <= input.size() ; i += 8) {
        message.push_back(std::bitset<8>(input.substr(i, 8)));
    }

    std::cout << "MESSAGE : " << message << std::endl;

    CRC_OPTION crc_option;

retake_choice:
    std::cout << 
        "Select a CRC Polynomial : \n"
        "1.\tCRC8\n"
        "2.\tCRC10\n"
        "3.\tCRC16\n"
        "4.\tCRC32\n"
        "Your Choice : ";
    char choice;
    std::cin >> choice;
    
    switch(choice) {
        case '1':
            crc_option = CRC8;
            break;
        case '2':
            crc_option = CRC10;
            break;
        case '3':
            crc_option = CRC16;
            break;
        case '4':
            crc_option = CRC32;
            break;
        default:
            std::cout << "Wrong Choice !";
            goto retake_choice;
    }

    std::tuple<std::bitset<32>, unsigned> crc_calculated = CRC::calc_crc(message, crc_option);

    std::cout << "CRC : " << std::get<0>(crc_calculated).to_string().substr(32-std::get<1>(crc_calculated)) << std::endl;

    std::cin.ignore();
    std::cout << "Enter the data received (with CRC padded at the end) : ";
    std::getline(std::cin, input);


    to_pad = input.size() % 8 != 0 ? (8 - input.size() % 8) : 0;
    for (int i = 0 ; i < to_pad ; i++) {
        input = "0"+input;
    }

    message.clear();
    for (int i = 0 ; i+8 <= input.size() ; i += 8) {
        message.push_back(std::bitset<8>(input.substr(i, 8)));
    }

    std::cout << "MESSAGE : " << message << std::endl;

    CRC::check_crc(message, crc_option) ? std::cout << "PASS" : std::cout << "FAIL";

    std::cout << std::endl;
}

// TESTED WORKS !

// MESSAGE : 10101010 
// POLYNOMIAL : 11010101
// REM : 10101010
// REM : 10000001
// REM : 11010111
// REM : 01111011
// REM : 11110110
// REM : 00111001
// REM : 01110010
// REM : 11100100
// CRC : 00011101

// MESSAGE : 10101010 10111011 
// POLYNOMIAL : 11010101
// REM : 10101010
// REM : 10000001
// REM : 11010111
// REM : 01111011
// REM : 11110110
// REM : 00111001
// REM : 01110010
// REM : 11100100
// REM : 10100110
// REM : 10011001
// REM : 11100111
// REM : 00011011
// REM : 00110110
// REM : 01101100
// REM : 11011000
// REM : 01100101
// CRC : 11001010
// 11001010



// The CRC length should be always greater than or equal to byte to be processed
// In this case we are processing byte-by-byte so this is always true

// std::bitset<8> CRC(0xD5);
// #define CRC_SIZE CRC.size()

/**
 * calc_crc
 * args: message : a vector of byte bitsets
 */
// std::bitset<CRC_SIZE> calc_crc(std::vector<std::bitset<8>> &message) {
//     std::cout << "POLYNOMIAL : " << CRC << std::endl;
//     // initialize the remainder with 0
//     std::bitset<CRC_SIZE> remainder(0x0);

//     // Perform for every byte in message
//     for (auto& byte : message) {
//         // load the byte to the remainder
//         remainder ^= (byte << (CRC.size() - byte.size()));

//         // perform for every bit in the byte
//         for (unsigned i = 0 ; i < 8 ; i++) {
//             std::cout << "REM : " << remainder << std::endl;
//             // check if the top bit is 1
//             if (remainder.test(remainder.size()-1)) {
//                 remainder = (remainder << 1) xor CRC;
//             } else {
//                 remainder = remainder << 1;
//             }
//         }
//     }

//     std::cout << "CRC : " << remainder << std::endl;

//     return remainder;
// }