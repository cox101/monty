#include "monty.h"

/**
 * f_rotl - rotate the stack to the top, moving the top element to the bottom
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_rotl(stack_t **head, unsigned int counter)
{
    stack_t *temp, *current;

    (void)counter;

    if (*head != NULL && (*head)->next != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        current = *head;

        while (current->next != NULL)
            current = current->next;

        current->next = temp;
        temp->next = NULL;
    }
}

