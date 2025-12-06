/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:16:32 by bahkaya           #+#    #+#             */
/*   Updated: 2025/07/14 18:40:26 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_flag(char format, char *flags)
{
	int	i;

	i = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] == format)
			return (1);
		i++;
	}
	return (0);
}

int	ft_flags_check(const char *format)
{
	int		i;
	int		sign;
	char	*flags;

	i = 0;
	sign = '%';
	flags = "scdiuxXp%";
	while (format[i] != '\0')
	{
		if (format[i] == sign && !ft_flag(format[i + 1], flags))
		{
			write(1, "Expected extra % or wrong flag\n", 32);
			return (-1);
		}
		if (format[i] == sign && format [i + 1] == sign)
			i += 2;
		else
			i++;
	}
	return (0);
}
