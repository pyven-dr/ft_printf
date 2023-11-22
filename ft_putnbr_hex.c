/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:24:06 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/21 16:26:31 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hex(unsigned int nbr, char *base, int *i)
{
	if (nbr / 16 == 0)
	{
		if (write(1, &base[nbr % 16], 1) == -1)
			return (-1);
		*i += 1;
		return (0);
	}
	if (ft_putnbr_hex(nbr / 16, base, &*i) == -1 || \
		write(1, &base[nbr % 16], 1) == -1)
		return (-1);
	*i += 1;
	return (0);
}
