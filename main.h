#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* DEFINE  SIZES */
#define S_SHORT 1
#define S_LONG 2

/* DEFINE FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/**
 * struct Format_Spec - Struct format hundler
 * @specifier: The format Specifier
 * @prc_Fnc: The processed function associated
 */

struct Format_Spec
{
	char specifier;
	int (*prc_Fnc)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct Format_Spec Format_Spec_t - Struct format hundler
 * @Format_Spec: The format Specifier
 * @Format_Spec_t: The processed function associated
 */

typedef struct FormatSpec FormatSpec_t;

/****************** *****************/

int _printf(const char *format, ...);
int printByFormat(const char *Format_Spec, int *ind,
		va_list list, char buffer[], int flags,
		int width, int precision, int size);

/***************** FUNCTIONS CALL ********************/

/* Print chars and strings */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_str(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print numbers */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hex_dec(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hex(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width,
		int precision, int size);

/* Print non printable characters */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Handle other specifiers */

int precision_calc(const char *format, int *i, va_list list);
int flags_calc(const char *format, int *i);
int size_calc(const char *format, int *i);
int width_calc(const char *format, int *i, va_list list);

/* Print string in reverse */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Print a string in rot 13 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Width handler */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif /* MAIN_H */
