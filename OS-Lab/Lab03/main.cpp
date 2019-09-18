#include <iostream>
#include <vector>
#include <numeric>

#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// program parameters
#define TOTAL_SUBJECTS 10
#define NUM_STUDENTS 10

class Student {
    public:
        Student(int nsubjects, bool rand_init);
        unsigned short get_mark_of_subject(int idx);
        unsigned int get_total();
        unsigned int get_id() { return this -> id; };
    
    friend std::ostream& operator<<(std::ostream& out, Student student);
    private:
        unsigned int id;
        std::vector<unsigned short> subject_marks;
};

Student::Student(int nsubjects = TOTAL_SUBJECTS, bool rand_init = true) : subject_marks(nsubjects), id(rand()) {
    if (rand_init) {
        for (auto& subject : subject_marks) {
            subject = rand() % 10;
        }
    }
}

std::ostream& operator<<(std::ostream& out, Student student) {
    out << "{ ID: " << student.id << ", Marks : [ ";
    for (auto mark : student.subject_marks) {
        out << mark << ", ";
    }
    out << "], }";

    return out;
}

unsigned short Student::get_mark_of_subject(int idx) {
    if (idx >= subject_marks.size()) {
        throw "idx out of range";
    }

    return subject_marks.at(idx);
}

unsigned int Student::get_total() {
    return std::accumulate(this -> subject_marks.begin(), this -> subject_marks.end(), 0);
}

struct thread_data {
    unsigned int thread_idx;
    Student student;
    unsigned int total_marks;
};

void* my_thread_fun(void* vargp) {
    thread_data* this_data = (thread_data*) vargp;

    std::cout.sync_with_stdio(true);

    std::cout << "[ Thread ID : " << pthread_self() << " ]"<< std::endl;
    std::cout << "Total Marks for Student ID : " << this_data -> student.get_id() << " is : " << this_data -> student.get_total() << std::endl;

    this_data -> total_marks = this_data -> student.get_total();

    std::cout << std::endl;

    return NULL;
}

void* say_hello(void* vargp) {

    std::cout << "Hello World from Thread : " << *(pthread_t*)vargp << std::endl;

    return NULL;
}

#define NUM_THREADS NUM_STUDENTS

thread_data thr_data[NUM_THREADS];

int main(int, char**) {
    std::cout.sync_with_stdio(true);

    pthread_t thread_id[3];

    // Say Hello from 3 different threads
    for (short i = 0 ; i < 3 ; i++) {
        if ((pthread_create(&thread_id[i], NULL, say_hello, &thread_id[i])) < 0) {
            std::cerr << "Error creating thread" << std::endl;

            return EXIT_FAILURE;
        }
    }

    for (short i = 0 ; i < 3 ; i++) {
        pthread_join(thread_id[i], NULL);
    }

    std::cout << std::endl;

    std::cout << "[ Running with " << NUM_THREADS << " Threads ]\n" << std::endl;
    // create the students and randomly initialize them

    std::vector<Student> students(NUM_THREADS);

    for (auto student: students) {
        std::cout << student << std::endl;
    }
    std::cout << std::endl;

    // create the threads

    pthread_t thrs[NUM_THREADS];

    for (short i = 0 ; i < NUM_THREADS ; i++) {
        thr_data[i].thread_idx = i;
        thr_data[i].student = students.at(i);

        int rc;
        if (rc = pthread_create(&thrs[i], NULL, my_thread_fun, &thr_data[i])) {
            std::cerr << "Error : Cannot create thread " << thrs[i] << std::endl;
            return EXIT_FAILURE;
        }
    }

    // block until all threads are completed
    for (short i = 0 ; i < NUM_THREADS ; i++) {
        pthread_join(thrs[i], NULL);
    }

    // check who has the highest marks
    int max_idx = 0;
    int max_marks = thr_data[0].total_marks;

    for (int i = 0 ; i < NUM_THREADS ; i++) {
        if (thr_data[i].total_marks > max_marks) {
            max_marks = thr_data[i].total_marks;
            max_idx = i;
        }
    }

    std::cout << "\nMax Marks is " << max_marks << " Obtained by Student ID : " << thr_data[max_idx].student.get_id() << std::endl; 

    pthread_exit(NULL);

    return 0;
}
