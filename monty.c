#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 *
 *
 *
 */
void (*get_func(stack_t **head,char *parts,unsigned int i))(stack_t **stack, unsigned int line_number)
{
	int n;
	instruction_t fn[]={
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	for (n = 0; fn[n].opcode ; n++)
	{
		if (strncmp(parts,fn[n].opcode,strlen(fn[n].opcode)) == 0 && (parts[strlen(fn[n].opcode)] == '\0'))
		{
			return(fn[n].f);
		}
	}
	printf("L%d: unkonwn instruction %s\n",i, parts);
	return(0);
}
/**
 *
 *
 *
 *
 */
int rdln(char *line,FILE *file)
{
        unsigned int i = 1;
        size_t len = 0;
	stack_t  *head = NULL;
	char *parts;
        while(getline(&line, &len, file) != -1)
        {
                parts = strtok(line, " \n");
		arg = strtok(NULL, "  \n");
                while(get_func(&head,parts, i) == 0)
		{
			return(0);
		}
		
		i++;
	}
	return (1);
}
/**
 *
 *
 *
 *
 */
void main(int argc,char *argv[])
{
	FILE * file;
	char *line = NULL;
	stack_t *head = NULL;

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
			printf("Error: Can't open file %s\n",argv[1]);
			exit(EXIT_FAILURE);
		}
		if (rdln(line,file) == 0)
                        exit(EXIT_FAILURE);
		rdln(line,file);
	}
	fclose(file);
}
