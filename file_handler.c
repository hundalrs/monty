#include "monty.h"
int op_int;
/**
 * file_handler - handles all operations on file
 * @filename: represents pointer holding file's name
 * Return: function is void
 */
void file_handler (const char *filename)
{
	size_t bufsize = 0;
	int line_num = 1;
	int x;
	FILE *fp;
	char *buffer = NULL, *newtoken, *token;
	stack_t *stack = NULL;

	if (filename == NULL)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &bufsize, fp) != -1)
	{
		token = strtok(buffer, "\n\t ");
		if (strcmp(token, "push") == 0)
		{
			newtoken = strtok(NULL, "\n\t ");
			op_int = atoi(newtoken);
		}
		x = tokenloop(token, line_num, &stack);
		if (x == 0)
		{
			printf("L%i: unknown instruction %s\n", line_num, token);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}

	fclose(fp);
	free(buffer);
}
