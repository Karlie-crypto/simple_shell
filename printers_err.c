#include "text.h"

/**
 * print_err - Print a message to STDERR
 *
 * @msg: Message to print
 *
 * Return: Number of bytes printed
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}
