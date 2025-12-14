/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:38:47 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:02:42 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_stack(t_link *a)
{
	t_link	*tmp;

	while (a != NULL)
	{
		free(a->line);
		tmp = a->next;
		free (a);
		a = tmp;
	}
}

void	ft_error_return_stack(char *arr_digit, t_link *head)
{
	write(2, "Error\n", 6);
	free(arr_digit);
	free_stack(head);
	exit(-1);
}

void	ft_error_return_link(char *arr_digit, t_link *head)
{
	write(2, "Error\n", 6);
	free(arr_digit);
	free_stack(head);
	exit(-1);
}

void	ft_check_how_many(int p_count, int e_count, int c_count, t_map *map)
{
	if (p_count != 1)
	{
		ft_printf("No player /or more than 1 player map\n");
		ft_free(map->whole_map);
		exit(-1);
	}
	if (e_count != 1)
	{
		ft_printf("No exit /or more than 1 exit map\n");
		ft_free(map->whole_map);
		exit(-1);
	}
	if (c_count < 1)
	{
		ft_printf("No coin on map\n");
		ft_free(map->whole_map);
		exit(-1);
	}
}

void	ft_check_map(t_stack *data)
{
	t_link	*map;

	map = NULL;
	ft_check_files(data->map);
	ft_check_map_suitable(&data->map);
	map = ft_put_map_on_link(&data->map);
	data->map = ft_put_map_on_map(map, data->map);
	ft_map_rectangle_check(&data->map);
	ft_map_walls_check(&data->map);
	ft_map_chars_and_count_check(&data->map);
	ft_map_counts_check(&data->map);
	ft_map_path_check(data);
}
