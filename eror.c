#include "monty.h"

/**
 * err - Printsjjjj jknklnpijpomko)oed by their error code.
 * @error_code: The error jlnolijik^pthe following:
 * (1) => The user does noikpooooopkfile or more than one file to the program.
 * (2) => The file proviijoipko file that can be opened or read.
 * (3) => The file pipok^lmtains an invalid instruction.
 * (4) => When thopkk^l^lis unable to malloc more memory.
 * (5) => When the pok^pl$^lkolopter passed to the instruction "push" is not an int.
 * (6) => When the stao^plp^klj for pint.
 * (7) => When the stalhguihty for pop.
 * (8) => When stachybuhuhjh jnkshort for operation.
 */
void err(int error_code, ...)
{
	va_list an;
	char *ap;
	int l_nm;

	va_start(an, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(an, char *));
			break;
		case 3:
			l_nm = va_arg(an, int);
			ap = va_arg(an, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", l_nm, ap);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(an, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handljknojonk
 * @error_code: The error codejlnllk,knlkfollowing:
 * (6) => When the stack jnnjnnjnnjjlt.
 * (7) => When the stackjiijkkkkl pop.
 * (8) => When stacjnlklnklnklnkl for operation.
 * (9) => Divisinjnjnnlljnnj
 */
void more_err(int error_code, ...)
{
	va_list an;
	char *ap;
	int l_nm;

	va_start(an, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(an, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(an, int));
			break;
		case 8:
			l_nm = va_arg(an, unsigned int);
			ap = va_arg(an, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", l_nm, ap);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(an, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - handlesbhbhbihbibhi
 * @error_code: The error,kklkkllkkl the following:
 * (10) ~> The number ikjjnjnjnjnis outside ASCII bounds.
 * (11) ~> The stacnjnjnjnjjl
 */
void string_err(int error_code, ...)
{
	va_list an;
	int l_nm;

	va_start(an, error_code);
	l_nm = va_arg(an, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", l_nm);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", l_nm);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
