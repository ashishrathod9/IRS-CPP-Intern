
for ITEM in item1 item2 item3; do
    echo $ITEM
done

for i in {1..10}; do
    echo "Number: $i"
done

for FILE in *.txt; do
    echo "Processing: $FILE"
done

for ((i=1; i<=10; i++)); do
    echo "Count: $i"
done


FRUITS=("apple" "banana" "orange")
for FRUIT in "${FRUITS[@]}"; do
    echo "Fruit: $FRUIT"
done


for USER in $(cat /etc/passwd | cut -d: -f1); do
    echo "User: $USER"
done


COUNTER=1
while [ $COUNTER -le 5 ]; do
    echo "Count: $COUNTER"
    ((COUNTER++))
done


while IFS= read -r LINE; do
    echo "Line: $LINE"
done < temp1.sh

while true; do
    echo "Running..."
    sleep 5
done

COUNTER2=1
until [ $COUNTER2 -gt 5 ]; do
    echo "Count: $COUNTER2"
    ((COUNTER2++))
done
