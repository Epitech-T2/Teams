/*
** EPITECH PROJECT, 2022
** Network
** File description:
** main
*/

#include "../include/server.h"

static client_t *init_client(client_t *client, int i)
{
    client[i].sock_client = 0;
    client[i].login = false;
    client[i].username = NULL;
    client[i].uuid = NULL;
    client[i].team_uuid = NULL;
    client[i].channel_uuid = NULL;
    client[i].thread_uuid = NULL;
    client[i].use = 0;
    return (client);
}

static void new_connection(server_t *server, client_t *client)
{
    int new_sock_client = 0;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    memset(&client_addr, 0, client_len);
    new_sock_client = accept(server->sock_server,
        (struct sockaddr *)&client_addr, &client_len);
    if (new_sock_client == -1)
        handle_error("Failed accept");
    printf("New Connection\n");
    for (int i = 0; i <= MAX_CLIENTS; i++) {
        if (client[i].sock_client == 0) {
            client[i].sock_client = new_sock_client;
            break;
        }
    }
}

static int fd_isset(server_t *server, client_t *client)
{
    if (FD_ISSET(server->sock_server, &server->rset))
        new_connection(server, client);
    for (int i = 0; i <= MAX_CLIENTS; i++)
        if (FD_ISSET(client[i].sock_client, &server->rset))
            receive_from_client(client, i);
    return (0);
}

static int build_fd_set(server_t *server, client_t *client)
{
    FD_ZERO(&server->rset);
    FD_SET(server->sock_server, &server->rset);
    server->high_sock = server->sock_server;
    for (int i = 0; i <= MAX_CLIENTS; ++i) {
        if (client[i].sock_client)
            FD_SET(client[i].sock_client, &server->rset);
        if (client[i].sock_client > server->high_sock)
            server->high_sock = client[i].sock_client;
    }
    return (0);
}

int select_func(server_t *server)
{
    client_t *client = malloc(sizeof(client_t) * (MAX_CLIENTS + 1));
    int nready = 0;

    errno = 0;
    signal(SIGINT, handler_signal);
    for (int i = 0; i <= MAX_CLIENTS; i++)
        client = init_client(client, i);
    while (run) {
        build_fd_set(server, client);
        nready = select(server->high_sock + 1, &server->rset, NULL, NULL, NULL);
        if (nready == -1 && errno == EINTR)
            continue;
        else if (nready == -1)
            return (close_server(server, client, 84));
        if (fd_isset(server, client) == 84)
            return (close_server(server, client, 84));
    }
    return (close_server(server, client, 0));
}
