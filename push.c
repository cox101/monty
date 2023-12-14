#include "monty.h"

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
    addnode(head, n);
}

