#!/bin/bash 
    echo "Starting integration"
    for NTH in 1 2 3 4 5 6 7 8 ; do
	echo -n "$NTH  ";
	mpirun -np $NTH --oversubscribe ./a.out ;
    done > scaling-mpi.txt | head -n 1
    
    echo "Computing metrics"
    awk 'BEGIN {TS=1.0;} { if(NR==1) TS=$2;  print $1, $2, TS/$2, TS/$2/$1}' scaling-mpi.txt > metrics-mpi.csv
    echo "Metrics saved to: metrics-int.csv"
echo "Done"
