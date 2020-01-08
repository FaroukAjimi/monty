#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 *_push - push elements in our linked list
 *@head: head of list
 *@line_number: the number of the line
 */
void _push(stack_t **head, unsigned int line_number)
{
	stack_t *new = NULL;

	new = (stack_t *)malloc(sizeof(stack_t));
	new->n = atoi(arg);
	(void)line_number;
	if (!head)
	{
		new->next = NULL;
		new->prev = NULL;
	}
	else
	{
		new->prev = NULL;
		new->next = (*head);
	}
	(*head) = new;
}
/**
 *_pall - display stack elements
 *@head: head of stack
 *@line_number: the number of the line
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *header = *head;
	(void)line_number;

	while (header)
	{
		printf("%d\n", header->n);
		header = header->next;
	}
}
/**
 *nop - nothing
 *@head: head of stack
 *@line_number: the line pf the number
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
