#include "monty.h"

/**
 * add_dnodeint_end - adds note at end of doubly linked list
 * @head: first position of the linked list
 * @n: data
 * Return: doubly linked list
 */

stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *tmp, *aux;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc has failed\n");
		free_bus();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	aux = *head;
	while (aux->next)
		aux = aux->next;
	tmp->next = aux->next;
	tmp->prev = aux;
	aux->next = tmp;
	return (aux->next);
}

/**
 * add_dnodeint - adds node at beginning of doubly linked list
 * @head: first position of the linked list
 * @n: data to be stored
 * Return: doubly linked list
 */

stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = malloc(sizeof(stack_t));
	if (!tmp)
	{
		dprintf(2, "Error: malloc has failed\n");
		free_bus();
		exit(EXIT_FAILURE);
	}
	tmp->n = n;

	if (*head == NULL)
	{
		tmp->next = *head;
		tmp->prev = NULL;
		*head = tmp;
		return (*head);
	}
	(*head)->prev = tmp;
	tmp->next = (*head);
	tmp->prev = NULL;
	*head = tmp;
	return (*head);
}

/**
 * free_stack - frees a doubly linked list
 * @head: list head
 * Return: no value
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
