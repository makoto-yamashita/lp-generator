#!/bin/bash


g++ -o lpgenerator.exe lpgenerator.cpp

marray=(3  5 10  50  50 100 100 200 200)
narray=(8 10 20 100 200 300 500 300 500)
length=$((${#marray[@]}-1))
echo $length
for i in {0..8}; do
    for seed in {1024..1029}; do
	# echo ${i}, m=${marray[${i}]}, n=${narray[${i}]}, seed=${seed}
	./lpgenerator.exe ${marray[${i}]} ${narray[${i}]} ${seed}
    done
done

mkdir -p problems
mv problem-*.txt problems
rm -f lpgenerator.exe
