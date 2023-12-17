#include "monty.h"

/**
 * f_swap - swap the top two elements of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_swap(stack_t **head, unsigned int counter)
{
    stack_t *temp;

    if (*head == NULL || (*head)->next == NULL)
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    temp = (*head)->next;
    (*head)->next = temp->next;
    temp->next = *head;
    *head = temp;
}

