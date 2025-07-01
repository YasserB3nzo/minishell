
#include "../minishell.h"
#include "../libft/libft.h"
#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int g_exit_status =0;

void sigint_handler(int signo) {
    (void)signo; 
    printf("\n");
    rl_on_new_line();
    rl_replace_line("", 0);
    rl_redisplay();
}

int	main(void)
{
    signal(SIGINT, sigint_handler);
	char	*command_line;
	char	**comands;

	while (1)
	{
		command_line = readline("minishell >");
		comands = ft_split(command_line, ' ');
		exits(comands);
		if (!(ft_strncmp(comands[0], "pwd", ft_strlen(comands[0]))))
		{
			pwd(comands);
		}
	}
}
