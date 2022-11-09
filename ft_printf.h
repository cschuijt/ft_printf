/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:38:07 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/26 14:44:46 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int		ft_printf(const char *str, ...);

int		printf_nbr_b(int n, char *base);
int		printf_nbr_ub(unsigned int n, char *base);
int		printf_string(char *str);
int		printf_char(int c);
int		printf_pointer(unsigned long n);

size_t	ft_strlen(const char *s);
#endif
