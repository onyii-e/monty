#include "monty.h"

/**
 * custom_stack_fucntion - adjust the stack status
 * @stack_head: pointer to the head of the stack
 * @line_number: line number
 * Return: no returnvalue
 */


void custom_stack_function(
		custom_stack_t **stack_head,
		unsigned int line_number
		)
{
	(void)stack_head;
	(void)line_number;
	custom_bus.stack_status = 0;
}
