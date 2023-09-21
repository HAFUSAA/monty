#include "monty.h"

/**
 * nop - Doeshvhhvhing.
 * @stack: Pointerbjjbjbjbbjpointing to top node of the stack.
 * @line_number: Intergjbbjjbjbpresenting the line number of of the opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - Swaps hvhhvvhlements of the stack.
 * @stack: Pointer to a bjjbjbbjer pointing to top node of the stack.
 * @line_number: Interger rnjnknkenting the line number of of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	tmpt = (*stack)->next;
	(*stack)->next = tmpt->next;
	if (tmpt->next != NULL)
		tmpt->next->prev = *stack;
	tmpt->next = *stack;
	(*stack)->prev = tmpt;
	tmpt->prev = NULL;
	*stack = tmpt;
}

/**
 * add_nodes - Adds the top two bhjjbbjbjts of the stack.
 * @stack: Pointer to a pointer bjbjbjjbto top node of the stack.
 * @line_number: Interger reprnkkknknknhe line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	sm = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the topbbbkkbof the stack.
 * @stack: Pointer to a pbbbkkbkbointing to top node of the stack.
 * @line_number: Internkknnknkknnting the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	sm = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - Adds the tjbbbjjbts of the stack.
 * @stack: Pointer to a pooooojpointing to top node of the stack.
 * @line_number: Interger kbkknnkenting the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int sm;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	sm = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sm;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
