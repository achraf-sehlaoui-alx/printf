#include <stdarg.h>
#include <stdio.h>
#include "main.h"

void _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%' && *(format + 1) == 'b')
        {
            // Handle the custom specifier %b
            unsigned int num = va_arg(args, unsigned int);
            unsigned int mask = 1 << (sizeof(unsigned int) * 8 - 1); // Create a mask
            int found_digit = 0;

            while (mask > 0)
            {
                if (num & mask)
                {
                    putchar('1');
                    found_digit = 1;
                }
                else if (found_digit)
                {
                    putchar('0');
                }
                mask >>= 1;
            }

            format += 2; // Skip past %b
        }
        else
        {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}
