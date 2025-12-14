/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 15:04:03 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 23:24:51 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_window_start(t_stack *data)
{
	int	height;
	int	width;

	data->mlx = mlx_init();
	if (!data->mlx)
		exit(-1);
	width = data->map.file_x_len * data->height;
	height = data->map.file_y_len * data->height;
	data->window = mlx_new_window(data->mlx, width, height, "so_long");
	data->img_w = mlx_xpm_file_to_image(data->mlx, "./assets/Wall.xpm",
			&data->width, &data->height);
	data->img_e = mlx_xpm_file_to_image(data->mlx, "./assets/Exit.xpm",
			&data->width, &data->height);
	data->img_p = mlx_xpm_file_to_image(data->mlx, "./assets/Player.xpm",
			&data->width, &data->height);
	data->img_f = mlx_xpm_file_to_image(data->mlx, "./assets/Floor.xpm",
			&data->width, &data->height);
	data->img_c = mlx_xpm_file_to_image(data->mlx, "./assets/Coin.xpm",
			&data->width, &data->height);
}

void	ft_put_assests_on_map(t_stack *data)
{
	int	height;
	int	width;
	int	i;
	int	k;

	i = 0;
	k = 0;
	width = data->height;
	height = data->height;
	while (data->map.whole_map[i] != NULL)
	{
		put_image(data, i, width, height);
		i++;
	}
	check_screen_size(data);
}

void	destroy_image(t_stack *data)
{
	if (!data)
		return ;
	if (data)
	{
		mlx_destroy_image(data->mlx, data->img_w);
		mlx_destroy_image(data->mlx, data->img_e);
		mlx_destroy_image(data->mlx, data->img_p);
		mlx_destroy_image(data->mlx, data->img_f);
		mlx_destroy_image(data->mlx, data->img_c);
	}
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}

int	exit_button(t_stack *data)
{
	ft_free(data->map.whole_map);
	destroy_image(data);
	exit(0);
}

void	check_screen_size(t_stack *data)
{
	int	height;
	int	width;

	mlx_get_screen_size(data->mlx, &width, &height);
	if (width < (data->width * data->map.file_x_len)
		|| height < (data->height * data->map.file_x_len))
	{
		ft_printf("Screen is big\n");
		ft_free(data->map.whole_map);
		destroy_image(data);
		exit(-1);
	}
}
