#!/bin/bash

COLS=$(tput cols)

function print_head {
    print_line
    echo -e "$1\n"
}

function print_line {
    printf '=%.0s' $(seq $COLS)
    printf "\n"
}

print_head ""

start=$SECONDS

echo -e "Bulding the Java Byte Code\n"
(cd PLPAssignCorrect; javac src/plpassigncorrect/PLPAssignCorrect.java src/plpassigncorrect/items.java -d bin/)

echo -e "\nBuilding the C executable Code\n"
gcc main.c -o gst-c

rm -r mem_report &> /dev/null
mkdir mem_report

echo -e "Testing Memory Usage for Java\n"

memusage java -cp PLPAssignCorrect/bin/ plpassigncorrect.PLPAssignCorrect |& sed -r "s/\x1B\[([0-9]{1,2}(;[[0-9]{1,2})?)[mGK]//g" |& tee mem_report/java_mem.txt

echo -e "Testing Memory Usage for C\n"

memusage ./gst-c |& sed -r "s/\x1B\[([0-9]{1,2}(;[[0-9]{1,2})?)[mGK]//g" |& tee mem_report/c_mem.txt

# Perf Report Directory
rm -r perf_report &> /dev/null
mkdir perf_report

echo -e "Testing Performance Stats for Java\n"
perf stat java -cp PLPAssignCorrect/bin/ plpassigncorrect.PLPAssignCorrect |& tee perf_report/java_perf_stat.txt

echo -e "Testing Performance Stats for C\n"
perf stat ./gst-c |& tee perf_report/c_perf_stat.txt

echo -e "Running perf record and saving the output (could take a while ..)\n"
perf record -s java -cp PLPAssignCorrect/bin/ plpassigncorrect.PLPAssignCorrect
mv perf.data perf_report/java_perf.data
perf report --stdio -i perf_report/java_perf.data |& tee perf_report/java_perf_report.txt

perf record -s gst-c
mv perf.data perf_report/c_perf.data
perf report --stdio -i perf_report/c_perf.data |& tee perf_report/c_perf_report.txt

echo -e "Perf records saved in perf_report/\n"

rm -r *.data &> /dev/null

duration=$(( SECONDS-start ))
echo -e "testing took $duration seconds\n"

print_head ""
