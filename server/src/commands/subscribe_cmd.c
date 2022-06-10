/*
** EPITECH PROJECT, 2022
** Network
** File description:
** subscribe_cmd
*/

#include "../../include/server.h"

void init_user(team_t *team, client_t *client, int i)
{
    user_t *new = malloc(sizeof(user_t));

    new->uuid = client[i].uuid;
    new->name = client[i].username;
    new->next = team->authorized_users;
    team->authorized_users = new;
    server_event_user_subscribed(team->uuid, client[i].uuid);
    dprintf(client[i].sock_client, "203|%s|%s", client[i].uuid, team->uuid);
}

void add_user(team_t *team, client_t *client, char **tab, int i)
{
    for (user_t *temp = team->authorized_users; temp; temp = temp->next) {
        if (strcmp(temp->uuid, client->uuid)) {
            dprintf(client[i].sock_client, "501|You are already subscribed");
            return;
        }
    }
    init_user(team, client, i);
}

void subscribe_cmd(database_t *database, client_t *client, char **tab, int i)
{
    tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
    if (!tab[1])
        return;
    for (team_t *temp = database->teams; temp; temp = temp->next)
        if (strcmp(temp->uuid, tab[1]) == 0)
            return (add_user(temp, client, tab, i));
    dprintf(client[i].sock_client, "403|%s", tab[1]);
}
