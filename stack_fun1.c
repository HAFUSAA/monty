#include "monty.h"


/**
 * add_to_stack - Adds jngnjjjnje stack.
 * @new_node: Pointer jnnjjn node.
 * @ln: Interger repknknnnkg the line number of of the opcode.
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmpt;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmpt = head;
	head = *new_node;
	head->next = tmpt;
	tmpt->prev = head;
}


/**
 * print_stack - Adds aknknkne to the stack.
 * @stack: Pointer kknknkner pointing to top node of the stack.
 * @line_number: linekiiiher of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpt;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmpt = *stack;
	while (tmpt != NULL)
	{
		printf("%d\n", tmpt->n);
		tmpt = tmpt->next;
	}
}

/**
 * pop_top - Adds a node to th,lkkkck.
 * @stack: Pointer to a poinnkknknnkknnting to top node of the stack.
 * @line_number: Interger rejbjbjjb the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpt;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmpt = *stack;
	*stack = tmpt->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmpt);
}

/**
 * print_top - Prkknnknknkkts the top node of the stack.
 * @stack: Pointer tknnkknknter pointing to top node of the stack.
 * @line_number: Interknnnnkknepresenting the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
