#!/bin/bash

for file in submit/*.zip
do
    id=$(grep -Eo '[0-9]{10}' <<< $file)
    # echo $id
    mkdir results/$id
    cp btree_map.h btree_set.h btree.h die.cc die.h results/$id
    unzip -qo $file -d results/$id
    cd results/$id
    make -B main
    for i in $(seq 1 7)
    do
        echo $id:$i
        timeout 100 \time -f "%e" -o $i.txt ./main < ../../$i.in > $i.out
        diff -q ../../$i.out $i.out
        if [ $? -eq 0 ];
        then
            touch $i.pass
        fi
    done
    cd ../..
done
