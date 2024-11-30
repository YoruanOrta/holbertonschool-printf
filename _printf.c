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
    char *str;

    if (!format)
        return (-1);

    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%' && format[i + 1])
        {
            i++;
            switch (format[i])
            {
                case 'd':
                case 'i':
                    count += printf("%d", va_arg(args, int));
                    break;
		case 'u':
		    count += printf("%u", va_arg(args, int));
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
		    putchar(format[i]);
		    count += 2;
            }
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
