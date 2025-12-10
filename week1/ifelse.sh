AGE=20

if [ $AGE -lt 18 ]; then
    echo "Minor"
elif [ $AGE -lt 65 ]; then
    echo "Adult"
else
    echo "Senior"
fi

if [ $NUM1 -eq $NUM2 ]; then echo "Equal"; fi
if [ $AGE -gt 18 ]; then echo "Adult"; fi

if [ -f "temp1.sh" ]; then echo "File exists"; fi
if [ -d "week1" ]; then echo "Directory exists"; fi
if [ -x "temp1.sh" ]; then echo "Executable"; fi
