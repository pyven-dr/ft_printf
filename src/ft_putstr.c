/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:12:35 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/24 14:05:00 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *i)
{
	size_t	len;

	if (s == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		*i += 6;
		return (0);
	}
	len = ft_strlen(s);
	if (write(1, s, len) == -1)
		return (-1);
	*i += len;
	return (0);
}
