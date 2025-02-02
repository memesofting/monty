#include "monty.h"
/**
 * me_div - divides the top two elements of the stack.
 * @head: stack head
 * @bus: bus struct
 * @counter: line_number
 * Return: no return
*/
void me_div(stack_t **head, unsigned int counter, bus_t *bus)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus->file);
		free(bus->content);
		me_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus->file);
		free(bus->content);
		me_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n / h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
