/*
** EPITECH PROJECT, 2022
** Network
** File description:
** logout_cmd
*/

#include "../../include/server.h"

static void share_close_client(client_t *client, int id)
{
    for (int i = 0; i <= MAX_CLIENTS; i++)
        if (i != id && client[i].login == true)
            dprintf(client[i].sock_client, "313|Client %s logged out with "\
                "login %s", client[id].uuid, client[id].username);
}

void logout_cmd(database_t *database, client_t *client, char **tab, int i)
{
    server_event_user_logged_out(client[i].uuid);
    dprintf(client[i].sock_client, "201|%s|%s", client[i].uuid,
        client[i].username);
    close(client[i].sock_client);
    share_close_client(client, i);
    client[i].sock_client = 0;
    client[i].login = false;
    client[i].uuid = NULL;
    client[i].username = NULL;
}
