/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:22:41 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/06 20:40:32 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"

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
}	t_stack;

typedef struct s_map
{
	char	**whole_map;
	char	*line_map;
	int		wall_fd;
	int		player_fd;
	int		coin_fd;
	int		exit_fd;
	int		floor_fd;
	int		i;
	int		k;
}	t_map;

int	key_handler(t_stack **data);

#endif