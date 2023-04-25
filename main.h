#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**

struct buffer - buffer structure
@start: pointer to the start of the buffer
@len: length of the buffer
@size: size of the buffer
*/
typedef struct buffer
{
char *start;
int len;
int size;
} buffer_t;
/* printf functions */
void clear_printf_args(va_list args, buffer_t *output);
int execute_printf(const char *format, va_list args, buffer_t *output);
int _printf(const char *format, ...);
void free_buffer(buffer_t *output);
unsigned char handle_flags(const char *format, char *temp);
int handle_width(va_list args, const char *format, char *temp);
int handle_precision(va_list args, const char *format, char *temp);
unsigned char handle_length(const char *format, char *temp);
unsigned int (*handle_specifiers(const char *format))(va_list, buffer_t *,
unsigned char, int, int, unsigned char);
int _memcpy(buffer_t *output, const char *src, int n);
buffer_t *init_buffer(void);

#endif /* MAIN_H */
