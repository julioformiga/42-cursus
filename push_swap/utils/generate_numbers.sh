function permutate {
    if [ "${#1}" = 1 ]; then
        ARGS="${2} ${1}"
        echo "Test:$ARGS"
        echo -n "Mosse: "
        ./a.out $ARGS | wc -l
        ./a.out $ARGS | ./checker_linux $ARGS
        # ./a.out $ARGS
    else
        for i in $(seq 0 $((${#1}-1)) ); do
            pre="${2} ${1:$i:1}"
            seg1="${1:0:$i}"
            seg2="${1:$((i+1))}"
            seg="${seg1}${seg2}"
            permutate "$seg" "$pre"
        done
    fi
}

permutate $1
