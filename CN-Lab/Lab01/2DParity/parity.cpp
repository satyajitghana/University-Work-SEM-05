#include "parity.hpp"

#include <iostream>

ParityData::ParityData(
    const std::vector<unsigned short>& data, 
    unsigned short split, 
    PARITY_OPTION parity_option = EVEN) {
        if (data.size() % split != 0) {
            throw "CANNOT SPLIT!";
        }
        this -> parity_option = parity_option;

        unsigned rows = split;
        unsigned cols = data.size() / split;
        this -> nrows = rows;
        this -> ncols = cols;

        // create our data matrix
        for (unsigned i = 0 ; i < rows ; i++) {
            std::vector<unsigned short> temp;
            for (unsigned j = 0 ; j < cols ; j++) {
                temp.push_back(data.at( i*cols+j ));
            }
            this -> data.push_back(temp);

            // meanwhile calculate the parity bit and push it as well
            unsigned short row_parity_bit = ParityData::calculate_parity_bit(temp, parity_option);
            this -> row_parity_bits.push_back(row_parity_bit);
        }

        // calculate the column parity bits
        for (unsigned j = 0 ; j < cols ; j++) {
            std::vector<unsigned short> temp;
            for (unsigned i = 0 ; i < rows ; i++) {
                temp.push_back(this -> data.at(i).at(j));
            }

            unsigned short col_parity_bit = ParityData::calculate_parity_bit(temp, parity_option);
            this -> column_parity_bits.push_back(col_parity_bit);
        }

        for (unsigned i = 0 ; i < rows ; i++) {
            for (unsigned j = 0 ; j < cols ; j++) {
                std::cout << this -> data.at(i).at(j);
            }
            std::cout << this -> row_parity_bits.at(i);
        }
        for (unsigned i = 0 ; i < this -> column_parity_bits.size() ; i++) {
            std::cout << this -> column_parity_bits.at(i);
        }
        std::cout << std::endl;

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


bool ParityData::check_with_received(const std::vector<unsigned short>& to_check) {

    // check the row parity bits
    for (unsigned i = 0 ; i < this -> nrows ; i++) {
        unsigned parity_found = to_check.at((i * (this -> ncols + 1)) + this -> ncols);
        unsigned parity_expected = this -> row_parity_bits.at(i);

        if (parity_found != parity_expected) {
            return false;
        }
    }

    // check the column parity bits
    for (unsigned j = 0 ; j < this -> ncols ; j++) {
        // do the math okay ? i'm dumb i have no clue how i did this
        unsigned parity_found = to_check.at( (this -> nrows * (this -> ncols + 1)) + j);
        unsigned parity_expected = this -> column_parity_bits.at(j);

        if (parity_found != parity_expected) {
            return false;
        }
    }

    return true;
}
