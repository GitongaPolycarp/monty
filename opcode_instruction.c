#include "monty.h"

/**
 * f_push - pushes an element to the stack
 * @head: head of linked lists
 * @number: line number
 * Return: no return
 */

void f_push(stack_t **head, unsigned int number)
{
	int a, b;

	if (!vglo.arg)
	{
		dprintf(2, "L%u: ", number);
		dprintf(2, "usage: push integer\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}

	for (b = 0; vglo.arg[b] != '\0'; b++)
	{
		if (!isdigit(vglo.arg[b]) && vglo.arg[b] != '-')
		{
			dprintf(2, "L%u: ", number);
			dprintf(2, "usage: push integer\n");
			free_vglo();
			exit(EXIT_FAILURE);
		}
	}

	a = atoi(vglo.arg);

	if (vglo.lifo == 1)
		add_dnodeint(head, a);
	else
		add_dnodeint_end(head, a);
}

/**
 * f_pall - prints all the values on the stack
 * @head: head of linked list
 * @number: line numbers
 * Return: no value
 */

void f_pall(stack_t **head, unsigned int number)
{
	stack_t *aux;
	(void)number;

	aux = *head;

	while (aux)
	{
		printf("%d\n", aux->n);
		aux = aux->next;
	}
}

/**
 * f_pint - prints the value at top of stack
 * @head: head of linked list
 * @number: line number
 * Return: no value
 */

void f_pint(stack_t **head, unsigned int number)
{
	(void)number;

	if (*head == NULL)
	{
		dprintf(2, "L%u: ", number);
		dprintf(2, "can't pint, stack is empty\n");
		free_vglo();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * f_pop - removes value at the top of stack
 * @head: head of linked list
 * @counter: line number
 * Return: no value
 */

void f_pop(stack_t **head, unsigned int counter)
{
	stack_t *aux;

	if (head == NULL || *head == NULL)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", counter);
		free_vglo();
		exit(EXIT_FAILURE);
	}
	aux = *head;
	*head = (*head)->next;
	free(aux);
}

/**
 * f_swap - swaps the top two elements of stack
 * @head: head of linked list
 * @counter: line number
 * Return: no value
 */

void f_swap(stack_t **head, unsigned int counter)
{
	int c = 0;
	stack_t *aux = NULL;

	aux = *head;

	for (; aux != NULL; aux = aux->next, c++)
		;

	if (c < 2)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", number);
		free_vglo();
		exit(EXIT_FAILURE);
	}

	aux = *head;
	*head = (*head)->next;
	aux->next = (*head)->next;
	aux->prev = *head;
	(*head)->next = aux;
	(*head)->prev = NULL;
}
