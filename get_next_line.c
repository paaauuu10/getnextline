/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:17:45 by pbotargu          #+#    #+#             */
/*   Updated: 2023/11/07 14:20:14 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_free_storage(char **storage)
{
    free(*storage);
    *storage = NULL;
    return (NULL);
}


    
char    *get_next_line(int fd)
{
    static char *storage;
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    storage = ft_read(fd, storage);
    if(!storage)
        return (NULL);
    line = ft_getlines(storage, 0);
    if (!line)
        return (ft_free_storage(&storage));
    storage = ft_clean_storage(storage);
    return (line);        
}