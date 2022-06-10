/*
** EPITECH PROJECT, 2022
** Network
** File description:
** info_cmd
*/

#include "../../include/server.h"

static void info_team(client_t *client, int id)
{
    dprintf(client->sock_client, "309|%s|%s|%i", client->uuid,
        client->username, client->login);
}

static void info_reply(channel_t * channel, client_t *client)
{
    thread_t *temp = channel->threads;

    for (; temp->next && !strcmp(temp->uuid, client->team_uuid);
        temp = temp->next);
    if (!temp) {
        dprintf(client->sock_client, BAD_ARG);
        return;
    }
    dprintf(client->sock_client, "312|%s|%s|%s|%s|%s", temp->uuid,
        temp->creator_uuid, temp->thread_timestamp, temp->title, temp->body);
}

static void info_thread(team_t *team, client_t *client)
{
    channel_t *temp = team->channels;

    for (; temp->next && !strcmp(temp->uuid, client->team_uuid);
        temp = temp->next);
    if (!temp) {
        dprintf(client->sock_client, BAD_ARG);
        return;
    }
    if (client->channel_uuid)
        return (info_reply(temp, client));
    dprintf(client->sock_client, "311|%s|%s|%s", temp->uuid, temp->name,
        temp->description);
}

static void info_channel(database_t *database, client_t *client)
{
    team_t *temp = database->teams;

    for (; temp->next && !strcmp(temp->uuid, client->team_uuid);
        temp = temp->next);
    if (temp == NULL) {
        dprintf(client->sock_client, BAD_ARG);
        return;
    }
    if (client->channel_uuid)
        return (info_thread(temp, client));
    dprintf(client->sock_client, "310|%s|%s|%s", temp->uuid, temp->name,
        temp->description);
}

void info_cmd(database_t *database, client_t *client, char **tab, int i)
{
    if (!client[i].team_uuid && client[i].use == 1) {
        info_team(client, i);
        return (reset_uuids(client));
    }
    info_channel(database, &(client[i]));
    reset_uuids(client);
}
