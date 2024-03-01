/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrusu <mrusu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:24:39 by mrusu             #+#    #+#             */
/*   Updated: 2023/12/02 13:22:26 by mrusu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_chr(int c)
{
	return (write(1, &c, 1));
}

static int	ft_printf_chk(char conversions, va_list ap)
{
	int	return_v;

	return_v = 0;
	if (conversions == 'c')
		return_v += ft_print_chr(va_arg(ap, int));
	else if (conversions == 's')
		return_v += ft_putsrt(va_arg(ap, char *));
	else if (conversions == 'p')
		return_v += ft_print_ptr(va_arg(ap, size_t));
	else if (conversions == 'd' || conversions == 'i')
		return_v += ft_print_digits((long)va_arg(ap, int), 10, 'x');
	else if (conversions == 'u')
		return_v += ft_print_unsigned((unsigned long)va_arg(ap, unsigned int));
	else if (conversions == 'x')
		return_v += ft_print_digits((long)va_arg(ap, unsigned int), 16, 'x');
	else if (conversions == 'X')
		return_v += ft_print_digits((long)va_arg(ap, unsigned int), 16, 'X');
	else if (conversions == '%')
		return_v += write(1, &conversions, 1);
	return (return_v);
}

int	ft_printf(const char *str, ...)
{
	int			return_v;
	va_list		ap;

	va_start (ap, str);
	return_v = 0;
	while (*str)
	{
		if (*str == '%')
			return_v += ft_printf_chk(*(++str), ap);
		else
			return_v += write(1, str, 1);
		++str;
	}
	va_end(ap);
	return (return_v);
}
