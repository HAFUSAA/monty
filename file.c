#include "monty.h"

/**
 * open_file - opens kjbjj
 * @file_name: the fnjjnjmepath
 * Return: vod
 */

void open_file(char *file_name)
{
	FILE *ad = fopen(file_name, "r");

	if (file_name == NULL || ad == NULL)
		err(2, file_name);

	read_file(ad);
	fclose(ad);
}


/**
 * read_file - reajnjnnja file
 * @fd: pointer tbkjkjbdescriptor
 * Return: vod
 */

void read_file(FILE *fd)
{
	int line_nmber, frmat = 0;
	char *bufer = NULL;
	size_t ln = 0;

	for (line_nmber = 1; getline(&bufer, &ln, fd) != -1; line_nmber++)
	{
		frmat = parse_line(bufer, line_nmber, frmat);
	}
	free(bufer);
}


/**
 * parse_line - Separates ekbbhbhhbbhbhtokens to determine
 * which functionjnjkjk
 * @buffer: line fjbjkbjkbkjhe file
 * @line_number: linen njjkl
 * @format:  stor jhgkbnv. If 0 Nodes will be entered as a stack.
 * if 1 nodes whbbbkkbhered as a queue.
 * Return: Returns 0 if opcod is stack. 1 if queue.
 */

int parse_line(char *buffer, int line_number, int format)
{
	char *opcod, *val;
	const char *delm = "\n ";

	if (buffer == NULL)
		err(4);

	opcod = strtok(buffer, delm);
	if (opcod == NULL)
		return (format);
	val = strtok(NULL, delm);

	if (strcmp(opcod, "stack") == 0)
		return (0);
	if (strcmp(opcod, "queue") == 0)
		return (1);

	find_func(opcod, val, line_number, format);
	return (format);
}

/**
 * find_func - find the apprhggbgbgbfunction for the opcode
 * @opcode: opcghhghn
 * @value: argumegbnhghf opcode
 * @format:  stornhnhhnrmat. If 0 Nodes will be entered as a stack.
 * @ln: line nuhnhgh
 * if 1 nodes whnhgge entered as a queue.
 * Return: voi
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int r;
	int flg;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", print_char},
		{"pstr", print_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (flg = 1, i = 0; func_list[r].opcode != NULL; r++)
	{
		if (strcmp(opcode, func_list[r].opcode) == 0)
		{
			call_fun(func_list[r].f, opcode, value, ln, format);
			flg = 0;
		}
	}
	if (flg == 1)
		err(3, ln, opcode);
}


/**
 * call_fun - Calls the rehytyjnction.
 * @func: Pointer tjtjjtjon that is about to be called.
 * @op: string rjttjtjng the opcode.
 * @val: string rejttjjenting a numeric value.
 * @ln: line numtjjttjttjr the instruction.
 * @format: Format stjtjjtjier. If 0 Nodes will be entered as a stack.
 * if 1 nodes will betjjjted as a queue.
 */
void call_fun(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *nde;
	int flg;
	int r;

	flg = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flg = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (r = 0; val[r] != '\0'; r++)
		{
			if (isdigit(val[r]) == 0)
				err(5, ln);
		}
		nde = create_node(atoi(val) * flg);
		if (format == 0)
			func(&nde, ln);
		if (format == 1)
			add_to_queue(&nde, ln);
	}
	else
		func(&head, ln);
}
