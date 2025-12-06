/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:22:41 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/06 21:00:30 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <errno.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct s_map
{
	char	**whole_map;
	char	*line_map;
	char	**ber_file;
	int		i;
	int		k;
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
}	t_stack;


void	ft_check_map(t_stack data);
int		key_handler(int key_code, t_stack *data);

#endif