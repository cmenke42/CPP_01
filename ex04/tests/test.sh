#!/bin/bash

# Test script for ex04

# Determine the script's directory
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"

# Set the path to the executable
EXECUTABLE="$SCRIPT_DIR/../sed_is_for_losers"

#Files
TEST_FILES="$SCRIPT_DIR/input"
EXPECTED_OUTPUT="$SCRIPT_DIR/expected_output"

#Function to compare files
function compare_files
{
	echo -e "Comparing output with expected:"
	if diff "$1" "$2" >/dev/null; then
		echo -e "Success"
	else
		{
			echo -e "Fail"
			awk '
				NR==FNR {
					a[NR]=$0
					next
				} {
					if (a[FNR] != $0) {
						print "Difference at line", FNR
						print "Correct:", a[FNR]
						print "Wrong  :", $0
					}
				}
			' "$1" "$2" | cat -e
		}
	fi
}

#function to check exit code
function check_exit_code {
	if (( $1 != $2 ))
	then
		echo "FAILED"
	else
		echo "PASSED"
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

#Run tests:
#Test 0
echo
echo "Test 0 - ARGS: Folder, \"\", \"\""
"$EXECUTABLE" "$TEST_FILES/some_folder" "" ""
check_exit_code $? 0

#Test 1
echo
echo "Test 1 - ARGS: empty_file, \"\", \"\""
"$EXECUTABLE" "$TEST_FILES/1.txt" "" ""
compare_files "$TEST_FILES/1.txt.replace" "$EXPECTED_OUTPUT/1.txt"

#Test 2
echo
echo "Test 2 - ARGS: File with 1 line, \"\", \"\""
"$EXECUTABLE" "$TEST_FILES/2.txt" "" ""
compare_files "$TEST_FILES/2.txt.replace" "$EXPECTED_OUTPUT/2.txt"

#Test 3
echo
echo "Test 3 - ARGS: File with text, e, +"
"$EXECUTABLE" "$TEST_FILES/3.txt" "e" "+"
compare_files "$TEST_FILES/3.txt.replace" "$EXPECTED_OUTPUT/3.txt"
