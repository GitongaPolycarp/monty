#include "monty.h"

bus_t bus;

/**
 * free_bus - frees global variables
 * Return: no value
 */

void free_bus(void)
{
	free_stack(bus.head);
	free(bus.content);
	fclose(bus.file);
}

/**
 * start_bus - initialize global variables
 * @file: file descriptor
 * Return: no value
 */

void start_bus(FILE *file)
{
	bus.lifi = 1;
	bus.cont = 1;
	bus.arg = NULL;
	bus.file = file;
	bus.content = NULL;
}

/**
 * input_check - checks if file exists
 * @argc: number of arguments
 * @argv: arguments passed
 * Return: file struct
 */

FILE *input_check(int argc, char *argv[])
{
	FILE file;

	if (argc == 1 || argc > 2)
	{
		dprintf(2, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1]. "r");

	if (file == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return (file);
}
