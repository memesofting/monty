#ifndef MONTY_H
#define MONTY_H

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of a stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

void me_pall(stack_t **head, unsigned int number);
void me_pint(stack_t **head, unsigned int number);
void me_push(stack_t **head, unsigned int number);
void me_pop(stack_t **head, unsigned int counter);
void me_swap(stack_t **head, unsigned int counter);
void me_add(stack_t **head, unsigned int counter);
void me_nop(stack_t **head, unsigned int counter);
void me_sub(stack_t **head, unsigned int counter);
void me_div(stack_t **head, unsigned int counter);
void me_mul(stack_t **head, unsigned int counter);
void me_mod(stack_t **head, unsigned int counter);
void me_addnode(stack_t **head, int n);
void me_addqueue(stack_t **head, int n);
void me_queue(stack_t **head, unsigned int counter);
void me_stack(stack_t **head, unsigned int counter);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void me_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void me_pchar(stack_t **head, unsigned int counter);
void me_rotl(stack_t **head, unsigned int counter);
void me_pstr(stack_t **head, unsigned int counter);
void free_stack(stack_t *head);

#endif
