#include "monty.h"

/**
 * print_char - Prints bhjbjbhbjcii value.
 * @stack: Pointerbjjbjbjbjpointing to top node of the stack.
 * @line_number: Intergebiihepresenting the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int asc;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
		string_err(10, line_number);
	printf("%c\n", asc);
}

/**
 * print_str - Prints a kiihihiring.
 * @stack: Pointerhhvvhhv pointing to top node of the stack.
 * @ln: Intergerbjbjjbbjting the line number of of the opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc;
	stack_t *tmpt;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	tmpt = *stack;
	while (tmpt != NULL)
	{
		asc = tmpt->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		tmpt = tmpt->next;
	}
	printf("\n");
}

/**
 * rotl - Rotateskkke first node of the stack to the bottom.
 * @stack: Poinbjjbjbo a pointer pointing to top node of the stack.
 * @ln: Intknknknnkknesenting the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmpt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpt = *stack;
	while (tmpt->next != NULL)
		tmpt = tmpt->next;

	tmpt->next = *stack;
	(*stack)->prev = tmpt;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - Rotates thttjbjjbthe stack to the top.
 * @stack: Pointebknknter pointing to top node of the stack.
 * @ln: Intergeknknknesenting the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *tmpt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	tmpt = *stack;

	while (tmpt->next != NULL)
		tmpt = tmpt->next;

	tmpt->next = *stack;
	tmpt->prev->next = NULL;
	tmpt->prev = NULL;
	(*stack)->prev = tmpt;
	(*stack) = tmpt;
}
