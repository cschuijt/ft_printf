/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:38:07 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/24 23:07:52 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/libft.h"

int	ft_printf(const char *str, ...);

int	print_nbr_sb(long n, char *base);
int	print_nbr_b(unsigned long n, char *base);
int	print_string(char *str);
int	print_char(int c);
int	print_pointer(void *ptr);
#endif
