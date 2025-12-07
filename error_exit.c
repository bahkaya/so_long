/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 22:38:47 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/07 22:40:37 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_stack(t_link *a)
{
	t_link	*tmp;

	while (a != NULL)
	{
		tmp = a->next;
		free (a);
		a = tmp;
	}
}

void	ft_error_return_stack(char *arr_digit, t_stack *head)
{
	write(2, "Error\n", 6);
	free(arr_digit);
	free_stack(head);
	exit(-1);
}