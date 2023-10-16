#include "main.h"

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formatted string
*/

int _printf(const char *format, ...)
{

int printed = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
	if (*format == '%')
	{
		format++;
		switch (*format)
		{
			case 'd':
			case 'i':
				printed = printf_integer(args, printed);
				break;
			case 'c':
				_putchar(va_arg(args, int));
				printed++;
				break;
			case 's':
				printed = printf_string(args, printed);
				break;
			case '%':
				_putchar('%');
				printed++;
				break;
			default:
				break;
		}
	}
	else
	{
		_putchar(*format);
		printed++;
	}
	format++;
}
	va_end(args);
	return (printed);
}

