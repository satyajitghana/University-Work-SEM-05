#pragma once

#include <vector>

enum PARITY_OPTION {
    EVEN,
    ODD
};

class ParityData {
    public:
        ParityData(const std::vector<unsigned short> &data, PARITY_OPTION option);
        bool check_with_received(const std::vector<unsigned short>& data, const unsigned short& parity_bit);
        static unsigned short calculate_parity_bit(const std::vector<unsigned short> &data, PARITY_OPTION option);
        unsigned short get_parity_bit() { return this -> parity_bit; };
    private:
        const std::vector<unsigned short> data;
        unsigned short parity_bit;
        PARITY_OPTION parity_option;
};