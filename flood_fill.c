/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 21:52:30 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:46:44 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**ft_copy_map(t_stack *data, int y_len)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(sizeof(char *) * (y_len + 1));
	if (!map_copy)
		return (NULL);
	i = 0;
	while (data->map.whole_map[i] != NULL)
	{
		map_copy[i] = ft_strdup(data->map.whole_map[i]);
		if (!map_copy[i])
		{
			ft_free(map_copy);
			return (NULL);
		}
		i++;
	}
	map_copy[i] = NULL;
	return (map_copy);
}

static void	ft_flood_fill(char **map_copy, int x, int y, t_stack *data)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V')
		return ;
	if (map_copy[y][x] == 'C')
		(data->coins)++;
	if (map_copy[y][x] == 'E')
		data->exits = 1;
	map_copy[y][x] = 'V';
	ft_flood_fill(map_copy, x + 1, y, data);
	ft_flood_fill(map_copy, x - 1, y, data);
	ft_flood_fill(map_copy, x, y + 1, data);
	ft_flood_fill(map_copy, x, y - 1, data);
}

void	ft_map_path_check(t_stack *data)
{
	char	**map_copy;
	int		i;

	map_copy = ft_copy_map(data, data->map.file_y_len);
	if (!map_copy)
	{
		ft_free(data->map.whole_map);
		ft_printf("Error: Memory allocation failed\n");
		exit(-1);
	}
	i = -1;
	ft_find_player(data);
	ft_find_coin(data);
	data->coins = 0;
	data->exits = 0;
	ft_flood_fill(map_copy, data->x_p, data->y_p, data);
	if (data->coins != data->coin)
		ft_flood_exit(map_copy, data);
	if (!data->exits)
		ft_flood_exit(map_copy, data);
	ft_free(map_copy);
}
