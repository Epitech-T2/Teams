/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** parsing
*/

#include "../include/server.h"

static int parse_cmd(client_t *client, char *cmd, int i)
{
    char **tab = NULL;

    if (!strcmp(cmd, ""))
        handle_error("No command");
    tab = str_to_tab(cmd, " ");
    return (select_command(client, tab, i));
}

int receive_from_client(client_t *client, int i)
{
    char buffer[1024];
    int size = recv(client[i].sock_client, buffer, (1024 - 1), 0);

    if (size == -1)
        handle_error("Bad recv");
    if (size == 0) {
        close(client[i].sock_client);
        exit(0);
    }
    buffer[size] = '\0';
    return (parse_cmd(client, buffer, i));
}
