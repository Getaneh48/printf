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
    int len, len2;
    unsigned int ui;
    void *addr;

    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");


   _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);

    _printf("_digit: %d\n", INT_MAX);
   printf("digit: %d\n", INT_MAX);

	_printf("%r\n","Let's try to printf a simple sentence.\n");
	_printf("%R\n","Let's try to printf a simple sentence.\n");
   	_printf("%R\n","Yrg'f gel gb cevags n fvzcyr fragrapr.\n");

	_printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);

    _printf("_binary: [%b]\n", 100);
    printf("binary: [%b]\n", 10024);
    
    len = _printf("Unsigned octal:[%o]\n", ui);
    len2 = printf("Unsigned octal:[%o]\n", ui);
    printf("_Length: [%d]\n", len);
    printf("Length: [%d]\n", len2);
    
    _printf("Unsigned hexadecimal:[%x, %X]\n", 9223372036854775807, 9223372036854775807);
    printf("Unsigned hexadecimal:[%x, %X]\n", 9223372036854775807, 9223372036854775807);
    
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);

    return (0);
}
