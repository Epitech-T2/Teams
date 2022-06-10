/*
** EPITECH PROJECT, 2022
** Network
** File description:
** login_cmd
*/

#include "../../include/client.h"

void login_cmd(client_t *client, char **tab)
{
    client->uuid = strdup(tab[1]);
    client->username = strdup(tab[2]);
    client_event_logged_in(client->uuid, client->username);
    client->login = true;
}
