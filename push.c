#include "monty.h"

/**
 * handle_error - handle errors and exit
 * @message: error message
 * @head: stack head
 * @counter: line number
 */
void handle_error(const char *message, stack_t **head, unsigned int counter)
{
    fprintf(stderr, message, counter);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

/**
 * addnode - add node to the stack
 * @head: stack head
 * @n: value to be added
 */
void addnode(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->next = *head;
    *head = new_node;
}

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0;

    if (!bus.arg)
        handle_error("L%d: usage: push integer\n", head, counter);

    if (bus.arg[0] == '-')
        j++;

    for (; bus.arg[j] != '\0'; j++)
    {
        if (!isdigit(bus.arg[j]))
            handle_error("L%d: usage: push integer\n", head, counter);
    }

    n = atoi(bus.arg);
    addnode(head, n);
}
