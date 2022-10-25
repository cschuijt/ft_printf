/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cschuijt <cschuijt@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 15:38:07 by cschuijt      #+#    #+#                 */
/*   Updated: 2022/10/25 11:34:42 by cschuijt      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int		ft_printf(const char *str, ...);

int		print_nbr_sb(long n, char *base);
int		print_nbr_b(unsigned long n, char *base);
int		print_string(char *str);
int		print_char(int c);
int		print_pointer(void *ptr);

size_t	ft_strlen(const char *s);
#endif
