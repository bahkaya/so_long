/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:22:41 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/06 19:01:20 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include "./printf/ft_printf.h"

typedef struct s_stack
{
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

int	key_handler(t_stack **data);

#endif