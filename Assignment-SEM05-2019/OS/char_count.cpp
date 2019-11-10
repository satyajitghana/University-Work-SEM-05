#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <map>

/*creating a hashmap to map each character
  with its frequency*/
typedef std::map<char, int> CharIntMap;

struct package {
    std::string s;
    CharIntMap character;
} bundle[3];

/*overloading the << operator for ease of 
  printing */
std::ostream& operator<<(std::ostream& out, CharIntMap ch) {
    //generalized statement for printing maps
    out << "[character] "
        << "->"
        << " \t[frequency]" << std::endl;
    for (auto [ch, freq] : ch) {
        out << "   [" << ch << "]\t    "
            << "->\t [" << freq << "]\n"
            << std::endl;
    }

    return out;
}

/*function to count character frequencies
  for each file*/

// function accepts two parameters:-
// 1. string s which holds the filename.
// 2. CharIntMap which is a character, integer
//    map
void* charcount(void* argc) {
    package* x = (package*)argc;
    //opening file
    // c.str() converts the string in s into valid
    // c string format which is read by function  open
    int input_fd = open(x->s.c_str(), O_RDONLY);

    if (input_fd == -1) {  //if open returned an error
        std::cout << "file error" << std::endl;
    }

    //initializing buffer
    char buffer;

    /*reading the file into buffer byte by 
      byte untill it reaches EOF */
    while (read(input_fd, &buffer, 1) == 1) {
        //assign key value and count to the map
        x->character[buffer]++;
    }

    //printing the frequency for a file
    std::cout << "CHAR COUNT FOR " << x->s << "\n"
              << x->character;
}

//driver function
int main(void) {
    //initializing thread
    pthread_t thread[3];

    //creating an array of maps
    CharIntMap character[3];

    //printing other stuff
    std::cout << "Welcome\n"
              << std::endl;
    std::cout << "This programe will analyze the file content &" << std::endl;
    std::cout << "compute the statistics of the file you input.\n"
              << std::endl;
    std::cout << "\n";

    bundle[0].s = "sample_1.txt";
    bundle[1].s = "sample_2.txt";
    bundle[2].s = "sample_3.txt";

    /*calling the character counter function 
      parallely using threads*/

    for (int i = 0; i < 3; i++) {
        pthread_create(&thread[i], NULL, charcount, &bundle[i]);
    }

    // join the threads
    for (int i = 0; i < 3; i++) {
        pthread_join(thread[i], NULL);
    }

    /*creating a map to count total frequency of
      a character*/
    CharIntMap total;

    for (auto bundle_ : bundle) {
        for (auto [ch, freq] : bundle_.character) {
            //if key already present, update value
            if (total[ch]) {
                total[ch] += bundle_.character[ch];
            }
            //else add key and its associated value
            // to the map
            else {
                total[ch] = bundle_.character[ch];
            }
        }
    }

    //print total char count
    std::cout << "TOTAL CHAR COUNT"
              << "\n"
              << total;

    return 0;
}