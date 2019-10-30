#pragma once

#include <map>
#include <string>

namespace bromine {

class file {
   private:
    // file name
    std::string file_name;
    // the file descriptor
    int fd;
    // to check if the file is closed
    bool isclosed = true;

   public:
    file() {
        file_name = "";
        fd = 0;
    };
    file(std::string file_name);
    ~file();

    // fetch the file descriptor
    int get_fd() { return this->fd; };

    /**
     * Returns the character count
     * @param none
     * @return character count as a map
    */
    std::map<char, int> get_char_count();

    /**
     * Opens the file
     * @param file name as a string
     * @return none
    */
    void open(std::string file_name);
    std::string get_file_name() { return this->file_name; };

    // char count function
    static void print_ccount(const std::map<char, int>& ccount);
    // threadable char count
    static void* threadable_ccount_fun(void*);
};

}  // namespace bromine
