#include "monty.h"
/**
 * me_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * @bus: bus struct
 * Return: no return
*/
void me_push(stack_t **head, unsigned int counter, bus_t *bus)
{
	int n, j = 0, flag = 0;

	if (bus->arg)
	{
		if (bus->arg[0] == '-')
			j++;
		for (; bus->arg[j] != '\0'; j++)
		{
			if (bus->arg[j] > 57 || bus->arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(bus->file);
			free(bus->content);
			me_free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus->file);
		me_free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus->arg);
	if (bus->lifi == 0)
		me_addnode(head, n);
	else
		me_addqueue(head, n);
}
