/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:22:41 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:32:23 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include "minilibx-linux/mlx.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct s_map
{
	char	**whole_map;
	char	*line_map;
	char	**ber_file_check;
	int		ber_file_fd;
	int		file_x_len;
	int		file_y_len;
	int		p_count;
	int		c_count;
	int		e_count;
}	t_map;

typedef struct s_stack
{
	t_map	map;
	void	*mlx;
	void	*window;
	int		height;
	int		width;
	void	*img_w;
	void	*img_p;
	void	*img_e;
	void	*img_f;
	void	*img_c;
	int		key_code;
	int		x_p;
	int		y_p;
	int		coin;
	int		pressed;
	int		coins;
	int		exits;
}	t_stack;

typedef struct s_link
{
	char			*line;
	struct s_link	*next;
}	t_link;

typedef struct s_update
{
	int		x_p;
	int		y_p;
	int		new_ground;
}	t_update;

void	ft_check_map(t_stack *data);
int		key_handler(int key_code, t_stack *data);
t_link	*ft_link_malloc_a(char *line);
t_map	ft_put_map_on_map(t_link *map, t_map map_info);
t_link	*ft_put_map_on_link(t_map *map);
void	ft_error_return_stack(char *arr_digit, t_link *head);
int		ft_stack_size(t_link *a);
void	free_stack(t_link *a);
void	ft_error_return_link(char *arr_digit, t_link *head);
void	ft_map_rectangle_check(t_map *map);
void	ft_map_walls_check(t_map *map);
void	ft_map_chars_and_count_check(t_map *map);
void	ft_map_counts_check(t_map *map);
void	ft_map_path_check(t_stack *data);
void	ft_window_start(t_stack *data);
void	ft_put_assests_on_map(t_stack *data);
void	ft_find_player(t_stack *data);
void	ft_move_up(t_stack *data);
void	ft_move_down(t_stack *data);
void	ft_move_left(t_stack *data);
void	ft_move_right(t_stack *data);
void	ft_find_coin(t_stack *data);
void	ft_free(char **str_is_digit);
void	destroy_image(t_stack *data);
int		exit_button(t_stack *data);
void	ft_check_files(t_map map);
void	ft_check_map_suitable(t_map *map);
void	ft_check_how_many(int p_count, int e_count, int c_count, t_map *map);
void	ft_game_exit(t_stack *data);
void	ft_flood_exit(char **map_copy, t_stack *data);
int		ft_check_first_last_wall(char *wall);
void	ft_map_rectangle_check(t_map *map);
void	put_image(t_stack *data, int i, int width, int height);
#endif