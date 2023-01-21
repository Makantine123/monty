#define _GNU_SOURCE
#include "monty.h"

/**
 * push - Pushes an element to the stack
 *
 * @line_number: data
 * Return: Nothin, Print error message if fail
 */
void push(stack_t **head, unsigned int line_numbers)
{
    stack_t *new_node;
    stack_t *last_node;

    if (*head == NULL)
    {
        dprintf(2, "L%u: push integer\n", line_numbers);
        exit(EXIT_FAILURE);
    }

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        exit(EXIT_FAILURE);
    }
    else
    {
        last_node = *head;
        new_node->n = line_numbers;
        new_node->next = NULL;
    }
    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    while (last_node->next != NULL)
    {
        last_node = last_node->next;
    }
    last_node->next = new_node;
    new_node->prev = last_node;
}

/**
 * pall - Function prints a stack in reverse order
 * @head_ref: Stack head
 *
 * Return: Nothing
 */
void pall(stack_t **head_ref)
{
    struct stack_s *temp = NULL;
    struct stack_s *current = *head_ref;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL)
    {
        *head_ref = temp->prev;;
    }
    while (head_ref != NULL)
    {
        printf("%d\n", (*head_ref)->n);
        *head_ref = (*head_ref)->next;
    }
}
