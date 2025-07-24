#include "../../minishell.h"
#include <stdio.h>

int	export(t_env* envt, char *input)
{
	char **arg = ft_split(input, '=');
	if(arg[1]==NULL)
	{
		while (envt) {
			printf("%s=%s",envt->name, envt->value);
			envt=envt->next;
		}
		exit(1);
	}
	else if(arg[2])
	{
		



	}

	


}
