#!/bin/bash

RED='\e[91m'
GREEN='\e[92m'
YELLOW='\e[93m'
BLUE='\e[94m'
PURPLE='\e[95m'
CYAN='\e[96m'
NC='\e[0m'
NL='\n'

echo -e $CYAN"=============================="$NC$NL
echo -e $CYAN"--------- TEST START ---------"$NC$NL

make > /dev/null

echo -e $CYAN"---- SUCCESS - MAKE PIPEX ----"$NC$NL
echo -e $CYAN"=============================="$NC$NL

echo -e "my${NL}name${NL}is${NL}pmitsuko" > input_file

check_diff() {
	RESULT=$(diff correct_output_file my_output_file)
	echo ------------------------------
	echo -e ${PURPLE}CORRECT RESULT${NC}
	cat correct_output_file
	echo -e ${PURPLE}MY RESULT${NC}
	cat my_output_file
	if [ -z "$RESULT" ]; then
		echo -e $GREEN"case $1 SUCCESS"$NC
	else
		echo -e $RED"case $1 FAILED"$NC
	fi
}


< input_file cat | cat > correct_output_file
./pipex input_file cat cat my_output_file
check_diff "1"

< input_file ls -l | wc -l > correct_output_file
./pipex input_file "ls -l" "wc -l" my_output_file
check_diff "2"

< input_file grep a1 | wc -w > correct_output_file
./pipex input_file "grep a1" "wc -w" my_output_file
check_diff "3"

< input_file cat 123 | cat > correct_output_file
./pipex input_file "cat 123" cat my_output_file
check_diff "4"

< input_file cat | notexisting > correct_output_file
./pipex input_file cat notexisting my_output_file
check_diff "5"

< input_file notexisting | cat > correct_output_file
./pipex input_file notexisting cat my_output_file
check_diff "6"

< ./assets/deepthought.txt grep Now | /usr/bin/cat > correct_output_file
./pipex ./assets/deepthought.txt "grep Now" /usr/bin/cat my_output_file
check_diff "7"

rm input_file correct_output_file my_output_file