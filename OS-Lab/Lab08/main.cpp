#include <iostream>
#include <vector>

int main(int, char**) {
    int n = 5;  // number of processes
    int m = 3;  // number of resources

    using matrix = std::vector<std::vector<int>>;

    matrix alloc{{0, 1, 0},
                 {2, 0, 0},
                 {3, 0, 2},
                 {2, 1, 1},
                 {0, 0, 2}};

    matrix max{{7, 5, 3},
               {3, 2, 2},
               {9, 0, 2},
               {2, 2, 2},
               {4, 3, 3}};

    std::vector<int> avail{3, 3, 2};

    matrix need;

    for (int i = 0; i < n; i++) {
        std::vector<int> temp;
        for (int j = 0; j < m; j++) {
            temp.push_back(max.at(i).at(j) - alloc.at(i).at(j));
        }
        need.push_back(temp);
    }

    int y = 0;
    std::vector<int> f(n);
    std::vector<int> ans;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f.at(i) == 0) {
                int flag = 0;

                for (int j = 0; j < m; j++) {
                    if (need.at(i).at(j) > avail.at(j)) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans.push_back(i);
                    for (int y = 0; y < m; y++)
                        avail.at(y) += alloc.at(i).at(y);
                    f.at(i) = 1;
                }
            }
        }
    }

    std::cout << "The Safe Sequence is : " << std::endl;
    for (auto a : ans)
        std::cout << "P" << a << " -> ";
    std::cout << "END" << std::endl;
}
