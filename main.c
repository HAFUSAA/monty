#include "monty.h"
stack_t *head = NULL;

/**
 * main - entrjbkjjknt
 * @argc: argumenhkhcount
 * @argv: list oihihihguments
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_nodes();
	return (0);
}

/**
 * create_node - Crhuuuues a node.
 * @n: Number to gojuuugugugde the node.
 * Return: Upon suceuuuugnter to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *nod;

	nod = malloc(sizeof(stack_t));
	if (nod == NULL)
		err(4);
	nod->next = NULL;
	nod->prev = NULL;
	nod->n = n;
	return (nod);
}

/**
 * free_nodes - Frees nodhhhhjjhe stack.
 */
void free_nodes(void)
{
	stack_t *tmpt;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmpt = head;
		head = head->next;
		free(tmpt);
	}
}


/**
 * add_to_queue - Adds a node hhhhhjkneue.
 * @new_node: Pointer to the newnkknknkn.
 * @ln: line number of thenjjjnkkn
 */
void add_to_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (tmpt->next != NULL)
		tmpt = tmpt->next;

	tmpt->next = *new_node;
	(*new_node)->prev = tmpt;

}
