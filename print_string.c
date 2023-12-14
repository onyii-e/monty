#include "monty.h"

/**
 * custom_print_string - prints the string starting at the
 * top of stack, followed by a new line
 * @stack_head: pointer to the head of the stack
 * @line_number: line number
 * Return: no return value
 */

void custom_print_string(custom_stack_t **stack_head, unsigned int line_number)
{
	custom_stack_t *temp;
	(void)line_number;

	tmp = *stack_head;

	while (tmp)
	{
		if (tmp->number > 127 || tmp->number <= 0)
		{
			break;
		}
		printf("%c", tmp->number);
		tmp = tmp->next;
	}
	printf("\n");
}
