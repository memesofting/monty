#include "monty.h"
/**
 * me_queue - prints the top
 * @head: stack head
 * @counter: line_number
 * @bus: bus struct
 * Return: no return
*/
void me_queue(stack_t **head, unsigned int counter, bus_t *bus)
{
	(void)head;
	(void)counter;
	bus->lifi = 1;
}

/**
 * me_addqueue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void me_addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
