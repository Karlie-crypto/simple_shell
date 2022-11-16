#include "builtins.h"

/**
 * bin_env - Implementation for the env builtin
 *
 * @info: General information about the shell
 * @arguments: Command
 **/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}
