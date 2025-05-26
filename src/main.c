#include "../libft/libft.h"
#include "../minishell.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

void	pwd(void)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	if (cwd)
	{
		write(1, cwd, ft_strlen(cwd));
		write(1, "\n", 1);
		free(cwd);
	}
}

int	main(void)
{
	char	*command_line;
	char	**comands;

	while (1)
	{
		command_line = readline("minishell >");
		comands = ft_split(command_line, ' ');
		if (!(ft_strncmp(comands[0], "pwd", ft_strlen(comands[0]))))
		{
			pwd();
		}
		if (ft_strncmp(comands[0], "exit", ft_strlen(comands[0])))
		{
			return (0);
		}
	}
}
