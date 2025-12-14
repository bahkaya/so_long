/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_link_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:19:51 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/14 22:01:19 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_link	*ft_link_malloc_a(char *line)
{
	t_link	*map_whole;

	map_whole = malloc(sizeof(t_stack));
	if (!map_whole)
		exit(-1);
	map_whole->line = ft_strdup(line);
	map_whole->next = NULL;
	return (map_whole);
}

int	ft_stack_size(t_link *a)
{
	int		i;
	t_link	*tmp;

	i = 0;
	tmp = a;
	while (tmp != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
