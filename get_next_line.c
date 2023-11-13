/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:17:45 by pbotargu          #+#    #+#             */
/*   Updated: 2023/11/13 11:33:23 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_free_storage(char **storage)
{
    free(*storage);
    *storage = NULL;
    return (NULL);
}

char    *ft_get_lines(char *storage, int i)
{
    char    *memory;
    if (!storage[i])
        return (NULL);
    while (storage[i] && storage[i] != '\n');
        i++;
    if (storage[i] == '\n')
        i++;
    memory = (char *)malloc((i + 1) * sizeof(char));
    if (!memory)
        return (NULL);
    i = 0;
    while (storage[i] && storage[i] != '\n')
    {
        memory[i] = storage [i];
        i++;
    }
    memory[i] = '\0';
    return (memory);
}
char    *ft_read(int fd, char *storage)
{
    char    *memory;
    int     bytes;

    memory = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!memory)
        return (ft_free_storage(&storage));
    bytes = 1;
    while (!ft_strchr(storage, '\n') && bytes != 0)
    {
        bytes = read(fd, memory, BUFFER_SIZE);
        if (bytes == -1)
        {
            ft_free_storage(&storage);
            ft_free_storage(&memory);
            return (NULL);
        }
        memory[bytes] = '\0';
        storage = ft_strjoin(&storage, memory);
    }
    ft_free_storage(&memory);
    return (storage);

    
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
    line = ft_get_lines(storage, 0);
    if (!line)
        return (ft_free_storage(&storage));
    storage = ft_clean_storage(storage);
    return (line);        
}