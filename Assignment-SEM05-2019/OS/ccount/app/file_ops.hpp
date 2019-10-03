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
    bool isclosed = true;
    //  std::map<char, int> ccount;

   public:
    file() {
        file_name = "";
        fd = 0;
    };
    file(std::string file_name);
    ~file();
    int get_fd() { return this->fd; };
    std::map<char, int> get_char_count();
    void open(std::string file_name);
    std::string get_file_name() { return this->file_name; };

    // char count function
    static void print_ccount(const std::map<char, int>& ccount);
    // threadable char count
    static void* threadable_ccount_fun(void*);
};

}  // namespace bromine
