#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>

using block_list_t = std::list<std::pair<char, int>>;
using proc_list_t = std::list<std::pair<char, int>>;

std::ostream& operator<<(std::ostream& out, std::list<std::pair<char, int>> list) {
    out << "START -> ";
    for (auto [mem_name, mem_size] : list) {
        out << mem_name << " " << mem_size << " -> ";
    }
    out << "END" << std::endl;

    return out;
}

void worst_fit(block_list_t blist, proc_list_t plist) {
    std::cout << "Worst Fit" << std::endl;

    for (auto [proc_name, proc_mem] : plist) {
        block_list_t::iterator worst = blist.end();
        for (auto it = blist.begin(); it != blist.end(); it++) {
            auto [block_name, block_size] = *it;
            if (block_name != 'H')
                continue;

            if (block_size >= proc_mem) {
                if (worst == blist.end())
                    worst = it;
                else if (block_size > worst->second)
                    worst = it;
            }
        }

        // found the worst fit
        if (worst != blist.end()) {
            auto [block_name, block_size] = *worst;
            int rem_mem = block_size - proc_mem;
            if (rem_mem > 0) {
                (*worst) = {proc_name, proc_mem};
                blist.insert(std::next(worst), {'H', rem_mem});
            } else if (rem_mem == 0) {
                (*worst) = {proc_name, proc_mem};
            }
        }
    }

    std::cout << "Memory Allocation List" << std::endl;
    std::cout << blist;
}

void best_fit(block_list_t blist, proc_list_t plist) {
    std::cout << "Best Fit" << std::endl;

    for (auto [proc_name, proc_mem] : plist) {
        block_list_t::iterator best = blist.end();
        for (auto it = blist.begin(); it != blist.end(); it++) {
            auto [block_name, block_size] = *it;
            if (block_name != 'H')
                continue;

            if (block_size >= proc_mem) {
                if (best == blist.end())
                    best = it;
                else if (block_size < best->second)
                    best = it;
            }
        }

        // found the best fit
        if (best != blist.end()) {
            auto [block_name, block_size] = *best;
            int rem_mem = block_size - proc_mem;
            if (rem_mem > 0) {
                (*best) = {proc_name, proc_mem};
                blist.insert(std::next(best), {'H', rem_mem});
            } else if (rem_mem == 0) {
                (*best) = {proc_name, proc_mem};
            }
        }
    }

    std::cout << "Memory Allocation List" << std::endl;
    std::cout << blist;
}

void first_fit(block_list_t blist, proc_list_t plist) {
    std::cout << "First Fit" << std::endl;

    for (auto [proc_name, proc_mem] : plist) {
        for (auto it = blist.begin(); it != blist.end(); it++) {
            auto [block_name, block_size] = *it;
            if (block_name != 'H')
                continue;

            int rem_mem = block_size - proc_mem;
            if (rem_mem > 0) {
                (*it) = {proc_name, proc_mem};
                blist.insert(std::next(it), {'H', rem_mem});
                break;
            } else if (rem_mem == 0) {
                (*it) = {proc_name, proc_mem};
                break;
            }
        }
    }

    std::cout << "Memory Allocation List" << std::endl;
    std::cout << blist;
}

int main(int argc, char* argv[]) {
    block_list_t block_list{{'H', 100}, {'H', 500}, {'H', 200}, {'H', 300}, {'H', 600}};
    proc_list_t proc_list{{'A', 212}, {'B', 417}, {'C', 112}, {'D', 426}};

    std::cout << "Memory Before Allocation" << std::endl;
    std::cout << block_list;
    std::cout << "Process List" << std::endl;
    std::cout << proc_list;

    std::cout << std::endl;
    first_fit(block_list, proc_list);

    std::cout << std::endl;
    best_fit(block_list, proc_list);

    std::cout << std::endl;
    worst_fit(block_list, proc_list);

    return EXIT_SUCCESS;
}