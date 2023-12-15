#include "monty.h"

void ig(void);

/**
 * main - Main Function
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0
 */

int main(int argc, char *argv[])
{
	int fd;
	unsigned int line_number = 1;
	char *line;
	ssize_t read_data;
	char *opcode, *delimiter = "\n\t\r\a ;:";
	int push_flag = 0;
	stack_t *head = NULL;

	if (argc != 2 || !argv[1])
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	line = malloc(sizeof(char) * 1024);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	read_data = read(fd, line, 1024);
	if (read_data == -1)
	{
		free(line);
		exit(EXIT_FAILURE);
	}

	opcode = strtok(line, delimiter);
	while (opcode != NULL)
	{
		if (push_flag == 1)
		{
			push(&head, line_number, opcode);
			push_flag = 0;
			opcode = strtok(NULL, delimiter);
			line_number++;
			continue;

		}
		else if (strcmp(opcode, "push") == 0)
		{
			push_flag = 1;
			opcode = strtok(NULL, delimiter);
			continue;
		}
		else
		{
			if (operate(opcode) != 0)
			{
				operate(opcode)(&head, line_number);
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}

	}
	line_number++;
	opcode = strtok(NULL, delimiter);

	free(line);
	close(fd);
	return (0);
}
