/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:22:41 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/07 22:40:45 by bahkaya          ###   ########.fr       */
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

typedef struct s_link
{
	char	*line;
	struct s_link	*next;
	
}	t_link;

void	ft_check_map(t_stack data);
int		key_handler(int key_code, t_stack *data);
t_link	*ft_link_malloc_a(char *line);
void	ft_error_return_stack(char *arr_digit, t_stack *head);

#endif