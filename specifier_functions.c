#include "main.h"

/****************** PRECISION CALCULATION ****************/

/**
 * precision_calc - calculates the precision for printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * @list: list of arguments
 * Return: Precision
 */

int precision_calc(const char *format, int *i, va_list list)
{
	int curr_Pos = *i + 1;
	int precision = -1;

	if (format[curr_Pos] != '.')
		return (precision);

	precision = 0;

	for (curr_Pos += 1; format[curr_Pos] != '\0'; curr_Pos++)
	{
		if (is_digit(format[curr_Pos]))
		{
			precision *= 10;
			precision += format[curr_Pos] - '0';
		}
		else if (format[curr_Pos] == '*')
		{
			curr_Pos++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_Pos - 1;

	return (precision);
}


/******************  FLAGS CALCULATION ****************/

/**
 * flags_calc - calculates active flags
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * Return: flags
 */

int flags_calc(const char *format, int *i)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_Pos;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_Pos = *i + 1; format[curr_Pos] != '\0'; curr_Pos++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_Pos] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}

		if (FLAGS_CH[j] == 0)
			break;
	}

	*i = curr_Pos - 1;

	return (flags);
}


/****************** SIZE CALCULATION ****************/


/**
 * size_calc - calculates the size to cast the argument
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * Return: size
 */

int size_calc(const char *format, int *i)
{
	int curr_Pos = *i + 1;
	int size = 0;

	if (format[curr_Pos] == 'l')
		size = S_LONG;
	else if (format[curr_Pos] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_Pos - 1;
	else
		*i = curr_Pos;

	return (size);
}


/******************  WIDTH CALCULATION ****************/

/**
 * width_calc - calculates the width for printing
 * @format: formatted string in which to print the arguments
 * @i: list of arguments to be printed
 * @list: list of arguments
 * Return: width
 */

int width_calc(const char *format, int *i, va_list list)
{
	int curr_Pos;
	int width = 0;

	for (curr_Pos = *i + 1; format[curr_Pos] != '\0'; curr_Pos++)
	{
		if (is_digit(format[curr_Pos]))
		{
			width *= 10;
			width += format[curr_Pos] - '0';
		}
		else if (format[curr_Pos] == '*')
		{
			curr_Pos++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_Pos - 1;

	return (width);
}

