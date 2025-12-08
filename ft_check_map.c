/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:46:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/08 21:23:13 by bahkaya          ###   ########.fr       */
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
		ft_printf("Error:\nInvalid file extension\n");
		exit(EXIT_FAILURE);
	}
}
void	ft_check_map_suitable(t_map map)
{
	char	*ber_file_location;

	ber_file_location = ft_strjoin("./map", map.ber_file_check);
	map.ber_file_fd = open(ber_file_location, O_RDONLY, 0644);
	if (!map.ber_file_fd || map.ber_file_fd != 3)
	{
		free(ber_file_location);
		close(ber_file_location);
		//error message
		exit(-1);
	}
}

t_link	*ft_put_map_on_link(t_map map)
{
	t_link	*whole_map;
	t_link	*temp;

	whole_map = NULL;
	temp = NULL;
	map.line_map = get_next_line(map.ber_file_fd);
	map.file_x_len = ft_strlen(map.line_map);
	map.file_x_len = 0;
	if(!map.line_map)
		exit(-1); // Plus the error message
	while (map.line_map != NULL)
	{
		whole_map = ft_link_malloc_a(map.line_map);
		if (!whole_map)
			ft_error_return_stack(map.line_map, whole_map);
		whole_map->next = temp;
		temp = whole_map;
		free(map.line_map);
		get_next_line(map.ber_file_fd);
		map.file_y_len++;
	}
	close(map.ber_file_fd);
	return (whole_map);
}

t_map	ft_put_map_on_map(t_link *map, t_map map_info)
{
	t_link *tmp;
	int		i;

	i = 0;
	tmp = map;
	while (tmp != NULL)
	{
		map_info.file_y_len = ft_stack_size(map);
		map_info.whole_map = malloc(sizeof(char *) * map_info.file_x_len + 1);
		if(!map_info.whole_map)
			exit(-1); // plus the error message
		map_info.whole_map[i] = ft_strdup(map->line);
		i++;
		map = map->next;
	}
	map_info.whole_map[i] = NULL;
	free_stack(map);
	return (map_info);
}

void	ft_check_map(t_stack data)
{
	t_link	*map;
	
	map = NULL;
	ft_check_files(data.map);
	ft_check_map_suitable(data.map);
	map = ft_put_map_on_link(data.map);
	data.map = ft_put_map_on_map(map, data.map);
	
}
