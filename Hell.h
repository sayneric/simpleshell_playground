#ifndef HELL_H
#define HELL_H

/*
 * Macros
 */

#define MAX_ARGUMENTS 10
#define MAX_COMMAND_LENGTH 1028

/*
 * Declarations
 */

extern char **environ;

/*
 * Header files
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

/*
 * Functions
 */

void sayne_print(const char *note);
void interpret_command(char *instruction, size_t size);
void display_prompt(void);
void accomplish_task(char *command);
/* char *tokenize_arguments(char *task); */
int compare_strings(const char *str1, const char *str2);


































#endif
