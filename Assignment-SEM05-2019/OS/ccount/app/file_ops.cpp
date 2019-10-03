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
*/
bromine::file::file(std::string file_name) : file_name(file_name) {
    this->open(this->file_name);
}

/**
 * Destructor
*/
bromine::file::~file() {
    if (!isclosed) {
        std::cout << "CLOSING " << this->file_name << std::endl;
        close(this->fd);
    }
    this->isclosed = true;
}

void bromine::file::open(std::string file_name) {
    this->file_name = file_name;

    if (this->fd = ::open(this->file_name.c_str(), O_RDONLY); this->fd != -1) {
        std::cout << "SUCCESSFULLY OPENED " << file_name << std::endl;
        this->isclosed = false;
    } else {
        throw std::runtime_error("ERROR OPENING FILE");
    }
}

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
        // std::cout << "#" << buffer[0] << "#";
        ccount[buffer[0]]++;
    }

    return ccount;
}

void* bromine::file::threadable_ccount_fun(void* file_obj) {
    bromine::file* file = static_cast<bromine::file*>(file_obj);

    auto ccount = new std::map<char, int>(file->get_char_count());

    return static_cast<void*>(ccount);
}

void bromine::file::print_ccount(const std::map<char, int>& ccount) {
    for (auto& elem : ccount) {
        if (isalnum(elem.first)) {
            std::cout << "{ " << elem.first << " } -> " << elem.second << ", ";
        } else {
            std::cout << "[ " << static_cast<unsigned>(elem.first) << " ] -> " << elem.second << ", ";
        }
    }
    std::cout << std::endl;
}
