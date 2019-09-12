#!/bin/bash

> ./ex1.out

for i in {0..9}
do
    ./ex1 >> ./ex1.out
done