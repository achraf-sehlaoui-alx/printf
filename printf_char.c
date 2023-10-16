#include "main.h"

/**
 * printf_char - prints a binary number
 * @args: arg
 * @pr: the printed characters
 * Return: printed charcaters
 */

int printf_char(va_list args, int pr)
{
	int character = va_arg(args, int);

	_putchar(character);
	return (pr + 1);
}
