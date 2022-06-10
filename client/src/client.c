/*
** EPITECH PROJECT, 2022
** Network
** File description:
** client
*/

#include "../include/client.h"

static int fd_isset(client_t *client)
{
    char *line = NULL;
    size_t size = 0;
    ssize_t size_line = 0;

    if (FD_ISSET(STDIN_FILENO, &client->rset)) {
        if ((size_line = getline(&line, &size, stdin)) == -1) {
            free(line);
            return (close_client(client, 0));
        }
        return (send_client(client, line, size_line));
    } else if (FD_ISSET(client->sock_client, &client->rset))
        return (recv_message(client));
    return (0);
}

static void build_fd_set(client_t *client)
{
    FD_ZERO(&client->rset);
    FD_SET(STDIN_FILENO, &client->rset);
    FD_SET(client->sock_client, &client->rset);
}

int select_func_client(client_t *client)
{
    int maxfd = 0;
    int nready = 0;

    signal(SIGINT, handler_signal_client);
    while (run) {
        maxfd = client->sock_client;
        build_fd_set(client);
        nready = select(maxfd + 1, &client->rset, NULL, NULL, NULL);
        if (nready == -1)
            return (error_close_client(client, 84));
        if (fd_isset(client) == 84)
            return (84);
    }
    return (close_client(client, 0));
}
