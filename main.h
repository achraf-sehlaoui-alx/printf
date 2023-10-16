#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int _putchar(char character);

int printf_char(va_list args, int pr);
int printf_string(va_list args, int pr);
int printf_integer(va_list args, int pr);

int switch_function(const char *format, va_list args, int pr);
int _printf(const char *format, ...);


#endif
