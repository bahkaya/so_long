/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:21:28 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 21:31:18 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_find_player(t_stack *data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (data->map.whole_map[i] != NULL)
	{
		k = 0;
		while (data->map.whole_map[i][k] != '\0'
			&& data->map.whole_map[i][k] != '\n')
		{
			if (data->map.whole_map[i][k] == 'P')
			{
				data->x_p = k;
				data->y_p = i;
				return ;
			}
			k++;
		}
		i++;
	}
}

void	ft_find_coin(t_stack *data)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	data->coin = 0;
	while (data->map.whole_map[i] != NULL)
	{
		k = 0;
		while (data->map.whole_map[i][k] != '\0'
			&& data->map.whole_map[i][k] != '\n')
		{
			if (data->map.whole_map[i][k] == 'C')
				data->coin++;
			k++;
		}
		i++;
	}
}
