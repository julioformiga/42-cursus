function permutate {
    if [ "${#1}" = 1 ]; then
        echo "Test:${2} ${1}"
        ./a.out "${2} ${1}"
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
