/*
** EPITECH PROJECT, 2022
** Network
** File description:
** user_cmd
*/

#include "../../include/server.h"

void user_cmd(database_t *database, client_t *client, char **tab, int i)
{
    user_t *temp = database->user;

    tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
    if (!tab[1])
        return;
    for (; temp && !strcmp(tab[1], temp->uuid); temp = temp->next);
    if (temp)
        dprintf(client->sock_client, "301|%s|%s|%d", temp->uuid, temp->name,
            temp->status);
}
