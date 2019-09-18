#include "crc_lib.hpp"

#include <iostream>
#include <tuple>

// returns the CRC polynomial with the CRC polynomial length
std::tuple<std::bitset<32>, unsigned> CRC::get_crc_polynomial(CRC_OPTION crc_option) {

    std::bitset<32> crc_poly;
    unsigned crc_poly_len;

    switch(crc_option) {
        case CRC8:
            crc_poly = std::bitset<32>(0xD5);
            crc_poly_len = 8;
            break;
        case CRC10:
            crc_poly = std::bitset<32>(0x233);
            crc_poly_len = 10;
            break;
        case CRC16:
            crc_poly = std::bitset<32>(0x1021);
            crc_poly_len = 16;
            break;
        case CRC32:
            crc_poly = std::bitset<32>(0x04C11DB7);
            crc_poly_len = 32;
            break;
    }

    return std::make_tuple(crc_poly, crc_poly_len);
}

std::tuple<std::bitset<32>, unsigned> CRC::calc_crc(std::vector<std::bitset<8>>& message, CRC_OPTION crc_option) {
    // Fetch the CRC polynomial
    std::tuple<std::bitset<32>, unsigned> _crc_poly = CRC::get_crc_polynomial(crc_option);

    std::bitset<32> crc_poly = std::get<0>(_crc_poly);
    unsigned crc_poly_len = std::get<1>(_crc_poly);

    std::cout << "POLYNOMIAL : " << crc_poly << std::endl;
    // initialize the remainder with 0
    std::bitset<32> remainder(0x0);

    // Perform for every byte in message
    for (auto& byte : message) {
        // load the byte to the remainder
        remainder ^= ( (std::bitset<32>(byte.to_string())) << (crc_poly_len - byte.size()) );

        // perform for every bit in the byte
        for (unsigned i = 0 ; i < 8 ; i++) {
            // std::cout << "REM : " << remainder << std::endl;
            // check if the top bit is 1
            if (remainder.test(crc_poly_len-1)) {
                remainder = (remainder << 1) xor crc_poly;
            } else {
                remainder = remainder << 1;
            }
        }
    }

    // std::cout << "CRC : " << remainder << std::endl;

    return std::make_tuple(remainder, crc_poly_len);
}

bool CRC::check_crc(std::vector<std::bitset<8>>& message, CRC_OPTION crc_option) {
    std::tuple<std::bitset<32>, unsigned> crc = CRC::calc_crc(message, crc_option);

    std::bitset<32>val(std::get<0>(crc).to_string().substr(32-std::get<1>(crc)));

    if (val.any()) {
        return false;
    } else {
        return true;
    }
}