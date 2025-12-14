/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:40:10 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:51:18 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_handler(int key_code, t_stack *data)
{
	if (key_code == 65307)
	{
		ft_free(data->map.whole_map);
		destroy_image(data);
		exit (0);
	}
	if (key_code == 119)
	{
		ft_move_up(data);
	}
	if (key_code == 97)
	{
		ft_move_left(data);
	}
	if (key_code == 115)
	{
		ft_move_down(data);
	}
	if (key_code == 100)
	{
		ft_move_right(data);
	}
	return (0);
}

// makefileda -g var ona dikkat et en son sil!
int	main(int ac, char **av)
{
	t_stack	data;

	if (ac == 2)
	{
		data.map.ber_file_check = av;
		ft_check_map(&data);
		data.height = 128;
		data.width = 128;
		data.pressed = 0;
		ft_find_player(&data);
		ft_find_coin(&data);
		ft_window_start(&data);
		ft_put_assests_on_map(&data);
		mlx_hook(data.window, 2, 1L >> 0, key_handler, &data);
		mlx_hook(data.window, 17, 0, exit_button, &data);
		mlx_loop(data.mlx);
	}
}
