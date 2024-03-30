#include "monty.h"

/**
 * add_to_stack - Adds a new node to the top of the stack.
 * @new_node: Double pointer to the new node to be added.
 * @ln: Line number of the opcode in the script file (unused).
 */
void add_to_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * print_stack - Prints all the values on the stack, starting from the top.
 * @stack: Double pointer to the top node of the stack.
 * @line_number: Line number of the opcode in the script file (unused).
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - Removes the top element of the stack.
 * @stack: Double pointer to the top node of the stack.
 * @line_number: Line number of the opcode in the script file.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - Prints the value at the top of the stack.
 * @stack: Double pointer to the top node of the stack.
 * @line_number: Line number of the opcode in the script file.
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
