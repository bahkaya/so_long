/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:28:27 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:27:59 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_middle_walls(char *wall)
{
	int	i;
	int	len;

	len = ft_strlen(wall);
	i = 0;
	if (wall[i] != '1' || wall[len - 2] != '1')
		return (0);
	return (1);
}

void	ft_map_walls_check(t_map *map)
{
	int	i;

	i = 0;
	while (map->whole_map[i] != NULL)
	{
		if (i == 0 || i == map->file_y_len - 1)
		{
			if (ft_check_first_last_wall(map->whole_map[i]))
			{
				ft_printf("Error on first or last wall\n");
				ft_free(map->whole_map);
				exit(-1);
			}
		}
		else if (i != 0 && i != map->file_y_len - 1)
		{
			if (!ft_check_middle_walls(map->whole_map[i]))
			{
				ft_printf("Error on middle map\n");
				ft_free(map->whole_map);
				exit(-1);
			}
		}
		i++;
	}
}

int	ft_map_charscount_error_check(char map)
{
	char	player;
	char	coin;
	char	exit;

	player = 'P';
	coin = 'C';
	exit = 'E';
	if (map == '1')
		return (0);
	else if (map == '0')
		return (0);
	else if (map == player)
		return (0);
	else if (map == coin)
		return (0);
	else if (map == exit)
		return (0);
	return (1);
}

void	ft_map_chars_and_count_check(t_map *map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map->whole_map[i] != NULL)
	{
		k = 0;
		while (map->whole_map[i][k] != '\0' && map->whole_map[i][k] != '\n')
		{
			if ((ft_map_charscount_error_check(map->whole_map[i][k])))
			{
				ft_printf ("Invalid P/C/E/1/0 on map\n");
				ft_free(map->whole_map);
				exit(-1);
			}
			k++;
		}
		i++;
	}
}

void	ft_map_counts_check(t_map *map)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	while (map->whole_map[i] != NULL)
	{
		k = 0;
		while (map->whole_map[i][k] != '\0' && map->whole_map[i][k] != '\n')
		{
			if (map->whole_map[i][k] == 'P')
				map->p_count++;
			else if (map->whole_map[i][k] == 'C')
				map->c_count++;
			else if (map->whole_map[i][k] == 'E')
				map->e_count++;
			k++;
		}
		i++;
	}
	ft_check_how_many(map->p_count, map->e_count, map->c_count, map);
}
