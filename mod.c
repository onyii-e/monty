#include "monty.h"

/**
 * f_mod - computes the rest of the division of the second
 * top element in the stack
 * @head: stack head
 * @counter: line number
 * Return: no return
 */

void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int len = 0, aux;

	while (h)
	{
		h = h->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		exit(EXIT_FAILURE);
	}

	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		exit(EXIT_FAILURE);
	}

	aux = h->next->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
