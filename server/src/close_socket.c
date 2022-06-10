/*
** EPITECH PROJECT, 2022
** Network
** File description:
** close_socket
*/

#include "../include/server.h"

int close_server(server_t *server, client_t *client, int out)
{
    for (int i = 0; i <= MAX_CLIENTS ; i++) {
        if (client[i].sock_client != -1) {
            printf("Close socket: %d, username: %s\n", client[i].sock_client,
                client[i].username);
            close(client[i].sock_client);
        }
    }
    close(server->sock_server);
    free(client);
    free(server);
    return (out);
}

void close_client_connection(client_t *client)
{
    close(client->sock_client);
    client->sock_client = 0;
}
