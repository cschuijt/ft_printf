/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 11:14:17 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/28 14:42:34 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"

static int	replace_percent(const char *str, va_list valist)
{
	str++;
	if (*str == 'c')
		return (print_char(va_arg(valist, int)));
	if (*str == 's')
		return (print_string(va_arg(valist, char *)));
	if (*str == 'p')
	{
		write(1, "0x", 2);
		return (2 + print_pointer(va_arg(valist, unsigned long)));
	}
	if (*str == 'x')
		return (print_nbr_ub(va_arg(valist, long), "0123456789abcdef"));
	if (*str == 'X')
		return (print_nbr_ub(va_arg(valist, long), "0123456789ABCDEF"));
	if (*str == 'd' || *str == 'i')
		return (print_nbr_b(va_arg(valist, int), "0123456789"));
	if (*str == 'u')
		return (print_nbr_ub(va_arg(valist, unsigned int), "0123456789"));
	if (*str == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (-1);
}

int	funny_little_loop_function(const char *str, va_list valist)
{
	int	i;
	int	j;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			j = replace_percent(str, valist);
			if (j < 0)
				str++;
			else
			{
				str += 2;
				i += j;
			}
		}
		else
		{
			i += write(1, str, 1);
			str++;
		}
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list		valist;
	int			i;

	va_start(valist, str);
	i = funny_little_loop_function(str, valist);
	va_end(valist);
	return (i);
}
