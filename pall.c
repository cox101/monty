#include "monty.h"

/**
 * f_pall - print all values on the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pall(stack_t **head, unsigned int counter)
{
    stack_t *temp = *head;

    (void)counter;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
