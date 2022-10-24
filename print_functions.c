/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 21:17:31 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/24 23:18:20 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"
#include "libftprintf.h"

int	print_nbr_sb(long n, char *base)
{
	long	bl;
	int		i;

	i = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	bl = ft_strlen(base);
	if (n > bl)
		print_nbr_sb(n / bl, base);
	write(1, &base[n % bl], 1);
	while (n)
	{
		n /= bl;
		i++;
	}
	return (i);
}

int	print_nbr_b(unsigned long n, char *base)
{
	size_t	bl;
	int		i;

	bl = ft_strlen(base);
	if (n > bl)
		print_nbr_b(n / bl, base);
	write(1, &base[n % bl], 1);
	i = 0;
	while (n)
	{
		n /= bl;
		i++;
	}
	return (i);
}

int	print_string(char *str)
{
	int	l;

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
	i += print_nbr_b((long) ptr, "0123456789abcdef");
	return (i);
}
