/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:12:15 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/15 13:58:54 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(int format, va_list args)
{
	int		count;
	char	sign;

	count = 0;
	sign = '%';
	if (format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (format == sign)
		count += ft_putchar(sign);
	else if (format == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (format == 'd')
		count += ft_putstr_itoa(ft_itoa(va_arg(args, int)));
	else if (format == 'i')
		count += ft_putstr_itoa(ft_itoa(va_arg(args, int)));
	else if (format == 'u')
		count += ft_putstr_itoa(ft_itoa_unsgined(va_arg(args, unsigned int)));
	else if (format == 'x')
		count += ft_print_hex_lower(va_arg(args, unsigned int));
	else if (format == 'X')
		count += ft_print_hex_upper(va_arg(args, unsigned int));
	else if (format == 'p')
		count += p_hex(va_arg(args, void *));
	return (count);
}
