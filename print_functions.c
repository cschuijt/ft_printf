/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 21:17:31 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/25 16:54:07 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	print_nbr_b(long long int n, char *base, int c)
{
	long	bl;
	int		i;

	i = 1;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	bl = ft_strlen(base);
	if (n >= bl)
		print_nbr_b(n / bl, base);
	write(1, &base[n % bl], 1);
	while (n >= bl)
	{
		n /= bl;
		i++;
	}
	return (i);
}

int	print_string(char *str)
{
	int	l;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	l = ft_strlen(str);
	write(1, str, l);
	return (l);
}

int	print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	print_pointer(void *ptr)
{
	int	i;

	i = 2;
	write(1, "0x", 2);
	i += print_nbr_b((unsigned long) ptr, "0123456789abcdef");
	return (i);
}
