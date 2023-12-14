#include "monty.h"

/**
 * custom_queue - sets the data structure to queue mode
 * @stack_head: pointer to the end of the stack
 * @counter: line number
 * Return: no return value
 */

void custom_queue(custom_stack_t **stack_head, unsigned int counter)
{
	(void)stack_head;
	(void)counter;
	custom_bus.lifi = 1;
}

/**
 * custom_addqueue - adds a node to the tail of the stack
 * @n: new value
 * @stack_head: pointer to the head of the stack
 * Return: no return value
 */

void custom_addqueue(custom_stack_t **stack_head, int n)
{
	custom_stack *new_node, *aux;

	aux = *stack_head;
	new_node = malloc(sizeof(custom_stack_t));
	if (new_node == NULL)
	{
		printf("Erroe\n");
	}
	new_node->number = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux =  aux->next;
	}
	if (aux)

	{
		*stack_head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
