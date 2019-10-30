// user includes
#include "file_ops.hpp"

// system includes
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <memory>
#include <utility>

/**
 * Constructor
 * @param string file_name
 * @return object of bromine::file
*/
bromine::file::file(std::string file_name) : file_name(file_name) {
    this->open(this->file_name);
}

/**
 * Destructor
 * close the file if it was open
*/
bromine::file::~file() {
    if (!isclosed) {
        // for debugging
        // std::cout << "CLOSING " << this->file_name << std::endl;
        close(this->fd);
    }
    this->isclosed = true;
}

/**
 * Opens the file, given the file_name
 * @param string file_name
 * @return none
*/
void bromine::file::open(std::string file_name) {
    this->file_name = file_name;

    if (this->fd = ::open(this->file_name.c_str(), O_RDONLY); this->fd != -1) {
        // std::cout << "SUCCESSFULLY OPENED " << file_name << std::endl;
        this->isclosed = false;
    } else {
        throw std::runtime_error("ERROR OPENING FILE : " + file_name);
    }
}

/**
 * Gets the character count from the file
 * @param none
 * @return map of char, int which is the character count
*/
std::map<char, int> bromine::file::get_char_count() {
    std::map<char, int> ccount;

    if (this->fd < 0) {
        std::cerr << "FILE ERROR" << std::endl;
        return ccount;
    }

    char buffer[2];

    // seek to start of the file
    lseek(this->fd, 0, SEEK_SET);

    while (read(this->fd, &buffer, 1) == 1) {
        // for debugging
        // std::cout << "#" << buffer[0] << "#";

        // increment the character count of the character
        ccount[buffer[0]]++;
    }

    return ccount;
}

/**
 * Threadable Character Count function which can be passed
 * to gen_worker_threads function in threader library
*/
void* bromine::file::threadable_ccount_fun(void* file_obj) {
    bromine::file* file = static_cast<bromine::file*>(file_obj);

    // how stupid am i to use RAW pointer ?
    // never use RAW pointer, use unique pointer and Move Semantics
    // and make use of RVO (Return Value Optimization)
    auto ccount = new std::map<char, int>(file->get_char_count());

    // thread count needs to be type casted to void*
    return static_cast<void*>(ccount);
}

/**
 * Prints the Character Count
 * @param map<char, int> ccount
 * @return none
*/
void bromine::file::print_ccount(const std::map<char, int>& ccount) {
    // elem.first is the character
    // elem.second is the character count
    for (auto& elem : ccount) {
        if (isalnum(elem.first)) {
            std::cout << "{ " << elem.first << " } -> " << elem.second << ", ";
        } else {
            std::cout << "[ " << static_cast<unsigned>(elem.first) << " ] -> " << elem.second << ", ";
        }
    }
    std::cout << std::endl;
}
