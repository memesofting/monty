#include "monty.h"
/**
  *me_rotr- rotates the stack to the bottom
  *@head: stack head
  *@counter: line_number
  * @bus: bus struct
  *Return: no return
 */
void me_rotr(stack_t **head,
__attribute__((unused)) unsigned int counter, bus_t *bus)
{
	stack_t *copy;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
