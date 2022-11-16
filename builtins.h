#ifndef BUILTINS_H
#define BUILTINS_H

#include "general.h"
#include "text.h"
#include "memory.h"
#include "commands.h"

/* builtins.c */
int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);

/* exit.c */
void bin_exit(general_t *info, char **arguments);
int number_controller(general_t *info, char *number);

/* env.c */
void bin_env(general_t *info, char **arguments);

/* echo.c */
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);

#endif /* BUILTINS_H */
