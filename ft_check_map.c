/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:01:45 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 21:32:19 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **str_is_digit)
{
	int	i;

	i = 0;
	while (str_is_digit[i] != NULL)
	{
		free(str_is_digit[i]);
		i++;
	}
	free(str_is_digit);
}

void	ft_check_files(t_map map)
{
	size_t	len;

	len = ft_strlen(map.ber_file_check[1]);
	if (len < 4 || ft_strncmp(map.ber_file_check[1] + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error on ber file\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map_suitable(t_map *map)
{
	map->ber_file_fd = open(map->ber_file_check[1], O_RDONLY, 0644);
	if (map->ber_file_fd == -1)
	{
		ft_printf("File error\n");
		close(map->ber_file_fd);
		exit(-1);
	}
}

t_link	*ft_put_map_on_link(t_map *map)
{
	t_link	*whole_map;
	t_link	*temp;

	whole_map = NULL;
	temp = NULL;
	map->file_y_len = 0;
	map->line_map = get_next_line(map->ber_file_fd);
	map->file_x_len = ft_strlen(map->line_map);
	if (!map->line_map)
		exit(-1);
	while (map->line_map != NULL)
	{
		whole_map = ft_link_malloc_a(map->line_map);
		if (!whole_map)
			ft_error_return_link(map->line_map, whole_map);
		whole_map->next = temp;
		temp = whole_map;
		free(map->line_map);
		map->line_map = get_next_line(map->ber_file_fd);
		map->file_y_len++;
	}
	free(map->line_map);
	close(map->ber_file_fd);
	return (whole_map);
}

t_map	ft_put_map_on_map(t_link *map, t_map map_info)
{
	t_link	*tmp;
	int		i;

	i = 0;
	tmp = map;
	map_info.whole_map = malloc(sizeof(char *) * (map_info.file_y_len + 1));
	while (tmp != NULL)
	{
		map_info.whole_map[i] = ft_strdup(tmp->line);
		if (!map_info.whole_map[i])
		{
			ft_free(map_info.whole_map);
			free_stack(map);
		}
		i++;
		tmp = tmp->next;
	}
	map_info.whole_map[i] = NULL;
	free_stack(map);
	return (map_info);
}
