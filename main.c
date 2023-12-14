#include "monty.h"

/**
 * monty_interpreter - Interprets and Executes Monty code
 * @arg_count: number of command-line arguments
 * @arg_values: Array of strings containing command-line arguments
 * @command_bus: pointer to the bus_t structure storing command information
 * This function reads a monty bytecode file and interprets/executes the
 * instructions within it. each instruction is processed and executed
 * sequentially.
 * the command_bus structure is used to manage command-related info
 * during the interpretation process.
 *
 *
 * Return: 0 on success
 */
int monty_interpreter(int arg_count, char *arg_values[], bus_t *command_bus)
{
	char *line_content;
	FILE *monty_file;
	size_t buffer_size = 0;
	ssize_t read_result = 1;
	stack_t *stack_head = NULL;
	unsigned int line_counter = 0;

	if (arg_count != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	monty_file = fopen(arg_values[1], "r");
	command_bus.file = monty_file;

	if (!monty_file)
	{
		fprintf(stderr, "Error: Cant open file %s\n", arg_values[1]);
		exit(EXIT_FAILURE);
	}

	while (read_result > 0)
	{
		line_content = NULL;
		read_result = getline(&line_content, &BUFFER_SIZE, monty_file);
		command_bus->content = line_content;
		line_counter++;

		if (read_result > 0)
		{
			execute(line_content, &stack_head, line_counter, monty_file);
		}

		free(line_content);
	}

	free_stack(stack_head);
	fclose(monty_file);
	return (0);
}
