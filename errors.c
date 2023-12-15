#include "monty.h"

/**
 * swap_error - error message for if swapping fails
 * @line_num: line number at which swapping failed
 */
void swap_error(unsigned int line_num)
{
	char int_to_string[10];
	char err_msg[256] = "L";

	sprintf(int_to_string, "%d", line_num);
	strcat(err_msg, int_to_string);
	strcat(err_msg, ": can't swap, stack too short\n");

	write(2, err_msg, strlen(err_msg) + 1);

	exit(EXIT_FAILURE);
}

/**
 * stack_empty_error - error message for when
 * stack is empty
 * @line_num: line number at which stack was empty
 */
void stack_empty_error(unsigned int line_num)
{
	char int_to_string[10];
	char err_msg[256] = "L";

	sprintf(int_to_string, "%d", line_num);
	strcat(err_msg, int_to_string);
	strcat(err_msg, ": can't pint, stack empty\n");

	write(2, err_msg, strlen(err_msg) + 1);

	exit(EXIT_FAILURE);
}

/**
 * malloc_error - error for when malloc fails
 */
void malloc_error(void)
{
	write(2, "Error: malloc failed\n", 22);
	exit(EXIT_FAILURE);
}
