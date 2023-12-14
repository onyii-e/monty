#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack
 * @stack_head: pointer to the stack head
 * @line_number: line number
 * Return: no return
 */

void add_top_two_elements(stack_t **stack_head, unsigned int line_number)
{
	stack_t *current;
	int stack_size = 0, result;

	current = *stack_head;
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack element\n", line_number);
		exit(EXIT FAILURE);
	}

	current = *stack_head;
	result = current->n + current->next->n;
	current->next->n = result;
	*stack_head = current->next;
	free(current);
}
