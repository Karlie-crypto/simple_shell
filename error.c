#include "error.h"
#include "general.h"
#include "text.h"

/**
 * message_selector - Select the message that match with the error_code
 *
 * @info: General information about the shell
 *
 * Return: Error message
 **/
char *message_selector(general_t info)
{
	int i, n_options;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (i = 0; i < n_options; i++)
		if (info.error_code == messages[i].code)
			return (messages[i].message);

	return ("");
}

/**
 * error - Print the error
 *
 * @info: General information about the shell
 **/
void error(general_t *info)
{
	char *message;
	char *number;
	char *aux;
	int size_number, size_message;

	number = NULL;
	message = message_selector(*info);
	number = to_string(info->n_commands);

	size_number = _strlen(number);
	size_message = _strlen(info->argv[0]);

	aux = malloc(size_message + size_number + 3);

	aux = _strcpy(aux, info->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	message = join_words(aux, info->command, message, ": ");
	print_err(message);

	free(message);
	free(number);
	free(aux);
}

/**
 * error_extra - Print the error with extra information
 *
 * @info: General information about the shell
 * @extra: Extra information
 **/
void error_extra(general_t *info, char *extra)
{
	char *message, *number, *aux, *aux2;
	int size_number, size_message, size_extra;

	number = NULL;
	message = message_selector(*info);
	number = to_string(info->n_commands);

	size_number = _strlen(number);
	size_message = _strlen(info->argv[0]);
	size_extra = _strlen(extra);

	aux = malloc(size_message + size_number + 3);
	aux = _strcpy(aux, info->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, number);

	aux2 = malloc(_strlen(message) + size_extra + 3);
	aux2 = _strcpy(aux2, message);
	aux2 = _strcat(aux2, ": ");
	aux2 = _strcat(aux2, extra);

	message = join_words(aux, info->command, aux2, ": ");
	print_err(message);

	free(message);
	free(number);
	free(aux);
	free(aux2);
}
