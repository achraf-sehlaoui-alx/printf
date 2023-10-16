#include "main.h"

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */

int _printf(const char *format, ...)
{
	int pr = 0;

	va_list args;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			pr = switch_function(format, args, pr);
			format++;
		}
		else
		{
			_putchar(*format);
			pr++;
			format++;
		}
	}
	va_end(args);
	return (pr);
}
