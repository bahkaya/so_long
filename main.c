#include "minilibx-linux/mlx.h"
#include <stdlib.h>

int	key_handler(t_stack **data)
{
	t_stack	*temp;


	if (keycode == 65307)
	{
		exit (0);
	}
	return 0;
}

int main()
{
	
	game.height = 128;
	game.width = 128;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, 1280, 640, "so_long");
	game.img_w = mlx_xpm_file_to_image(game.mlx, "./Wall.xpm", &game.width, &game.height);
	game.img_e = mlx_xpm_file_to_image(game.mlx, "./Exit.xpm", &game.width, &game.height);
	game.img_p = mlx_xpm_file_to_image(game.mlx, "./Player.xpm", &game.width, &game.height);
	game.img_f = mlx_xpm_file_to_image(game.mlx, "./Floor.xpm", &game.width, &game.height);
	game.img_c = mlx_xpm_file_to_image(game.mlx, "./Coin.xpm", &game.width, &game.height);

	mlx_hook(game.window, 2, , key_handler, &game);
	mlx_put_image_to_window(game.mlx, game.window, game.img_w, 0* 128 , 0*128);
	mlx_put_image_to_window(game.mlx, game.window, game.img_w, 0* 128 , 1*128);
	mlx_put_image_to_window(game.mlx, game.window, game.img_w, 0* 128 , 2*128);
	mlx_put_image_to_window(game.mlx, game.window, game.img_w, 0* 128 , 3*128);
	mlx_put_image_to_window(game.mlx, game.window, game.img_w, 0* 128 , 4*128);
	mlx_loop(game.mlx);
}