#include "monty.h"

stack_t *head = NULL;

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Argument vector.
 * Return: Always 0.
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
    return 0;
}

/**
 * create_node - Creates a node.
 * @n: The number to store in the node.
 * Return: A pointer to the new node if successful, NULL otherwise.
 */
stack_t *create_node(int n)
{
    stack_t *node = malloc(sizeof(stack_t));
    if (!node)
    {
        err(4);
    }
    node->next = NULL;
    node->prev = NULL;
    node->n = n;
    return node;
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
    while (head)
    {
        stack_t *temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * add_to_queue - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @ln: Line number of the opcode (unused).
 */
void add_to_queue(stack_t **new_node, __attribute__((unused)) unsigned int ln)
{
    if (!new_node || !*new_node)
    {
        exit(EXIT_FAILURE);
    }

    if (!head)
    {
        head = *new_node;
        return;
    }

    stack_t *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = *new_node;
    (*new_node)->prev = temp;
}
