/*
** EPITECH PROJECT, 2022
** Network
** File description:
** unsubscribe_cmd
*/

#include "../../include/server.h"

void remove_user(team_t *team, client_t *client, int i)
{
    user_t *temp = team->authorized_users;

    if (temp == NULL){
        dprintf(client[i].sock_client, NOT_SUB);
        return;
    }
    for (; temp; temp = temp->next) {
        if (strcmp(temp->uuid, client[i].uuid) == 0) {
            temp = temp->next;
            server_event_user_unsubscribed(team->uuid, client[i].uuid);
            dprintf(client[i].sock_client, "204|%s|%s", client[i].uuid,
                team->uuid);
            return;
        }
    }
    dprintf(client[i].sock_client, NOT_SUB);
}

void unsubscribe_cmd(database_t *database, client_t *client, char **tab, int i)
{
    tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
    if (!tab[1])
        return;
    for (team_t *temp = database->teams; temp; temp = temp->next)
        if (strcmp(temp->uuid, tab[1]) == 0)
            return (remove_user(temp, client, i));
    dprintf(client[i].sock_client, "403|%s", tab[1]);
}
