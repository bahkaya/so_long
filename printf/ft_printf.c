/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 12:47:23 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/15 13:37:11 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start (args, format);
	count = 0;
	while (*format)
	{
		if (format[0])
		{
			count += ft_flags_check(format);
			if (count == -1)
				return (count);
		}
		if (*format == '%')
		{
			count += ft_format(*(format + 1), args);
			format += 2;
		}
		else if (*format != '%')
			count += ft_putchar(*format++);
	}
	va_end(args);
	return (count);
}

int	ft_putstr_itoa(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	free(s);
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
