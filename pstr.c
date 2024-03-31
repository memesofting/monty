#include "monty.h"
/**
 * me_pstr - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * @bus: bus struct
 * Return: no return
*/
void me_pstr(stack_t **head, unsigned int counter, bus_t *bus)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
