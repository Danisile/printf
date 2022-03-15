#include "main.h"
<<<<<<< HEAD
/**
 * opFunction - Second function for _printf
 * @cont: Contador
 * @list: Lista arguments
 * @tipos: Tipos que nos trae el JSON
 * @format: Formato
 * Return: Len
*/
int opFunction(int cont, va_list list, typedate tipos[], const char *format)
{
int i = 0, j = 0, band = 0, spaces = 0;
while (format && format[i])
{
	band = 0;
	if (format[i] == '%' && format[i + 1] == '\0')
	return (-1);
	else if (format[i] == '%' && format[i + 1] != '%')
	{
		for (j = 0; j < 7; j++)
		{
			if (format[i] == '%' && format[i + spaces + 1] == tipos[j].typec)
			{
				cont += tipos[j].fun(list);
				i += spaces + 1;
				band = 1;
			}
		}
		if (band == 0 && format[i + 2] != '\n')
		{
			_putchar(format[i]);
			cont++;

		}
		else if (band == 0 && format[i + 2] == '\n')
		{
			_putchar(format[i]);
			cont++;
		}
	}
	else if (format[i] == '%' && format[i + 1] == '%')
	{
		i += _putchar('%');
		cont += 1;
	}
	else
		cont += _putchar(format[i]);
	i++;
}
	return (cont);
}
/**
 * _printf - Printf!!
 * @format: Format
 * Return: len
 */
int _printf(const char *format, ...)
{
typedate tipos[] = {
	{'s', printString}, {'c', printChar}, {'i', printInteger},
	{'d', printDecimal}, {'b', printBinary}, {'o', printOctal},
	{'u', printUnsigned}
};
va_list list;
int cont = -1;

if (format != NULL)
{
va_start(list, format);
cont = 0;
cont = opFunction(cont, list, tipos, format);
va_end(list);
}
return (cont);
=======

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, len = 0, ibuf = 0;
	va_list arguments;

	int (*function)(va_list, char *, unsigned int);
	char *buffer;
	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], ibuf), len++, i--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
>>>>>>> f7000c82f6f8ad3e2e87f7b0c1e7b8c7f830e7fe
}

