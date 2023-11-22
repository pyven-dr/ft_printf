/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:36:09 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/21 11:44:00 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	add_i(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	if (n == 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_putnbr(long n)
{
	char	nb;

	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		n = -n;
	}
	nb = 48 + (n % 10);
	if (n / 10 == 0)
	{
		if (write(1, &nb, 1) == -1)
			return (-1);
		return (0);
	}
	if (ft_putnbr(n / 10) == -1)
		return (-1);
	if (write(1, &nb, 1) == -1)
		return (-1);
	return (0);
}

int	ft_printf_int(int n, int *i)
{
	*i += add_i(n);
	return (ft_putnbr(n));
}
