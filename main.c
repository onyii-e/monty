#include "monty.h"
#include <stdio.h>
/**
 *  main - interprets monty code from a file
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success execution, non-zero otherwise
 */
int main(int argc, char *argv[])
{
	bus_t bus = {NULL, NULL, NULL, 0};

	/* moved bus variable inside main */

	char *content;
	FILE *file;
	size_t size = 0;
	size_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	bus.file = file;

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.content = content;
		counter++;

		if (read_line > 0)
		{
			execute(content, &stack, counter, file);
		}
		free(content);
	}

	free_stack(stack);
	fclose(file);
	return (0);
}
