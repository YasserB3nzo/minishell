#include "../../minishell.h"

t_env	*g_env = NULL;

t_env	*lstnew_env(char *name, char *value)
{
	t_env	*node;

	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->name = name;
	node->value = value;
	node->next = NULL;
	return (node);
}
void	lstadd_env(t_env **lst, t_env *new)
{
	t_env	*temp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	lst_env_create(char **envp)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	while (envp[i])
	{
		temp = ft_split(envp[i], '=');
		lstadd_env(&g_env, lstnew_env(temp[0], temp[1]));
		i++;
	}
	return (1);
}
int	export(char **envp)
{
	lst_env_create(envp);
}
