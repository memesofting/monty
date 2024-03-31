#include "monty.h"
/**
 * me_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * @bus: bus struct
 * Return: no return
*/
void me_pint(stack_t **head, unsigned int counter, bus_t *bus)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(bus->file);
		free(bus->content);
		me_free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
