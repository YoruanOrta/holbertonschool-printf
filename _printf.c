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
                case 's':
                    str = va_arg(args, char *);
                    count += printf("%s", str ? str : "(null)");
                    break;
                case 'c':
                    count += printf("%c", va_arg(args, int));
                    break;
                case '%':
                    count += printf("%%");
                    break;
                default:
                    count += printf("%%c", format[i]);
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
