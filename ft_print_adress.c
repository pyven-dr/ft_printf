/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_adress.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:25:15 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/21 19:15:46 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_adress(unsigned long nb, int *i, char *base)
{
	if (nb / 16 == 0)
	{
		if (write(1, &base[nb % 16], 1) == -1)
			return (-1);
		*i += 1;
		return (0);
	}
	if (ft_put_adress(nb / 16, &*i, base) == -1 || \
		write(1, &base[nb % 16], 1) == -1)
		return (-1);
	*i += 1;
	return (0);
}

int	ft_print_adress(unsigned long nb, int *i, char *base)
{
	if (nb == 0)
	{
		if (write(1, "(nil)", 5) == -1)
			return (0);
		*i += 5;
		return (1);
	}
	if (write(1, "0x", 2) == -1)
		return (-1);
	*i += 2;
	ft_put_adress(nb, &*i, base);
	return (0);
}
