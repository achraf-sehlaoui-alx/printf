#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/

/**
 * print_unsigned - Prints unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int Number = va_arg(types, unsigned long int);

	Number = convert_size_unsignedd(Number, size);

	if (Number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (Number > 0)
	{
		buffer[i--] = (Number % 10) + '0';
		Number /= 10;
	}
	i++;
	return (write_unsignedd(0, i, buffer, flags, width, precision, size));
}


/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/

/**
 * print_oct - Prints an unsigned number in octal notation
 * @types: Lists of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int Number = va_arg(types, unsigned long int);
	unsigned long int init_Number = Number;

	UNUSED(width);

	Number = convert_size_unsignedd(Number, size);

	if (Number == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (Number > 0)
	{
		buffer[i--] = (Number % 8) + '0';
		Number /= 8;
	}

	if (flags & F_HASH && init_Number != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsignedd(0, i, buffer, flags, width, precision, size));
}


/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/

/**
 * print_hex_dec - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hex_dec(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**
 * print_hex_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hex_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hex(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEX NUM IN LOWER OR UPPER **************/

/**
 * print_hex - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle prints
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_hex(va_list types, char map_to[], char buffer[],
	char flag_ch, int flags,  int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int Number = va_arg(types, unsigned long int);
	unsigned long int init_Number = Number;

	UNUSED(width);

	Number = convert_size_unsignedd(Number, size);

	if (Number == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (Number > 0)
	{
		buffer[i--] = map_to[Number % 16];
		Number /= 16;
	}
	if (flags & F_HASH && init_Number != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsignedd(0, i, buffer, flags, width, precision, size));
}
