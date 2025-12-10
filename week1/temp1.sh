
NAME="Alice"
AGE=25
PI=3.14159


echo $NAME
echo ${NAME}
echo "Name: $NAME, Age: $AGE"

CURRENT_DATE=$(date +%Y-%m-%d)
FILE_COUNT=$(ls | wc -l)
USER_HOME=$(eval echo ~$USER)


NUM1=10
NUM2=5
SUM=$((NUM1 + NUM2))
PRODUCT=$((NUM1 * NUM2))

echo "Sum: $SUM"
echo "Product: $PRODUCT"

echo "Enter your name:"
read USERNAME
echo "Hello, $USERNAME"


read -p "Enter your age: " USERAGE
