#pragma once

#include <vector>

enum PARITY_OPTION {
    EVEN,
    ODD
};

class ParityData {
    public:
        ParityData(const std::vector<unsigned short> &data,  unsigned short split, PARITY_OPTION option);
        bool check_with_received(const std::vector<unsigned short>& data);
        static unsigned short calculate_parity_bit(const std::vector<unsigned short> &data, PARITY_OPTION option);
    private:
        std::vector<std::vector<unsigned short>> data;
        std::vector<unsigned short> row_parity_bits;
        std::vector<unsigned short> column_parity_bits;
        unsigned nrows, ncols;
        PARITY_OPTION parity_option;
};