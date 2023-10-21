#!/bin/bash

# Test script for ex04

# Colors
RED="\033[0;31m"
GREEN="\033[0;32m"
YELLOW="\033[0;33m"
PINK="\033[0;35m"
RESET="\033[0m"


# Determine the script's directory
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Set the path to the executable
EXECUTABLE="$SCRIPT_DIR/../a.out"

#Files
TEST_FILES="$SCRIPT_DIR/input"
EXPECTED_OUTPUT="$SCRIPT_DIR/expected_output"

#Function to compare files
function compare_files
{
	echo -e "\n${YELLOW}Comparing output with expected:${RESET}"
	if diff "$1" "$2" >/dev/null; then
		echo -e "${GREEN}Success${RESET}"
	else
	{
		echo -e "${RED}Fail${RESET}"
		awk -v yellow="$YELLOW" -v green="$GREEN" -v red="$RED" -v reset="$RESET" '
			{
				if (FILENAME == ARGV[1]) {
					# Process the first file to store expected lines
					expected_lines[FNR] = $0
					length_file_1 = FNR
				} else {
					# Process the second file to compare expected and actual lines
					if (FNR <= length_file_1 && expected_lines[FNR] != $0) {
						print yellow "Difference at line", reset, FNR
						print green "Expected:", reset, expected_lines[FNR]
						print red "Actual  :", reset, $0
					} else if ((FNR == length_file_1 && expected_lines[FNR] != $0) || FNR > length_file_1) {
						# Print extra lines in the output
						print yellow "Difference at line", reset, FNR
						print green "Expected:", reset
						print red "Actual  :", reset, $0
					}
					length_file_2 = FNR  # Store the length of file 2
				}
			}
			END {
					if (length_file_2 < length_file_1) {
						#Print lines that are missing in the output
						for (i = length_file_2 + 1; i <= length_file_1; i++) {
							print yellow "Difference at line", reset, i
							print green "Expected:", reset, expected_lines[i]
							print red "Actual  :", reset
						}
				}
			}
			' "$1" "$2"
	}
	fi
	echo ----------------------------------------
}

#function to check exit code
function check_exit_code {
	if (( $1 == 0 ))
	then
		echo -e "${RED}Fail${RESET}"
	else
		echo -e "${GREEN}Success${RESET}"
	fi
}

#Build the program
make -C "$SCRIPT_DIR/.." > /dev/null
if (( $? != 0 ))
then
	echo "Build failed"
	exit 1
fi

#Clean old output files
echo "Cleaning old output files"
rm -f "$TEST_FILES"/*.replace
echo ----------------------------------------

#Run tests:
#Test 0
echo -e "${PINK}Test 0 - ARGS: Folder, \"\", \"\"${RESET}"
"$EXECUTABLE" "$TEST_FILES/some_folder" "" ""
check_exit_code $?
echo ----------------------------------------

#Test 1
echo -e "${PINK}Test 1 - ARGS: empty_file, \"\", \"\"${RESET}"
"$EXECUTABLE" "$TEST_FILES/1.txt" "" ""
compare_files "$TEST_FILES/1.txt.replace" "$EXPECTED_OUTPUT/1.txt"

#Test 2
echo -e "${PINK}Test 2 - ARGS: File with 1 line, \"\", \"\"${RESET}"
"$EXECUTABLE" "$TEST_FILES/2.txt" "" ""
compare_files "$TEST_FILES/2.txt.replace" "$EXPECTED_OUTPUT/2.txt"

#Test 3
echo -e "${PINK}Test 3 - ARGS: File with text, e, +${RESET}"
"$EXECUTABLE" "$TEST_FILES/3.txt" "e" "+"
compare_files "$TEST_FILES/3.txt.replace" "$EXPECTED_OUTPUT/3.txt"
