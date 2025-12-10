#!/bin/bash
count=10

if [ $count -eq 10 ]
then
    echo "The condition is true"
fi

count=5

if [ $count -eq 10 ]
then
    echo "Equal to 10"
else
    echo "Not equal to 10"
fi

num=20

if [ $num -eq 10 ]
then
    echo "Number is 10"
elif [ $num -eq 20 ]
then
    echo "Number is 20"
else
    echo "Neither 10 nor 20"
fi

age=20

if [ $age -gt 18 ] && [ $age -lt 60 ]
then
    echo "Adult"
fi

age=5

if [ $age -lt 10 ] || [ $age -gt 60 ]
then
    echo "Special category"
fi

num=10

if [ $num -gt 5 ]
then
    if [ $num -lt 20 ]
    then
        echo "Between 5 and 20"
    fi
fi



count=0

for u in $(who | awk '{print $1}')
do
    echo "User: $u"
    ((count++))
done

echo "---------------------"
echo "Total users: $count"
