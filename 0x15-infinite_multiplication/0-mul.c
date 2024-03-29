#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * int_casting - cast char to int
 * @charnum: char number to cast
 *
 * Return: the actual number
 */

int int_casting(char *charnum)
{
	int i, j;
	int intnum, num, pow;

	intnum = 0;

	for (i = 0; charnum[i] != '\0'; i++)
	{
		num = charnum[i] - '0';
		pow = 1;
		for (j = strlen(charnum - 1); j >= i; j--)
		{
			num = num * pow;
			pow = pow * 10;
		}
		intnum += num;
	}
	return (intnum);
}

/**
 * mul - infinite multiplication
 * @a: number of arguments
 * @b: number of arguments
 *
 * Return: result
 */

int mul(int a, int b)
{
	return (a * b);
}

/**
 * checker - check if arguments are valid
 * @argv: argument to check
 *
 * Return: 0 or -1
 */

int checker(char *argv)
{
	int i;

	for (i = 0; argv[i] != '\0'; i++)
	{
		if ((argv[i] < 48) || (argv[i] > 57))
			return (-1);
	}
	return (0);
}

/**
 * _putstr - print string
 * @str: string to print
 *
 * Return: nothing
 */

void _putstr(char *str)
{
	unsigned int i;

	for (i = 0; i < strlen(str); i++)
		_putchar(str[i]);
}

/**
 * main - main fun
 * @argc: argument counter
 * @argv: arguments
 *
 * Return: 0 for success 98 for failure
 */

int main(int argc, char **argv)
{
	char *error = "Error";
	int a, b, resmul;

	if (argc < 3 || argc > 3)
	{
		_putstr(error);
		_putchar('\n');
		exit(98);
	}

	if (checker(argv[1]) != 0 || checker(argv[2]) != 0)
	{
		_putstr(error);
		_putchar('\n');
		exit(98);
	}
	a = int_casting(argv[1]);
	b = int_casting(argv[2]);
	resmul = mul(a, b);
	printf("%d\n", resmul);
	return (0);
}
