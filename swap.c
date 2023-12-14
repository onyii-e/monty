#include "monty.h"

/**
 * swap_elements - Exchanges top two elements in the stack
 * @stack_head: pointer to the head of the stack
 * @line_number: line number
 * Return: no return value
 */

void swap_elements(stack_t **stack_head, unsigned int line_number)
{
	stack_t *tmp;
	int count = 0, tmp_val;

	tmp = *stack_head;

	/* count the number of elements in the stack */
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}

	if (count < 2)
	{
		fprintf(stderr, "l%d: can't swap,stack element\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(stack_head);
		exit(EXIT_FAILURE);
	}

	tmp = *stack_head;
	tmp_val = tmp->n;
	tmp->n = tmp->next->n;
	tmp->next->n = tmp_val;
}
