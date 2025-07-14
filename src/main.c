/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:06:53 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/14 18:23:48 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	char	*input;
	t_data	data;
	(void)argc;
	(void)argv;

	set_signal();
	while(1)
	{
		input = readline("minishell$ ");
		if(!input)
			ft_error("exit");
		if(*input)
			add_history(input);
		split_arg(input, &data);
		execute_cmd(envp, &data);
		free(input);
	}
	return(0);
}
