#include "minishell.h"

char    *get_envp(char **envp)
{
    int i;
    char *full_envp;

    while(envp[i])
    {
        if(ft_strncmp(envp[i], "PATH=", 5) == 0)
            return(envp[i] + 5);
        i++;
    }
    return(NULL);
}

int     find_valid_path(char **paths, char **envp, t_token *token)
{
    char    *temp;
    char    *full_path;
    int i;

    while(paths[i])
    {
        temp = ft_strjoin(paths[i], "/");
        full_path = ft_strjoin(temp, token->str);
        free(temp);
        if(!full_path)
            return(0);
        if(access(full_path, X_OK) == 0)
        {
            execve(full_path, token->str, envp);
            free(full_path);
            return(1);
        }
        free(full_path);
        i++;
    }
    return(0);
}

void   execute_cmd(char **envp, t_data *data)
{
    char    *full_envp;
    char    **paths;

    full_envp = get_envp(envp);
    paths = ft_split(full_envp, ':');
    if(!paths)
        return ;
    if(!find_valid_path(paths, envp, data->token));
        ft_free("command not found", paths, 127);
    //free and exit
}