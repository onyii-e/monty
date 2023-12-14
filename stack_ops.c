#include "monty.h"

/**
 * custom_push - Adds a node to the stack
 * @stack_head: Pointer to the head of the stack
 * @line_number: line number
 * Return: no return value
 */
vid custom_push(custom_stack_t **stack_head, usigned int line_number)
{
	int n, j = 0, flag = 0;

	if (custom_bus.argument)
	{
		if (custom_bus.argument[0] == '-')
			j++;
		for (; custom_bus.argument[j] != '\0'; j++)
		{
			if (custom_bus.argument[j] > 57 || custom_bus.argument[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: Usage: push integer\n", line_number);
			fclose(custom_bus.file);
			free(custom_bus.content);
			custom_free_stack(*stack_head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: Usage: push integer\n", line_number);
		fclose(custom_bus.file);
		free(custom_bus.contnet);
		custom_free_stack(*stack_head);
		exit(EXIT_FSILURE);
	}
	n = atoi(custom_bus.argument);
	if (custom_bus.lifi == 0)
		custom_addnode(stack_head, n);
	else
		custom_addqueue(stack_head, n);
}
