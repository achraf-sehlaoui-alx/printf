#include "main.h"

/**
 * printf_string - prints a string
 * @args: numberof arguements
 * @pr: the printed characters
 * Return: printed charcaters
 */

int printf_string(va_list args, int pr)
{
	char *string = va_arg(args, char *);

	while (*string != '\0')
	{
		_putchar(*string);
		pr++;
		string++;
	}
	return (pr);
}
