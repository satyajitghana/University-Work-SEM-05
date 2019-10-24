#include <iostream>
#include <list>

using block_list_t = std::list<std::pair<char, int>>;
using proc_list_t = std::list<std::pair<char, int>>;

void first_fit(block_list_t blist, proc_list_t plist) {
    std::cout << "First Fit -----------" << std::endl;

    for (auto [proc_name, proc_mem] : plist) {
        for (auto it = blist.begin(); it != blist.end(); it++) {
            auto [block_name, block_size] = *it;
            int rem_mem = block_size - proc_mem;
            if (rem_mem > 0) {
                blist.emplace(it, proc_name, proc_mem, 'H', rem_mem);
            } else if (rem_mem == 0) {
                blist.emplace(it, proc_name, proc_mem);
            }
        }
    }

    for (auto [mem_name, mem_size] : blist) {
        std::cout << mem_name << " " << mem_size << " -> ";
    }
}

int main(int argc, char* argv[]) {
    block_list_t block_list{{'H', 100}, {'H', 500}, {'H', 200}, {'H', 300}, {'H', 600}};
    proc_list_t proc_list{{'A', 212}, {'B', 417}, {'C', 112}, {'D', 426}};

    first_fit(block_list, proc_list);
    return EXIT_SUCCESS;
}