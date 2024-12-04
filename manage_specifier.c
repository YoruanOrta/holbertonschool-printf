#include "main.h"

/**
 * manage_specifier - Handles different specifiers for _printf
 * @format: Format specifier
 * @args: List of arguments
 * Return: Number of characters printed
 */
int manage_specifier(char format, va_list args)
{
	char *str;
	int count = 0;

	switch (format)
	{
		case 'd': case 'i':
		count += printf("%d", va_arg(args, int));
		break;
		case 'u':
		count += printf("%u", va_arg(args, unsigned int));
		break;
		case 'o':
		count += printf("%o", va_arg(args, unsigned int));
		break;
		case 'x':
		count += printf("%x", va_arg(args, unsigned int));
		break;
		case 'X':
		count += printf("%X", va_arg(args, unsigned int));
		break;
		case 's':
		str = va_arg(args, char *);
		count += printf("%s", str ? str : "(null)");
		break;
		case 'c':
		count += printf("%c", va_arg(args, int));
		break;
		case 'p':
		count += printf("%p", va_arg(args, void *));
		break;
		case '%':
		count += printf("%%");
		break;
		default:
		putchar('%');
		putchar(format);
		count += 2;
	}
	return (count);
}
