/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:46:19 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/11 20:13:19 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void ft_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}

void	ft_error_malloc()
{
	exit(EXIT_FAILURE);
	//free list
}