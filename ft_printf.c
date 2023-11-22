/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pyven-dr <pyven-dr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:47:02 by pyven-dr          #+#    #+#             */
/*   Updated: 2023/11/22 17:25:06 by pyven-dr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conversion(char arg, va_list ap, int *i)
{
	if (arg == 'c')
		return (ft_putchar((char)va_arg(ap, int), &*i));
	else if (arg == 's')
		return (ft_putstr(va_arg(ap, char *), &*i));
	else if (arg == 'p')
		return (ft_print_adress((unsigned long)va_arg(ap, void *), \
			&*i, "0123456789abcdef"));
	else if (arg == 'd' || arg == 'i')
		return (ft_printf_int(va_arg(ap, int), &*i));
	else if (arg == 'u')
		return (ft_printf_unsigned(va_arg(ap, unsigned int), &*i));
	else if (arg == 'x')
		return (ft_putnbr_hex(va_arg(ap, unsigned int), \
			"0123456789abcdef", &*i));
	else if (arg == 'X')
		return (ft_putnbr_hex(va_arg(ap, unsigned int), \
			"0123456789ABCDEF", &*i));
	else if (arg == '%')
		return (ft_putchar('%', &*i));
	if (write(1, "%", 1) == -1 || \
		write(1, &arg, 1) == -1)
		return (-1);
	*i += 2;
	return (0);
}

int	ft_printf(const	char *format, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, format);
	i = 0;
	if (format == NULL)
		i = -1;
	while (format[0] != '\0' || i == -1)
	{
		if (format[0] == '%')
		{
			if (conversion(format[1], ap, &i) == -1)
				i = -1;
			format += 2;
		}
		else if (format[0] != '\0' && format[0] != '%')
		{
			if (write(1, &format[0], 1) == -1)
				i = -2;
			format++;
			i++;
		}
	}
	va_end(ap);
	return (i);
}
