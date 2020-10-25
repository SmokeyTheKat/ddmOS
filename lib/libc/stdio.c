#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <limits.h>
#include <stdbool.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif


static bool print(const char* _c, size_t _l)
{
	const unsigned char* b = (const unsigned char*)_c;
	for (size_t i = 0; i < _l; i++)
		if (putchar(b[i]) == EOF)
			return false;
	return true;
}


int printf(const char* restrict format, ...) {
	va_list parameters;
	va_start(parameters, format);
 
	int written = 0;
 
	while (*format != '\0') {
		size_t maxrem = INT_MAX - written;
 
		if (format[0] != '%' || format[1] == '%') {
			if (format[0] == '%')
				format++;
			size_t amount = 1;
			while (format[amount] && format[amount] != '%')
				amount++;
			if (maxrem < amount) {
				return -1;
			}
			if (!print(format, amount))
				return -1;
			format += amount;
			written += amount;
			continue;
		}
 
		const char* format_begun_at = format++;
 
		if (*format == 'c') {
			format++;
			char c = (char) va_arg(parameters, int);
			if (!maxrem) {
				return -1;
			}
			if (!print(&c, sizeof(c)))
				return -1;
			written++;
		} else if (*format == 's') {
			format++;
			const char* str = va_arg(parameters, const char*);
			size_t len = strlen(str);
			if (maxrem < len) {
				return -1;
			}
			if (!print(str, len))
				return -1;
			written += len;
		} else {
			format = format_begun_at;
			size_t len = strlen(format);
			if (maxrem < len) {
				return -1;
			}
			if (!print(format, len))
				return -1;
			written += len;
			format += len;
		}
	}
 
	va_end(parameters);
	return written;
}

int puts(const char* _c)
{
	return printf("%s\n", _c);
}

int putchar(int _c)
{
#if defined(__is_libk)
	char c = (char)_c;
	terminal_write_char(c);
#else
#endif
	return _c;
}
