#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct buffer_s
{
	char *start;
	size_t index;
	size_t len;
	size_t size;
} buffer_t;

buffer_t *init_buffer(void);
int free_buffer(buffer_t *buffer);
int _memcpy(buffer_t *dest, const char *src, size_t n);

unsigned char handle_flags(const char *format, char *temp);
int handle_width(va_list args, const char *format, char *temp);
int handle_precision(va_list args, const char *format, char *temp);
unsigned char handle_length(const char *format, char *temp);
unsigned int (*handle_specifiers(const char *format))(va_list,
		buffer_t *, unsigned char, int, int, unsigned char);

void clear_printf_args(va_list args, buffer_t *output);
int execute_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);

#endif /* MAIN_H */

