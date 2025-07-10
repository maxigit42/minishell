/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwilline <mwilline@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:06:53 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/08 19:36:44 by mwilline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(void)
{
	char	*input;

	set_signal();
	while(1)
	{
		input = readline("minishell$ ");
		if(!input)
			ft_error("exit");
		if(*input)
			add_history(input);
		printf("comando recibido: %s\n", input);
		free(input);
	}
	return(0);
}


