#include "monty.h"

/**
 * f_rotr - rotate the stack to the bottom, moving the bottom element to the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotr(stack_t **head, unsigned int counter)
{
    stack_t *temp, *current;

    (void)counter;

    if (*head != NULL && (*head)->next != NULL)
    {
        temp = *head;
        current = *head;

        while (current->next->next != NULL)
            current = current->next;

        temp->next = *head;
        *head = current->next;
        current->next = NULL;
    }
}

