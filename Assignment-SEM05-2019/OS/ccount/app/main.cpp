// C++ Includes
#include <algorithm>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <vector>

// C Includes
#include <dirent.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// User defined Includes
#include "file_ops.hpp"
#include "threader.hpp"

void help(char name[]);

int main(int argc, char** argv) {
    std::vector<std::shared_ptr<bromine::file>> files;

    bool is_directory = false;
    bool is_threaded = false;

    int opt;
    while ((opt = getopt(argc, argv, ":dt")) != -1) {
        switch (opt) {
            case 'd':
                is_directory = true;
                break;
            case ':':
                std::cout << "MISSING FOLDER NAME";
                help(argv[0]);
                exit(EXIT_FAILURE);
                break;
            case '?':
                std::cout << "UNKNOWN OPTION : " << argv[optind];
                break;
            case 't':
                is_threaded = true;
                break;
        }
    }

    if (is_directory) {
        // directory path used
        DIR* d;
        struct dirent* dir;

        d = opendir(argv[optind]);
        if (d) {
            while ((dir = readdir(d)) != nullptr) {
                if (dir->d_type == DT_REG) {
                    std::string rel_path(dir->d_name);
                    rel_path = std::string(argv[optind]) + "/" + rel_path;
                    std::shared_ptr<bromine::file> ptr(new bromine::file(rel_path));
                    files.emplace_back(ptr);
                }
            }
        } else {
            std::cerr << "ERROR OPENING DIRECTORY " << argv[2] << std::endl;
            exit(EXIT_FAILURE);
        }
    } else {
        if (argc == 1) {
            help(argv[0]);
            exit(EXIT_FAILURE);
        }

        for (; optind < argc; optind++) {
            // files are specified in argv
            for (int i = 1; i < argc; i++) {
                std::shared_ptr<bromine::file> ptr(new bromine::file(argv[optind]));
                files.emplace_back(ptr);
            }
        }
    }

    std::vector<void*> results;

    if (is_threaded) {  // MULTITHREADED
        // transform into void* vector
        std::vector<void*> fargs(files.size());
        std::transform(files.begin(), files.end(), fargs.begin(), [](std::shared_ptr<bromine::file> p) {
            return static_cast<void*>(p.get());
        });

        // generate and run threads
        std::vector<pthread_t> threads = bromine::threader::gen_worker_threads(&bromine::file::threadable_ccount_fun, fargs);
        results = bromine::threader::get_threads_results(threads);
    } else {  // SEQUENCIAL
        for (auto& file : files) {
            std::map<char, int>* ccount = new std::map<char, int>();
            *ccount = file.get()->get_char_count();
            results.emplace_back(static_cast<void*>(ccount));
        }
    }

    // var to store the accumulated results
    std::map<char, int> accumulated_vals;

    // accumulate the results in the main thread
    for (auto& result : results) {
        std::map<char, int> ccount = *static_cast<std::map<char, int>*>(result);
        for (auto& elem : ccount) {
            if (accumulated_vals[elem.first]) {
                accumulated_vals[elem.first] += elem.second;
            } else {
                accumulated_vals[elem.first] = elem.second;
            }
        }
    }

    std::cout << "ACCUMULATED COUNT" << std::endl;
    bromine::file::print_ccount(accumulated_vals);
}

void help(char name[]) {
    std::cerr << "USAGE : " << name << " <option(s)> SOURCES\n"
              << "Options:\n"
              << "\t-t\t\tEnable Threading\n"
              << "\t-d\t\tUse Directory\n"
              << "\nExample Usages : \n"
              << name << " -dt test_files\n"
              << name << " meow.txt test.txt\n"
              << "\nLEGEND:"
              << "\n[ <ascii value> ] -> <char_count>"
              << "\n{ <char> } -> <char_count>"
              << std::endl;
}
