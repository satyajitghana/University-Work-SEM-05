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

start=$SECONDS

print_head "Building"
rm -rf build 2> /dev/null
mkdir build
(cd build; cmake -DCMAKE_BUILD_TYPE=Release ..; make)

# Perf Report Directory
rm -r perf_report &> /dev/null
mkdir perf_report

print_head "TESTING PROGRAM TIMES"

print_head "Generating Files"
rm -rf auto_gen_files 2> /dev/null
mkdir auto_gen_files

(cd auto_gen_files; sh ../generate_files.sh 400 40000)

echo -e "Generated 400 files with 40000 characters each\n"

print_head "Single Threaded Run"

perf stat build/app/ccount -d auto_gen_files |& tee perf_report/perf_stat_st.txt

print_head "Multi Threaded Run"

perf stat build/app/ccount -dt auto_gen_files |& tee perf_report/perf_stat_mt.txt

# Run Perf Benchmarks and save to file
print_head "Running Perf . . . (could take a while) "

# single threaded run
perf record -s build/app/ccount -d auto_gen_files
mv perf.data perf_report/perf_st.data
perf report --stdio -i perf_report/perf_st.data |& tee perf_report/perf_report_st.txt

# multi threaded run
perf record -s build/app/ccount -dt auto_gen_files
mv perf.data perf_report/perf_mt.data
perf report --stdio -i perf_report/perf_mt.data |& tee perf_report/perf_report_mt.txt

echo -e "perf records and output saved to perf_report/\n"

duration=$(( SECONDS - start ))
echo -e "testing took $duration seconds\n"


# print_head "Cleaning Up"
# rm -r auto_gen_files 2> /dev/null
