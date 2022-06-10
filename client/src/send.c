/*
** EPITECH PROJECT, 2022
** Network
** File description:
** send
*/

#include "../include/client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *check_commands(char *cmd, ssize_t size_line)
{
    int i = 0;

    if (cmd == NULL || size_line == 0)
        return (NULL);
    if (cmd[size_line - 1] != '\n')
        return (NULL);
    for (; cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'); i++);
    cmd += i;
    if (cmd[0] != '/')
        return (NULL);
    cmd += 1;
    cmd[strcspn(cmd, "\n")] = '\0';
    return (cmd);
}

int send_next(client_t *client, char *commands)
{
    if (strncmp("help", commands, 4) == 0 && client->login == false) {
        printf("Please log with user /login \"username\"\n");
        return (0);
    }
    if ((strncmp("login", commands, 5) == 0) && client->login == true) {
        printf("You are already login\n");
        return (0);
    }
    return (1);
}

int send_client(client_t *client, char *cmd, ssize_t size_line)
{
    char *commands = malloc(size_line);

    commands = check_commands(cmd, size_line);
    if (commands == NULL) {
        printf("Bad arguments\n");
        return (0);
    }
    if (send_next(client, commands) == 0)
        return (0);
    if (send(client->sock_client, commands, strlen(commands), 0) == -1)
        return (error_close_client(client, 84));
}
