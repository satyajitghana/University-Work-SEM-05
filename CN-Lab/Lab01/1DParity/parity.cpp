#include "parity.hpp"

ParityData::ParityData(const std::vector<unsigned short>& data, PARITY_OPTION parity_option = EVEN) : data(data) {
    this -> parity_option = parity_option;
    this -> parity_bit = ParityData::calculate_parity_bit(data, this -> parity_option);
}

unsigned short ParityData::calculate_parity_bit(const std::vector<unsigned short>& data, PARITY_OPTION parity_option) {
    unsigned count = 0;

    for (auto e : data) {
        if (e == 1) {
            count++;
        }
    }

    bool is_count_even = count % 2 == 0;

    unsigned short parity_bit;

    switch(parity_option) {
        case EVEN:
            parity_bit = is_count_even == true ? 0 : 1;
            break;
        case ODD:
            parity_bit = is_count_even == true ? 1 : 0;
            break;
    }

    return parity_bit;
}


bool ParityData::check_with_received(const std::vector<unsigned short>& to_check, const unsigned short& parity_bit) {
    unsigned short parity_bit_expected = ParityData::calculate_parity_bit(to_check, this -> parity_option);
    bool is_correct = parity_bit == parity_bit_expected ? true : false;

    return is_correct;
}
