/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 21:28:27 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/10 22:25:06 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_rectangle_check(t_map map)
{
	int	i;

	i = 0;
	map.file_x_len = ft_strlen(map.whole_map[i]);
	while (map.whole_map[i] != NULL)
		i++;
	map.file_y_len = i;
	if(map.file_x_len / map.file_y_len == 0)
	{
		ft_printf("Error: Map is square\n");
		// free
		exit(-1);
	}
}
int	ft_check_first_last_wall(char *wall)
{
	int	i;

	i = 0;
	while (wall[i] != "\0")
	{
		if (wall[i] == 1)
			i++;
		else
			return (1);
	}
	return (0);
}
int	ft_check_middle_walls(char *wall)
{
	int	i;
	int	len;

	len = ft_strlen(wall);
	i = 0;
	while (wall[i] != "\0")
	{
		if (i == 0 || i == len - 1)
		{
			if(wall[i] != 1 || wall[len - 1] != 1)
				return (1);
			else
				i++;
		}
		i++;
	}
	return (0);
}
void	ft_map_walls_check(t_map map)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (map.whole_map != NULL)
	{
		while (map.whole_map[i] != '\0') //Patlayabilir get nextlinedan dolayı sonradan bir bak \n mi yoksa \0 mu?
		{
			if(i == 0 || i == map.file_y_len - 1)
				if(!ft_check_first_last_wall(map.whole_map[i]))
				{
					ft_printf("Error on first or last wall\n");
					//free
					exit(-1);
				}
			else if (i != 0 || i != map.file_y_len)
			{
				ft_printf("Error on middle map\n");
				//free;
				exit(-1);
			}
		}
	}
}
int	ft_map_charscount_error_check(char map)
{
	char	player;
	char	coin;
	char	exit;

	player = 'p';
	coin = 'c';
	exit = 'e';
	if(map == 1)
		return (0);
	else if (map == 0)
		return (0);
	else if (map == player)
		return (0);
	else if (map == coin)
		return (0);
	else if (map == exit)
		return (0);
	return (1);
}

void	ft_map_chars_and_count_check(t_map map)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (map.whole_map[i] != NULL)
	{
		while(map.whole_map[i][k] != '\0')
		{
			if ((!ft_map_charscount_error_check(map.whole_map[i][k])))
			{
				ft_printf ("Invalid p/c/e/1/0 on map\n");
				//free;
				exit(-1);
			}
			else
				k++;
		}
		i++;
	}
}

void	ft_map_counts_check(t_map map)
{
	int		i;
	int		k;
	int		p_count;
	int		c_count;
	int		e_count;
	char	player;
	char	coin;
	char	exit;
	

	player = 'p';
	coin = 'c';
	exit = 'e';
	i = 0;
	k = 0;
	p_count = 0;
	e_count = 0;
	c_count = 0;
	while (map.whole_map[i] != NULL)
	{
		while(map.whole_map[i][k] != '\0')
		{
			if (map.whole_map[i][k] == 1 || map.whole_map[i][k] == 0)
				k++;
			else if (map.whole_map[i][k] == 'p')
				p_count;
			else if (map.whole_map[i][k] == 'c')
				c_count;
			else if (map.whole_map[i][k] == 'e')
				e_count++;
		}
		i++;
	}
	if (p_count != 1)
	{
		return ;
	}
	if (e_count != 1)
	{
		return ;
	}
	if (c_count < 1)
	{
		return ;
	}
}
//void	ft_map_path_check(t_map map);
