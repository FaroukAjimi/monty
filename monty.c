#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 *g - it will specify the function
 *@h: head of the linked list
 *@p: the command that appears in the monty file
 *@i : the number of the line
 *Return: function or 0 if it fails
 */
void (*g(stack_t **h, char *p, unsigned int i))(stack_t **h, unsigned int l)
{
	int n;
	(void) h;
	instruction_t fn[] = {
		{"push", _push},
		{"pall", _pall},
		{"nop", nop},
		{NULL, NULL}
	};
for (n = 0; fn[n].opcode ; n++)
{
if (strncmp(p, fn[n].opcode, strlen(fn[n].opcode)) == 0)
{
return (fn[n].f);
}
}
printf("L%d: unkonwn instruction %s\n", i, p);
return (0);
}
/**
 *rdln - It will read our monty file line by line
 *@line: line
 *@file: the monty file
 *Return: 1 for success 0 for failure
 */
void rdln(char *line, FILE *file)
{
	unsigned int i = 1;
	size_t len = 0;
	stack_t  *head = NULL;
	char *parts;
	void (*func)(stack_t **stack, unsigned int line_number);

	while (getline(&line, &len, file) != -1)
	{
		parts = strtok(line, " \n");
		arg = strtok(NULL, "  \n");
		while (g(&head, parts, i) == 0)
		{
			exit(EXIT_FAILURE);
		}
		func = (g(&head, parts, i));
		func(&head, i);
		i++;
	}
}
/**
 *main - monty language interpreter
 *@argc: number of argument
 *@argv: arguments carrier
 *Return: 0 always
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			printf("Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		rdln(line, file);
	}
	fclose(file);
	return (0);
}
