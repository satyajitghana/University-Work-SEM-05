#!/bin/bash
for n in $(seq 1 $1); do
    < /dev/urandom tr -dc "\n [:alnum:]" | head -c$2 > $( printf %04d "$n" ).txt
done