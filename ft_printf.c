/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 11:14:17 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/24 18:20:14 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>
#include "libft/libft.h"

static unsigned int	count_arguments(const char *str)
{
	unsigned int	i;

	i = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) != '%')
				i++;
			if (*(str + 1) == '\0')
				return (i);
			str = str + 2;
		}
		str++;
	}
	return (i);
}

static int	put_nbr(long i, char *base, char c)
{
	unsigned long	u;
	int				n;

	u = i;
	n = 0;
	if (c == 'd' || c == 'i' || c == 'x' || c == 'X')
	{
		if (i < 0)
		{
			write(1, "-", 1);
			n++;
		}
		return (n + ft_put_nbr_base(i, base));
	}
	return (ft_put_nbr_base(u, base));
}

static int	put_str(char *str, char c)
{
	int	len;

	if (c == 'c')
		len = 1;
	else
		len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

static int	replace_percent(const char *str, va_list *valist)
{
	str++;
	if (*str == '\0')
		return (0);
	if (*str == 'c' || *str == 's')
		return (put_str(va_arg(*valist, char *), *str));
	if (*str == 'p')
	{
		write(1, "0x", 2);
		return (2 + put_nbr(va_arg(*valist, long), "0123456789abcdef", *str));
	}
	if (*str == 'x')
		return (put_nbr(va_arg(*valist, long), "0123456789abcdef", *str));
	if (*str == 'X')
		return (put_nbr(va_arg(*valist, long), "0123456789ABCDEF", *str));
	if (*str == 'd' || *str == 'i' || *str == 'u')
		return (put_nbr(va_arg(*valist, long), "0123456789", *str));
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
	unsigned int	argc;
	unsigned int	i;

	i = 0;
	argc = count_arguments(str);
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
