#include "general.h"
#include "text.h"
#include <unistd.h>

/**
 * _putchar_to_fd - Print a character to a specific file
 * descriptor
 *
 * @c: Character to print
 * @fd: Place to print the character
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - Print a string
 *
 * @msg: Strin to print in the fd specified
 * @fd: File descriptor to print
 *
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int print_to_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}
