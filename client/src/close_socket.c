/*
** EPITECH PROJECT, 2022
** Network
** File description:
** close_socket
*/

#include "../include/client.h"

int close_client(client_t *client, int out)
{
    close(client->sock_client);
    free(client);
    return (out);
}

int error_close_client(client_t *client, int out)
{
    return (close_client(client, out));
}
