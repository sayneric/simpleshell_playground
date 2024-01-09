#ifndef HELL_H
#define HELL_H

/*
 * Macros
 */
#define INITIAL_BUFFER_SIZE 1024
#define MAX_ARGUMENTS 100
#define MAX_COMMAND_LENGTH 1000

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
#include <stdbool.h>
#include <ctype.h>



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
void set_last_element_to_null(char *args[], int arg_index);
char *handle_quotes_and_escapes(char *token, bool *in_quotes);
char *custom_strtok(char *str, const char *delimiters);
char *custom_getline(void);
char *read_input(size_t *buffer_size, size_t *buffer_pos);






























#endif
