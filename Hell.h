#ifndef HELL_H
#define HELL_H

/*
 * Macros
 */

#define MAX_ARGUMENTS 10
#define MAX_COMMAND_LENGTH 100

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
int check_command_existence(const char *command, char *command_path);
void execute_command(const char *command_path, const char *command);
void accomplish_task(const char *command);
int compare_strings(const char *str1, const char *str2);
char *tokenize_arguments(const char *task, char *args[]);
void process_arguments(int argc, char *argv[]);
int main(int argc, char *argv[]);
void env_builtin(void);

































#endif
