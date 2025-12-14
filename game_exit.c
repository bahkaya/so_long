/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:11:43 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:22:35 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_game_exit(t_stack *data)
{
	data->pressed++;
	ft_printf("Move %d\n", data->pressed);
	ft_free(data->map.whole_map);
	destroy_image(data);
	exit(0);
}

void	ft_flood_exit(char **map_copy, t_stack *data)
{
	ft_printf("Error: Not all coins are reachable\n");
	ft_free(map_copy);
	ft_free(data->map.whole_map);
	exit(-1);
}

void	ft_map_rectangle_check(t_map *map)
{
	int	i;
	int	len;
	int	cur;

	i = 0;
	len = ft_strlen(map->whole_map[0]);
	if (map->whole_map[0][len - 1] == '\n')
		len--;
	while (map->whole_map[i])
	{
		cur = ft_strlen(map->whole_map[i]);
		if (map->whole_map[i][cur - 1] == '\n')
			cur--;
		if (cur != len)
		{
			ft_printf("Error: Map is not rectangular\n");
			ft_free(map->whole_map);
			exit(1);
		}
		i++;
	}
	map->file_x_len = len;
	map->file_y_len = i;
}

int	ft_check_first_last_wall(char *wall)
{
	int	i;

	i = 0;
	while (wall[i] != '\0' && wall[i] != '\n')
	{
		if (wall[i] == '1')
			i++;
		else
			return (1);
	}
	return (0);
}
