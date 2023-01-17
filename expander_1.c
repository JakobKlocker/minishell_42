#include "minishell.h"

int get_len_env_var(char *var)
{
    int i;

    i = 0;
    while(var[i] != ' ' && var[i] != '\n' && var[i] != '\0' && var[i] != '\'' && var[i] != '"')
        i++;
    return (i);
}

char    *get_env_for_var(t_info *info, char *dol_pos, int len)
{
    envlst_t *tmp;
    char    tmp_repl;
    char    *ret;
    tmp_repl = dol_pos[len];
    dol_pos[len] = '\0';
    tmp = info->envp;
    while(tmp)
    {
        if(ft_strnstr(tmp->var, dol_pos, len) && tmp->var[len] == '=')
        {
            ret = ft_strnstr(tmp->var, dol_pos, len) + len + 1;
            dol_pos[len] = tmp_repl;
            return (ret);
        }
        tmp = tmp->next;
    }
    dol_pos[len] = tmp_repl;
    return (NULL);
}
