#include "main.h"
#include <stdarg.h>

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */

int _printf(const char *format, ...) {
  va_list args;
  int count = 0;

  va_start(args, format);
  while (*format != '\0') {
    if (*format == '%') {
      switch (*(++format)) {
        case 'c':
          putc((char)va_arg(args, int), stdout);
          count++;
          break;
        case 's':
          fputs(va_arg(args, char *), stdout);
          count += strlen(va_arg(args, char *));
          break;
        case '%':
          putc('%', stdout);
          count++;
          break;
        default:
          // Handle other conversion specifiers here.
          break;
      }
    } else {
      putc(*format, stdout);
      count++;
    }
    format++;
  }
  va_end(args);

  return count;
}
