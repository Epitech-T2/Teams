/*
** EPITECH PROJECT, 2022
** Network
** File description:
** recv
*/

#include "../include/client.h"

static int parse_cmd(client_t *client, char *cmd)
{
    char **tab = NULL;

    if (!strcmp(cmd, ""))
        handle_error("No command");
    tab = str_to_tab(cmd, "|\n");
    if (check_protocol(tab[0]) == 84)
        return (84);
    return (select_command(client, tab));
}

int recv_message(client_t *client)
{
    char buffer[1024];
    int size = 0;

    size = recv(client->sock_client, buffer, (1024 - 1), 0);
    if (size == -1)
        handle_error("Bad recv");
    if (size == 0) {
        close(client->sock_client);
        exit(0);
    }
    buffer[size] = '\0';
    return (parse_cmd(client, buffer));
}
