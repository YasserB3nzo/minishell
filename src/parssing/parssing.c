#include "../../minishell.h"

// Helper function to free the array of strings
void free_array(char **array) {
    if (array) {
        for (int i = 0; array[i] != NULL; i++) {
            free(array[i]);
        }
        free(array);
    }
}


int parssing(char *string) {
    char **array = ft_split(string, ' ');

    if (array == NULL) {
        // perror("ft_split failed");
        return 1;
    }

    if (ft_strncmp(array[0], "echo", ft_strlen("echo")) == 0) {
        if (array[1] != NULL && ft_strncmp(array[1], "-n", 2) == 0) {
            if (ft_echo(array, 2) != 0) { // Pass the array and flag
                free_array(array);
                return 1;
            }
        } else {
            if (ft_echo(array, 1) != 0) { // Pass the array and flag
                free_array(array);
                return 1;
            }
        }
    } else if (ft_strncmp(array[0], "cd", ft_strlen("cd")) == 0) {
        if (ft_cd(array[1]) == 1) {
            free_array(array);
            return 1;
        }
    } else if (ft_strncmp(array[0], "exit", ft_strlen("exit")) == 0) {
        exits(array);
        free_array(array);
        return 1;
    } else if (ft_strncmp(array[0], "pwd", ft_strlen("pwd")) == 0) {
        pwd(array);
        free_array(array);
        return 1;
    } else {
        free_array(array);
        return 0;
    }

    free_array(array);
    return 1;
}