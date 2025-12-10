
function greet() {
    echo "Hello, $1!"
}


greet_user() {
    local NAME=$1
    echo "Hello, $NAME!"
}


greet "Alice"
greet_user "Bob"


add_numbers() {
    local NUM1=$1
    local NUM2=$2
    local SUM=$((NUM1 + NUM2))
    echo $SUM
}

RESULT=$(add_numbers 10 20)
echo "Result: $RESULT"


check_file() {
    if [ -f "$1" ]; then
        return 0
    else
        return 1
    fi
}

if check_file "test.txt"; then
    echo "File exists"
else
    echo "File not found"
fi
