#include "monty.h"
/**
* execute - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execute(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", me_push}, {"pall", me_pall}, {"pint", me_pint},
				{"pop", me_pop},
				{"swap", me_swap},
				{"add", me_add},
				{"nop", me_nop},
				{"sub", me_sub},
				{"div", me_div},
				{"mul", me_mul},
				{"mod", me_mod},
				{"pchar", me_pchar},
				{"pstr", me_pstr},
				{"rotl", me_rotl},
				{"rotr", me_rotr},
				{"queue", me_queue},
				{"stack", me_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter, &bus);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		me_free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
