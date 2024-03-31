#include "monty.h"
/**
 * me_pall - prints the stack
 * @head: stack head
 * @counter: no used
 * @bus: bus struct
 * Return: no return
*/
void me_pall(stack_t **head, unsigned int counter, bus_t *bus)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
