#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdarg.h>
#include "holberton.h"

/**
 *int_casting - cast char to int
 * @charnum: char number to cast
 * Return: the actual number
 */
int int_casting(char *charnum)
{
    int i, j;
    int intnum, num;
    
    for (i = 0; charnum[i] != '\0'; i++)
    {
        num = charnum[i] - '0';
        for (charnum[j] = strlen(charnum - 1); charnum[j] != 0; j--)
        {
            num *= 10;
        }
        intnum += num;
    }
    return intnum;
}
/**
 * mul - infinite multiplication
 * @a: number of arguments
 * @b: number of arguments
 * Return: result
*/
int mul (int a, int b)
{
    return a * b;
}

/**
 * checker - check if arguments are valid
 * @argv: argument to check
 * Return: 0 or -1
*/
int checker(char *argv)
{
    while (argv)
    {
        if (int_casting(argv) >= 48 || int_casting(argv) <= 57);
        else
            return -1;

    }
    return 0;
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
    return;
}

/**
 * main - main fun
 * @argc: argument counter
 * @argv: arguments
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
    return resmul;

}