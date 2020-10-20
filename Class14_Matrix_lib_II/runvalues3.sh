for N in 1 2 10 100 200 500 1000; do
    echo -n "$N  "
    ./valores_propios3.x $N 10
done > valores_propios3.txt

