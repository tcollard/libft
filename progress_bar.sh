#!/bin/bash

NC='\033[0m'
GREEN='\033[0;32m'
PURPLE='\033[0;35m'
COLOR=0
NAME=$1;
x=0;
MAX=`ls -lR ./srcs | grep -o -c "\.c"`;
COUNT=`ls -lR ./obj | grep -o -c "\.o"`;
i=0;

if [ $MAX = 0 ]
then
    let "x = 0"
else
    let "x = COUNT * 20 / MAX"
fi
echo -n -e "$NAME:\t\t[";

while [ $i -lt $x ]
do
    if [ $x = 20 ]
    then
	echo -n -e "${GREEN}#${NC}"
    else
        echo -n -e "${PURPLE}#${NC}"
    fi
    let "i += 1"
done

while [ $i -lt 20 ]
do
    echo -n " "
    let "i += 1"
done

echo -n "]"

let "x = COUNT * 100 / MAX"

if [ $x = 100 ]
then
    echo -e "  ${GREEN}[$x%]${NC}"
    echo -e -n "${NAME}:\t\t"
    echo -e "${GREEN}[DONE]${NC}"
else
    echo -n -e "  [${PURPLE}$x%${NC}]"
fi
