/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 22:25:56 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:35:51 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_stack *data, int i, int width, int height)
{
	int	k;

	k = 0;
	while (data->map.whole_map[i][k] != '\0' &&
		data->map.whole_map[i][k] != '\n')
	{
		if (data->map.whole_map[i][k] == '1')
			mlx_put_image_to_window(data->mlx, data->window,
				data->img_w, k * width, i * height);
		else if (data->map.whole_map[i][k] == '0')
			mlx_put_image_to_window(data->mlx, data->window,
				data->img_f, k * width, i * height);
		else if (data->map.whole_map[i][k] == 'P')
			mlx_put_image_to_window(data->mlx, data->window,
				data->img_p, data->x_p * width, data->y_p * height);
		else if (data->map.whole_map[i][k] == 'E')
			mlx_put_image_to_window(data->mlx, data->window,
				data->img_e, k * width, i * height);
		else if (data->map.whole_map[i][k] == 'C')
			mlx_put_image_to_window(data->mlx, data->window,
				data->img_c, k * width, i * height);
		k++;
	}
}
