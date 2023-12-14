#include "monty.h"

/**
 * f_pall - print all values on the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *current = *head;

    (void)counter; // Unused parameter

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

