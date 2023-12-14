#include "monty.h"
#include "stack.h"
/**
 * division - Divides the top two elements of the stack
 * @stack_head: pointer to the head of the stack
 * @line_num: line number
 * Return: no return value
 */

void division(stack_t **stack_head, unsigned int line_num)
{
	stack_t *current;
	int stack_size = 0, result;

	current = *stack_head;
	while (current)
	{
		current = current->next;
		stack size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "Line %d: Unable to divide, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}

	current = *stack_head;
	if (current->n == 0)
	{
		fptintf(stderr, "Line %d: Division by zero\n"  line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack-head);
		exit(EXIT_FAILURE);
	}

	result = current->next->n / current->n;
	current->next->next = result;
	*stack_head = current->next;
	free(current);
}
