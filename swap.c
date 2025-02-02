#include "monty.h"
/**
 * me_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * @bus: bus struct
 * Return: no return
*/
void me_swap(stack_t **head, unsigned int counter, bus_t *bus)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus->file);
		free(bus->content);
		me_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
