/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:23 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/21 15:27:43 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_printf(const	char *format, ...);
int	ft_putchar(char c, int *i);
int	ft_putstr(char *s, int *i);
int	ft_printf_int(int n, int *i);
int	ft_printf_unsigned(unsigned int n, int *i);
int	ft_putnbr_hex(unsigned int nbr, char *base, int *i);
int	ft_print_adress(unsigned long adress, int *i, char *base);
int	ft_strchr(const char *s, int c);

#endif