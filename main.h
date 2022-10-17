#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(char *s);
char *int_to_binary(int num);
char *int_to_octal(long int num);
char *int_to_hex(long int num);
char *_toupper(char *str);
char *ntochar(int d);
void _int_to_str(long int num, char *buf, int);
char *intostr(long int);
void _handleS(char *str, int *nchar);
int print_hex(va_list args, char format);
int print_p(va_list args);
char *rev_string(char *);
int print_r(va_list args);
int print_R(va_list args);
char *_strcpy(char *dest, char *src);
void aschii_tr_table(int *atbl, int min, int max, int shift);
char *rot13(char *s);
int print_di(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_b(va_list args);
#endif
