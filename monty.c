#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
#include <string.h>
/**
 *
 *
 *
 */
void (*get_func(char *parts,unsigned int i))(stack_t **stack, unsigned int line_number)
{
	int n;
	instruction_t fn[]={
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}
	};
	for (n = 0; fn[n].opcode ; n++)
	{
		if (strncmp(parts,fn[n].opcode,strlen(fn[n].opcode)) == 0)
		{
			printf("%s\n",fn[n].opcode);
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
int stack(char *parts,char *line,FILE *file)
{
        unsigned int i = 1;
        size_t len = 0;

        while(getline(&line, &len, file) != -1)
        {
                parts = strtok(line, " \n");
                while(get_func(parts, i) == 0)
		{
			return (0);
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
	char *parts;
	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (argc == 2)
	{
		if (stack(parts,line,file) == 0)
			exit(EXIT_FAILURE);
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			printf("Error: Can't open file %s\n",argv[1]);
			exit(EXIT_FAILURE);
		}
		stack(parts,line,file);
	}
	fclose(file);
}