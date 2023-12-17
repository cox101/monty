#include "monty.h"

/**
 * f_mod - calculate the remainder of the division of the second element
 *         by the top element of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_mod(stack_t **head, unsigned int counter)
{
    stack_t *temp;

    if (*head == NULL || (*head)->next == NULL || (*head)->n == 0)
    {
        fprintf(stderr, "L%d: can't mod, stack too short or division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    (*head)->next->n %= (*head)->n;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}

