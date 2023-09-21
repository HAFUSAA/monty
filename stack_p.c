#include "monty.h"

/**
 * mul_nodes - Adds the jbjbbjbjjb of the stack.
 * @stack: Pointer to a pnjbjbjinting to top node of the stack.
 * @line_number: Intenkknnkknnksenting the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sm = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - Adds thenjjjjbments of the stack.
 * @stack: Pointer tknknknnknker pointing to top node of the stack.
 * @line_number: Intergerjjjbjjesenting the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sm = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
