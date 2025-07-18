#include "../../minishell.h"


int ft_echo(char **string, int flag) {
    int i = 1;
    int nl = 1;

    if (!string) {
        return 1;
    }

    if (flag == 2)
    {
        i++;
        nl = 0;
    }
    while (string[i] != NULL)
    {
        write(1, string[i], strlen(string[i]));
        i++;
        if (string[i] != NULL) {
            write(1, " ", 1);
        }
    }
    if (nl) {
        write(1, "\n", 1);
    }

    return 1;
}

int ft_cd(char *path)
{
    char *target_path;
    
    // If no path is provided, go to HOME directory
    if (!path)
    {
        target_path = getenv("HOME");
        if (!target_path)
        {
            write(2, "cd: HOME not set\n", 17);
            return 1;
        }
    }
    else
    {
        target_path = path;
    }
    
    // Attempt to change directory
    if (chdir(target_path) == -1)
    {
        write(2, "cd: No such file or directory\n", 30);
        return 1;
    }
    
    return 0;
}

int ft_ls(char **args)
{
    pid_t pid;
    char *ls_path = "/bin/ls"; // Path to the ls executable

    // Fork the process
    pid = fork();
    if (pid < 0)
    {
        write(2, "Error: Fork failed\n", 19);
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        if (execv(ls_path, args) == -1)
        {
            write(2, "Error: execv failed\n", 21);
            exit(1);
        }
    }
    else
    {
        // Parent process waits for the child to complete
        waitpid(pid, NULL, 0);
    }

    return 0;
}

// int chdir(const char *path);
// char *getenv(const char *name);

// $ echo "hello" > a
// $ cat a
// hello
// $ echo -n "hello" > a 
// $ cat a
// hello$            # the new line is not present, so the prompt follows last line
