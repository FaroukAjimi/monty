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
stack_t* newnode()
{
	stack_t *stack = (stack_t *)malloc(sizeof(stack_t));
	int n = atoi(arg);
	stack->n = n;
	stack->next = NULL;
	stack->prev = NULL;
}
/**
 *
 *
 *
 */
void _push(stack_t **stack, unsigned int line_number)
{
	stack_t* s = newnode(arg);
	s->next = *stack;
	*stack = s;
}
/**
 *
 *
 */
void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *header = *stack;
	void(line_number);
	if  (*stack == NULL)
		return;
	while (header != NULL)
	{
		printf("%d\n", header->n);
		header = header->next;
	}
}
