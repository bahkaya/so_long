/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:46:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/06 21:03:34 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_files(t_map map)
{
	if(ft_strnstr(map.ber_file[1], ".ber", 4))
	{
		ft_printf("HATA\n");
		exit(-1);
	}
}
void	ft_check_map(t_stack data)
{
	ft_check_files(data.map);
		
}
