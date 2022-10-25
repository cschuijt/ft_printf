/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 11:14:17 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/25 11:34:55 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "ft_printf.h"

static int	replace_percent(const char *str, va_list *valist)
{
	str++;
	if (*str == '\0')
		return (0);
	if (*str == 'c')
		return (print_char(va_arg(*valist, int)));
	if (*str == 's')
		return (print_string(va_arg(*valist, char *)));
	if (*str == 'p')
		return (print_pointer(va_arg(*valist, void *)));
	if (*str == 'x')
		return (print_nbr_b(va_arg(*valist, long), "0123456789abcdef"));
	if (*str == 'X')
		return (print_nbr_b(va_arg(*valist, long), "0123456789ABCDEF"));
	if (*str == 'd' || *str == 'i')
		return (print_nbr_b(va_arg(*valist, long), "0123456789"));
	if (*str == 'u')
		return (print_nbr_sb(va_arg(*valist, unsigned long), "0123456789"));
	if (*str == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list			valist;
	unsigned int	i;

	i = 0;
	va_start(valist, str);
	while (*str)
	{
		if (*str == '%')
		{
			i += replace_percent(str, &valist);
			str++;
		}
		else
		{
			write(1, str, 1);
			i++;
		}
		str++;
	}
	va_end(valist);
	return (i);
}
