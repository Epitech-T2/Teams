/*
** EPITECH PROJECT, 2022
** Network
** File description:
** subscribed_cmd
*/

#include "../../include/server.h"

void subscribed_to_team(team_t *team, client_t *client)
{
    char *str = NULL;
    char *nbr = malloc(2);

    str = strdup("304");
    for (user_t *temp = team->authorized_users; temp; temp = temp->next) {
        str = realloc(str, sizeof(str) + MAX_NAME_LENGTH + SIZE_UUID + 5);
        copy_str(str, temp->uuid, temp->name);
        strcat(str, "|");
        sprintf(nbr, "%d", temp->status);
        strcat(str, nbr);
    }
    dprintf(client->sock_client, "%s", str);
}

bool is_subscribed(team_t *team, char *uuid)
{
    for (user_t *temp = team->authorized_users; temp; temp = temp->next)
        if (temp->uuid == uuid)
            return(true);
    return(false);
}

void teams_subscribed(database_t *database, client_t *client)
{
    char *str = NULL;

    str = strdup("303");
    for (team_t *team = database->teams; team; team = team->next) {
        if (is_subscribed(team, client->uuid) == true) {
            str = realloc(str, sizeof(str) + SIZE_UUID + MAX_NAME_LENGTH +
                MAX_DESCRIPTION_LENGTH + 5);
            str = copy_str(str, team->uuid, team->name);
            strcat(str, "|");
            strcat(str, team->description);
        }
    }
    dprintf(client->sock_client, "%s", str);
}

void subscribed_cmd(database_t *database, client_t *client, char **tab, int i)
{
    if (!tab[1])
        return (teams_subscribed(database, &client[i]));
    tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
    for (team_t *team = database->teams; team; team = team->next) {
        if (strcmp(tab[1], team->uuid) == 0)
            return (subscribed_to_team(team, &client[i]));
    }
    dprintf(client[i].sock_client, "501|%s", BAD_ARG);
    return;
}
