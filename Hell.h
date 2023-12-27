#ifndef HELL_H
#define HELL_H



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


/*
 * Functions
 */

void sayne_print(const char *note);
void interpret_command(char *instruction, size_t size);
void display_prompt(void);
void accomplish_task(const char *task);




































#endif
