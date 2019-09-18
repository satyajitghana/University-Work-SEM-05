#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> vec) {
    out << "[ ";
    for (auto& e : vec) {
        out << e << ", ";
    }
    out << "]" << std::endl;

    return out;
}

int main(int, char**) {
    using namespace std;
    cout << "Go back N " << endl;
    int window_size, tot_elems;
    cout << "Enter the Window size and Number of Elements : ";
    cin >> window_size >> tot_elems;
    // cout << "Enter the " << tot_elems << " Elements : ";
    std::vector<int> message(tot_elems);
    for (int i = 0 ; i < message.size() ; i++) {
        message[i] = i;
    }

    int N = window_size;
    std::vector<int>::iterator start = message.begin();
    std::vector<int>::iterator end = message.begin() + N >= message.end() ? message.end() : message.begin() + N;

    while (end <= message.end()) {
        std::vector<int> to_trasmit(start, end);

        cout << "TRANSMITTING " << to_trasmit;
        // for (auto& e : to_trasmit) {
        //     cout << e << " ";
        // }
        // cout << "]" << endl;

        int error_at;
        cout << "Enter the frame index if there was a bit error elese enter -1 : ";
        cin >> error_at;

        auto old_start = start;
        // error occured
        if (error_at != -1) {
            start = message.begin() + error_at;
        } else { // no error has occured
            start = end;
        }

        std::vector<int> recieved(old_start, start);
        cout << "RECIEVED : " << recieved;

        // check if we successfully transmitted the last bit
        if (end == message.end())
            break;

        end = start + N >= message.end() ? message.end() : start + N; 
    }
}
