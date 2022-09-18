//TODO: create table generator, create truth table generator, minterm & maxterm output, create error function, file input, minterm & maxterm input

/****************************
 * KARNAUGH TABLE GENERATOR
 * Generates karnaugh tables & truth tables from logical functions
 * Input: logical functions through the command line or through file
 * Output: karnaugh table, truth table and the funtion in other forms
 * *************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "karnaugh.h"

#define BUFFER_SIZE 100 // Size of the function buffer

int is_character(char character)	
{
	// Function determines if a character is recognized
	switch(toupper(character)) {
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
		case 'F':
		case 'G':
		case 'H':
		case 'I':
		case 'J':
		case 'K':
		case 'L':
		case 'M':
		case 'N':
		case 'O':
		case 'P':
		case 'Q':
		case 'R':
		case 'S':
		case 'T':
		case 'U':
		case 'V':
		case 'W':
		case 'X':
		case 'Y':
		case 'Z':
			return 1;
		default:
			return 0;
	}
}

int variable_array(char * func, char * variables)
{
	//Function generates a list of variables and returns the number of variables
	int variable_count = 0;
	int i; // Temporary variables used in calucations
	int y;

	for (i = 0; i < BUFFER_SIZE && func[i] != NULL; i++) {
		if (func[i] == ' ' || func[i] == '\t' || func[i] == '\'' || func[i] == '+' || func[i] == '*' || func[i] == '(' || func[i] == ')')
			continue; // Skipping through white space and operations

		else if (is_character(func[i])) {
			for (y = 0; y <= variable_count; y++) // Checking if the variable already has been counted
				if (func[i] == variables[y])
					break;

			if (y == variable_count + 1 && y < 5) // If variable is uncounted and there is still space
				variables[++variable_count] = func[i]; // Add variable to array

			else if (y >= 5) { // Generating an error if there's too many variables
				printf("Too many variables.\n");
				exit(1);
			}
		} 
		
		else { // Generating an error if the character is undefined
			printf("Undefined character: %s\n", func[i]);
			exit(1);
		}
	}
	if (i == BUFFER_SIZE) { // Generating an error if the function extends beyond the buffer size
		printf("Function too large for buffer.\n");
		exit(1);
	}

	return variable_count;	
}

int main(int argc, char* argv[])
{
	if (argc > 2) {

		printf("Usage: karnaugh [file path]\n");
		exit(1);
	} else if (argc == 2) { // Running in file mode

		printf("Input through file (unfinished)");
	} else { // Running in command line mode

		char * func[BUFFER_SIZE]; // Buffer for logical function
		for (int i = 0; i < BUFFER_SIZE; i++) { // Zeroing buffer
			func[i] = NULL;
		}

		char variables[] = {NULL, NULL, NULL, NULL, NULL}; // Array of the variables
		int variable_count;

		printf("Please enter the function: ");
		scanf("%s", &func); // Loading logical function into buffer

		variable_count = variable_array(func, variables); // Generating a variable list
		
		for (int i = 0; i <= variable_count; i++) // Printing values for debuging
			printf("%c\n", variables[i]);
		printf("%d\n", variable_count);
	}

	return 0;
}
