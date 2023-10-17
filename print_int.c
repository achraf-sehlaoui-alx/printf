/************************* PRINT INT *************************/
/**
 * print_int - Print int Number
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int Number;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	Number = (unsigned long int)n;

	if (n < 0)
	{
		Number = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (Number > 0)
	{
		buffer[i--] = (Number % 10) + '0';
		Number /= 10;
	}

	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
