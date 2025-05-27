#include "../../minishell.h"

int parssing(char *string) {
    char **array = ft_split(string, ' ');

    if (array == NULL) {
        return 1;
    }

    if (ft_strncmp(array[0], "echo", ft_strlen("echo")) == 0) {
        if (ft_echo(array[1]) == 1) { 
            return 1;
        }
    } else {
        return 0;
    }

    return 0;
}