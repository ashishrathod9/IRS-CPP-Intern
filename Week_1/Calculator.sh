#!/bin/bash

# Calculator Script

echo "----------------------------"
echo " SIMPLE CALCULATOR (BASH) "
echo "----------------------------"

# Take first number
echo "Enter first number:"
read num1

# Take second number
echo "Enter second number:"
read num2

echo "Choose operation:"
echo "1. Addition (+)"
echo "2. Subtraction (-)"
echo "3. Multiplication (*)"
echo "4. Division (/)"
read choice

case $choice in
    1)
        result=$((num1 + num2))
        echo "Result: $num1 + $num2 = $result"
        ;;
    2)
        result=$((num1 - num2))
        echo "Result: $num1 - $num2 = $result"
        ;;
    3)
        result=$((num1 * num2))
        echo "Result: $num1 * $num2 = $result"
        ;;
    4)
        if [ $num2 -eq 0 ]; then
            echo "Error: Division by zero is not allowed"
        else
            result=$((num1 / num2))
            echo "Result: $num1 / $num2 = $result"
        fi
        ;;
    *)
        echo "Invalid choice"
        ;;
esac

