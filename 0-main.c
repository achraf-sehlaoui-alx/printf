#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
int len;
int len2;

len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");
_printf("Length:[%d, %i]\n", len, len);
printf("Length:[%d, %i]\n", len2, len2);
_printf("Negative:[%d]\n", -762534);
printf("Negative:[%d]\n", -762534);



_printf("Should print a single percent sign: %%\n");
printf("Should print a single percent sign: %%\n");
_printf("css%ccs%scscscs", 'T', "Test");
printf("css%ccs%scscscs", 'T', "Test");
_printf("%c", '\0');
printf("%c", '\0');
_printf("%");
printf("%");
_printf("%!\n");
printf("%!\n");

return (0);
}
