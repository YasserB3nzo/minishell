#include "../../minishell.h"

extern int g_exit_status;

static int	is_numeric(const char *str)
{
	int i = 0;

	if (!str)
		return 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return 0;
		i++;
	}
	return 1;
}

void exits(char **comands)
{
	int exit_code;

	if (ft_strncmp(comands[0], "exit", ft_strlen(comands[0])) != 0)
		return;

	ft_putstr_fd("exit\n", STDERR_FILENO);

	if (!comands[1])
		exit(g_exit_status);

	if (!is_numeric(comands[1]))
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(comands[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		exit(255);
	}

	if (comands[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		g_exit_status = 1;
		return;
	}

	exit_code = ft_atoi(comands[1]) % 256;
	if (exit_code < 0)
		exit_code += 256;
	exit(exit_code);
}
