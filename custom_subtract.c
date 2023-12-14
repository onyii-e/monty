#include "monty.h"

/**
 * custom_subtract - preform subtraction operation
 * @stack_head: pointer to the head of the stack
 * @line_number: line number
 * Return: no return value
 */
void custom_subtract(custom_stack_t **stack_head, unsigned int line_number)
{
	custom_stack_t *tmp;
	int result, count_nodes;

	tmp = *stack_head;

	/* count the number of nodes in the stack */
	for (count_nodes = 0; tmp != NULL; count_nodes++)
		tmp = tmp->next;

	/* checks if there are enough nodes to perform subtraction */
	if (count_nodes < 2)
	{
		fprintf(stderr, "L%dcan't sub, stack elements\n", line_number);
		fclose(custom_bus.file);
		free(custom_bus.content);
		custom_free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	tmp = *stack_head;
	result = tmp->number - tmp->number;
	tmp->next->number = result;
	*stack_head = tmp->next;
	free(tmp);
}
