#include "main.h"

/**
 * switch_function - selects the appropriate specifiers
 * @args: number of arguements
 * @pr: the printed characters
 * @format: the format specifier
 * Return: printed charcaters
 */

int switch_function(const char *format, va_list args, int pr)
{
	switch (*format)
	{
		case 'd':
		case 'i':
			pr = printf_integer(args, pr);
			break;
		case 'c':
			_putchar(va_arg(args, int));
			pr++;
			break;
		case 's':
			pr = printf_string(args, pr);
			break;
		case '%':
			_putchar('%');
			pr++;
			break;
		default:
			break;
	}
	return (pr);
}

