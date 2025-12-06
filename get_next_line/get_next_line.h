/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:11:13 by bahkaya           #+#    #+#             */
/*   Updated: 2025/12/06 18:54:07 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif 

char	*get_next_line(int fd);
char	*gnl_ft_strdup(char *s);
char	*gnl_ft_strjoin(char *temp, char *buffer);
char	*gnl_ft_strchr(char *s, int c);
char	*gnl_ft_substr(char *s, unsigned int start, size_t len);
char	*new_temp(char *temp);
size_t	gnl_ft_strlen(char *str);
char	*get_line(char *temp);
#endif