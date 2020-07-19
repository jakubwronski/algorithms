make gen
make brute
make alg

for((i=0;i<10000;i++))
do
    echo $i
    echo $i > seed
    ./gen seed > input
    ./alg < input > alg.out
    ./brute < input > brute.out 

    diff -w alg.out brute.out || break

done