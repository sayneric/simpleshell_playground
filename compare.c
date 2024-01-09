#include "Hell.h"

/**
 * compare_strings - compare two strings case-insensitively
 * @str1: first string
 * @str2: second string
 *
 * Return: returns \0 for both strings on success
 */

int compare_strings(const char *str1, const char *str2)
{
	while (*str1 != '\0' && *str2 != '\0' && tolower(*str1) == tolower(*str2))
	{
		str1++;
		str2++;
	}

	return (*str1 == '\0' && *str2 == '\0');
}
