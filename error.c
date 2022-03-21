/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinestr <fsinestr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:35:08 by fsinestr          #+#    #+#             */
/*   Updated: 2022/03/21 13:37:05 by fsinestr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    return (0);
}

void    *nll_error(char *message)
{
    write(2, "Error\n", 6);
    write(2, message, ft_strlen(message));
    return ((void *) 0);
}