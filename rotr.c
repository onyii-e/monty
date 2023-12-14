#include "monty.h"

/**
 * stack_rotate_right - Rotates the stack elements to the bottom
 * @stack: pointer to the end of the stack
 * @line_number:line number
 * Return: no return value
 */

void stack_rotate_right(
		stack_t **stack,
		__attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp, *last_node;

	tmp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}

	while (tmp->next != NULL)
	{
		last_node = tmp;
		tmp = tmp->next;
	}

	tmp->next = *stack;
	last_node->next = NULL;
	(*stack)->prev = tmp;
	*stack = tmp;
}

