/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:12:44 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:46:44 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_stack *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->map.whole_map[y - 1][x] == '1')
		return ;
	if (data->map.whole_map[y - 1][x] == 'C')
		data->coin--;
	if (data->map.whole_map[y - 1][x] == 'E' && data->coin != 0)
		return ;
	if (data->map.whole_map[y - 1][x] == 'E' && data->coin == 0)
		ft_game_exit(data);
	data->map.whole_map[y][x] = '0';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_f, x * 128, y * 128);
	data->y_p -= 1;
	data->map.whole_map[data->y_p][data->x_p] = 'P';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_p, data->x_p * 128, data->y_p * 128);
	data->pressed++;
	ft_printf("Move %d\n", data->pressed);
}

void	ft_move_down(t_stack *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->map.whole_map[y + 1][x] == '1')
		return ;
	if (data->map.whole_map[y + 1][x] == 'C')
		data->coin--;
	if (data->map.whole_map[y + 1][x] == 'E' && data->coin != 0)
		return ;
	if (data->map.whole_map[y + 1][x] == 'E' && data->coin == 0)
		ft_game_exit(data);
	data->map.whole_map[y][x] = '0';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_f, x * 128, y * 128);
	data->y_p += 1;
	data->map.whole_map[data->y_p][data->x_p] = 'P';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_p, data->x_p * 128, data->y_p * 128);
	data->pressed++;
	ft_printf("Move %d\n", data->pressed);
}

void	ft_move_left(t_stack *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->map.whole_map[y][x - 1] == '1')
		return ;
	if (data->map.whole_map[y][x - 1] == 'C')
		data->coin--;
	if (data->map.whole_map[y][x - 1] == 'E' && data->coin != 0)
		return ;
	if (data->map.whole_map[y][x - 1] == 'E' && data->coin == 0)
		ft_game_exit(data);
	data->map.whole_map[y][x] = '0';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_f, x * 128, y * 128);
	data->x_p -= 1;
	data->map.whole_map[data->y_p][data->x_p] = 'P';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_p, data->x_p * 128, data->y_p * 128);
	data->pressed++;
	ft_printf("Move %d\n", data->pressed);
}

void	ft_move_right(t_stack *data)
{
	int	x;
	int	y;

	x = data->x_p;
	y = data->y_p;
	if (data->map.whole_map[y][x + 1] == '1')
		return ;
	if (data->map.whole_map[y][x + 1] == 'C')
		data->coin--;
	if (data->map.whole_map[y][x + 1] == 'E' && data->coin != 0)
		return ;
	if (data->map.whole_map[y][x + 1] == 'E' && data->coin == 0)
		ft_game_exit(data);
	data->map.whole_map[y][x] = '0';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_f, x * 128, y * 128);
	data->x_p += 1;
	data->map.whole_map[data->y_p][data->x_p] = 'P';
	mlx_put_image_to_window(data->mlx, data->window,
		data->img_p, data->x_p * 128, data->y_p * 128);
	data->pressed++;
	ft_printf("Move %d\n", data->pressed);
}
