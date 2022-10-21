#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <stdarg.h>
int _printf(const char *fmt, ...);
int format_handler(const char *fmt, int index, int *nchar, va_list args);
int get_modifier(const char *fmt, int index);
int print_s(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);
int process_format(const char *fmt, char mdf,
		int fsp_sindex, int fsp_eindex, int val_length, void *val);
char *_strcat(char *dest, char *src);
int _power(int base, int exp);
int _atoi(char *num);
int _extract_number(const char *str, int s_index, int e_index);
int _last_flag(const char *fmt, int s_index, int e_index);
char *_int_tostr(long int);
int print_c(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);
void print_percent(int *nchar);
void print_b(va_list args, int *nchar);
void print_S(va_list args, int *nchar);
void print_r(va_list args, int *nchar);
void print_R(va_list args, int *nchar);
int print_o(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);
char *int_to_octal(long int num);
int print_p(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);
int print_x(const char *fmt, char f, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);
int print_u(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);

int move_char_onfirstindex(char *print, char flag);
int check_flag_exist(const char *fmt, int s_index, int e_index, char flag);
void handle_plusF(char mdf, char *print, int *printedchar, void *val);
void handle_minusF(const char *fmt, int j, char *print);
char *handle_zeroF(char mdf, int width, int val_length,
		int *printedchar, char *print);
void handle_spaceF(const char *fmt, int j, char mdf,
		int w, int vl, int *pchar, char *print);
void handl_hashtagF(char mdf, char *print, int *pchar);
void print_noflag(char mdf, int width, int val_length, int *pchar);
void dispatch_flag(const char *fmt,
		int j,
		char flag, char mdf, char *print, int *pchar, void *val, int width, int vl);

int _printf(const char *format, ...);
int _putchar(char c);
int _strlen(const char *s);
char *int_to_binary(int num);
char *int_to_hex(long int num);
char *_toupper(char *str);
char *ntochar(int d);
void _int_to_str(long int num, char *buf, int);
char *intostr(long int);
char *rev_string(char *);
char *_strcpy(char *dest, char *src);
void aschii_tr_table(int *atbl, int min, int max, int shift);
char *rot13(char *s);
int print_di(const char *fmt, int fsp_sindex,
		int fsp_eindex, int *nchar, va_list args);
#endif
