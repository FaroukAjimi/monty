#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
/**
 *
 *
 *
 *
 */
stack_t* newnode(stack_t head, char* arg)
{
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
	int n = atoi(arg);
	head->n = n;
	head->next = NULL;
	head->prev = NULL;
}
/**
 *
 *
 *
 */
void _push(stack_t *head, unsigned int line_number)
{
	stack_t* s = newnode(*head,arg);
	s->next = head;
	head = s;
}
/**
 *
 *
 */
void _pall(stack_t *head, unsigned int line_number)
{
	stack_t *header = head;
	(void)line_number;

	if  (head == NULL)
		return;
	while (header != NULL)
	{
		printf("%d\n", header->n);
		header = header->next;
	}
}
