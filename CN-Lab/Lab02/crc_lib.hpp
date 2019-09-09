#pragma once

#include <bitset>
#include <vector>
#include <tuple>

enum CRC_OPTION {
    CRC8, CRC10, CRC16, CRC32
};

class CRC {
public:
    static std::tuple<std::bitset<32>, unsigned> calc_crc(std::vector<std::bitset<8>> &message, CRC_OPTION crc_option);
    static std::tuple<std::bitset<32>, unsigned> get_crc_polynomial(CRC_OPTION CRC_OPTION);
    static bool check_crc(std::vector<std::bitset<8>>& message, CRC_OPTION crc_option);
};
