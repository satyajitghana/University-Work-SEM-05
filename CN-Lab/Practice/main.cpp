#include <iostream>

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int, char**) {
    int data[20];
    int poly[20];

    int data_len;
    int poly_len;

    cout << "Enter no. of bits in data : ";
    cin >> data_len;

    cout << "Enter the data bits : ";
    for (int i = 0; i < data_len; i++)
        cin >> data[i];

    cout << "Enter the no. of bits in CRC : ";
    cin >> poly_len;

    cout << "Enter the CRC bits : ";
    for (int i = 0; i < poly_len; i++)
        cin >> poly[i];

    // append poly_len-1 no. of zeros to data;
    for (int i = data_len; i < data_len + poly_len - 1; i++) {
        data[i] = 0;
    }

    // copy message to temp;
    int temp[20];
    for (int i = 0; i < data_len + poly_len - 1; i++) {
        temp[i] = data[i];
    }

    // division
    for (int i = 0; i < data_len; i++) {
        if (temp[i] == 1) {
            int k = 0;
            for (int j = i; j < i + poly_len; j++, k++) {
                if ((temp[j] == 0 && poly[k] == 0) || (temp[j] == 1 && poly[k] == 1)) {
                    temp[j] = 0;
                } else {
                    temp[j] = 1;
                }
            }
        } else {
            continue;
        }
    }

    cout << "The CRC is : ";
    for (int i = data_len; i < data_len + poly_len - 1; i++) {
        cout << temp[i];
    }
    cout << endl;
}
