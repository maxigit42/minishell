/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:07:42 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/14 15:20:38 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <readline/readline.h>
#include <readline/history.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <libft.h>
#include "message.h"

typedef struct s_token
{
	int				type;
	char			*str;
	
	int				infile;
	int				outfile;
	int				heredoc;
	int				append;
	int				cmd;

	struct s_token	*next;
}	t_token;

typedef struct t_data
{
    struct t_token *token;
} t_data;

//parse
void    split_arg(char *args, t_data *data);
void    put_lstback(t_token **head, t_token *new);
void    get_token_type(char **args, t_token *token);
t_token     *ft_token_new(char *str);

// utils
void ft_error(char *str);
void	free_split(char **str);

//signs
void    set_signal(void);
void 	ctrl_c(int sig);

#endif