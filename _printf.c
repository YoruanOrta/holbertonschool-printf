#include "main.h"

/**
 * _printf - Custom implementation of printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
	return (-1);

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			i++;
			count += manage_specifier(format[i], args);
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
