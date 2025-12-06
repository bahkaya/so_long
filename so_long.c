/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 15:40:10 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/06 19:34:30 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
//TODO:
https://harm-smits.github.io/42docs/libs/minilibx

mlx init
mlx_new_window
mlx_destroy_window
mlx_put_image_to_window
mlx_destroy_wiimage //emin değilim bi bak
mlx_key_hook
mlx_loop
mlx_xpm_to_image

Bu case e dikkat ya exit ın üzerinden geçicek yada map invalid olacak.
11111
1PEC1
11111


Dosya uzantısını kontrol etmek olmalı.
x.ber

The map must be rectangular.

 At every move, the current number of movements must be displayed in the shell.

 collactable ın üzerineyken collatable değişkenini 1 azaltman lazım ve orayı 0 yapman lazım
 yani zemin görseli ile değiştrmen lazım
 
 Map ekran boyutundan büyükse oyunu açma direkt hata döndür ve çık.

 flood_fill algortimasını öğrenmen lazım ve bununla mapini kontol etmen lazım.
 
  If any misconfiguration is encountered in the file, the program must exit cleanly,
and return "Error\n" followed by an explicit error message of your choice.
Altına hata mesajın

pixel kullanman yasak uğraşma geç

*/

#include "solong.h"

int	key_handler(t_stack **data)
{
	if ((*data)->key_code == 65307)
	{
		exit (0);
	}
	return 0;
}

int main()
{
	t_stack *data;

	data = NULL;
	data = malloc(sizeof(t_stack));
	data->height = 32;
	data->width = 32;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, 1280, 640, "so_long");
	data->img_w = mlx_xpm_file_to_image(data->mlx, "./Wall.xpm", &data->width, &data->height);
	data->img_e = mlx_xpm_file_to_image(data->mlx, "./Exit.xpm", &data->width, &data->height);
	data->img_p = mlx_xpm_file_to_image(data->mlx, "./Player.xpm", &data->width, &data->height);
	data->img_f = mlx_xpm_file_to_image(data->mlx, "./Floor.xpm", &data->width, &data->height);
	data->img_c = mlx_xpm_file_to_image(data->mlx, "./Coin.xpm", &data->width, &data->height);

	mlx_hook(data->window, 2, 1L>> 0, key_handler, &data);
	mlx_put_image_to_window(data->mlx, data->window, data->img_w, 0* 128 , 0*128);
	mlx_put_image_to_window(data->mlx, data->window, data->img_w, 0* 128 , 1*128);
	mlx_put_image_to_window(data->mlx, data->window, data->img_w, 0* 128 , 2*128);
	mlx_put_image_to_window(data->mlx, data->window, data->img_w, 0* 128 , 3*128);
	mlx_put_image_to_window(data->mlx, data->window, data->img_w, 0* 128 , 4*128);
	mlx_loop(data->mlx);
}