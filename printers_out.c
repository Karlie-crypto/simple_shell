#include "general.h"
#include "text.h"

/**
 * _putchar - Print a character to STDOUT
 *
 * @c: Character to print
 *
 * Return: On success 1
 * On error -1
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - Print a message to STDOUT
 *
 * @msg: Message to print
 *
 * Return: On success number of bytes printed
 * On errror -1, and set the error
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}
