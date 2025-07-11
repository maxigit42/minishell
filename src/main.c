/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:06:53 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/11 19:42:53 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char	*input;
	t_data	data;

	set_signal();
	while(1)
	{
		input = readline("minishell$ ");
		if(!input)
			ft_error("exit");
		if(*input)
			add_history(input);
		split_arg(input, &data);
		printf("comando recibido: %s\n", input);
		free(input);
	}
	return(0);
}


