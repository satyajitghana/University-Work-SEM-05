#include <iostream>

#include <ctype.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct file_props {
    pthread_t tid;
    char file_name[20];
    int vowel_count;
    bool is_valid;
};

bool is_vowel(char ch) {
    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return true;

    return false;
}

/**
 * Thread-able function to modify the vowels
*/
void* thread_replace_vowels(void* arg) {
    file_props* farg = (file_props*)arg;

    printf("[TID %lu] : Processing file %s\n", farg->tid, farg->file_name);

    // open the file in read_write mode
    int input_file;
    if ((input_file = open(farg->file_name, O_RDWR)) < 0) {
        printf("[TID %lu] : Error opening file %s\n", farg->tid, farg->file_name);
        farg->is_valid = false;
        return NULL;
    } else {
        farg->is_valid = true;
    }

    //  buffer of one character + null character
    char buffer[2];

    // start to parse the file byte at a time
    while (read(input_file, buffer, 1)) {
        char ch = buffer[0];
        // if its an alphabet, and is upper case and also a vowel
        if (isalpha(ch) && isupper(ch) && is_vowel(ch)) {
            // make it lower
            buffer[0] = tolower(buffer[0]);
            // seek back a character
            lseek(input_file, -1, SEEK_CUR);
            // write the lower case character
            write(input_file, buffer, 1);
            // increment the count
            (farg->vowel_count)++;
        }
    }

    close(input_file);

    return NULL;
}

int fileio() {
    file_props files[] = {{0, "test.txt", 0}, {0, "meow.txt", 0}};
    int n_files = sizeof(files) / sizeof(files[0]);

    for (int i = 0; i < n_files; i++) {
        pthread_create(&(files[i].tid), NULL, thread_replace_vowels, files + i);
    }

    int total_alterations = 0;
    int files_successfully_processed = 0;
    int* ret_value;
    for (int i = 0; i < n_files; i++) {
        pthread_join(files[i].tid, NULL);
        total_alterations += files[i].vowel_count;
        if (files[i].is_valid)
            files_successfully_processed++;
    }

    printf("Processed %d/%d files and made %d alterations\n", files_successfully_processed, n_files, total_alterations);

    return EXIT_SUCCESS;
}