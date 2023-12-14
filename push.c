#include "monty.h"

/**
 * handle_error - handle errors and exit
 * @message: error message
 * @head: stack head
 */
void handle_error(const char *message, stack_t **head)
{
    fprintf(stderr, "%s\n", message);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_push(stack_t **head, unsigned int counter)
{
    int n, j = 0;

    if (!bus.arg)
        handle_error("L%d: usage: push integer", head, counter);

    if (bus.arg[0] == '-')
        j++;

    for (; bus.arg[j] != '\0'; j++)
    {
        if (!isdigit(bus.arg[j]))
            handle_error("L%d: usage: push integer", head, counter);
    }

    n = atoi(bus.arg);
    if (bus.lifi == 0)
        addnode(head, n);
    else
        addqueue(head, n);
}

/**
 * f_pall - print all values on the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;

    (void)counter;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

