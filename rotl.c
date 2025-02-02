#include "monty.h"
/**
  *me_rotl- rotates the stack to the top
  *@head: stack head
  *@counter: line_number
  * @bus: bus struct
  *Return: no return
 */
void me_rotl(stack_t **head,
__attribute__((unused)) unsigned int counter, bus_t *bus)
{
	stack_t *tmp = *head, *aux;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
