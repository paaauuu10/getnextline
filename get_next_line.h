/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:16:10 by pbotargu          #+#    #+#             */
/*   Updated: 2023/11/07 14:20:53 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char    *get_next_line(int fd);
char    *ft_read(int fd, char *storage);
char    *ft_getlines(char *storage, int i);
char    *ft_free_storage(char **storage);
char    *ft_clean_storage(char *storage); 

#endif