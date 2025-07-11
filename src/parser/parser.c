/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximo <maximo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 19:15:44 by mwilline          #+#    #+#             */
/*   Updated: 2025/07/11 20:39:14 by maximo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_token     *ft_token_new(char *str)
{
    t_token  *new;
    
    new = malloc(sizeof(t_token));
    if(!new)
    ft_error_malloc(); //acabar este funcion
    new->str = ft_strdup(str);
    new->type = 0;
    new->infile = 0;
    new->outfile = 0;
    new->heredoc = 0;
    new->append = 0;
    new->cmd = 0;
    return(new);
}

void    get_token_type(char **args, t_token *token)
{
    int i;
    
    i = 0;
    while(args[i])
    {
        if(ft_strncmp(args[i], ">", 1) == 0)
        token->outfile++;
        else if(ft_strncmp(args[i], "<", 1) == 0)
            token->infile++;
        else if(ft_strncmp(args[i], ">>", 2) == 0)
            token->append++;
            else if(ft_strncmp(args[i], "<<", 2) == 0)
            token->heredoc++;
        i++;
    }
}

void    put_lstback(t_token **head, t_token *new)
{
    t_token *temp;

    if(!head || !new)
        return;
    if(!*head)
    {
        *head = new;
        return;
    }
    temp = *head;
    while(temp->next)
        temp = temp->next;
    temp->next = new;
}

void    split_arg(char *args, t_data *data)
{
    char **token_array;
    int i;
    t_token *new;

    i = 0;
    token_array = ft_split(args, ' ');
    if (!token_array)
        return ;
    while(args[i])
    {
        new = ft_token_new(token_array[i]);
        get_tokens_type(token_array[i], new);
        put_lstback(&(data->token), new);
        i++;
    }
    free_split(token_array); //crear funcion
}
