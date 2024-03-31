#include "monty.h"
/**
 * me_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * @bus: bus struct
 * Return: no return
*/
void me_pop(stack_t **head, unsigned int counter, bus_t *bus)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus->file);
		free(bus->content);
		me_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
