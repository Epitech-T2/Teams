/*
** EPITECH PROJECT, 2022
** Network
** File description:
** list_cmd
*/

#include "../../include/server.h"

static void list_replies(channel_t *channel, client_t *client)
{
    thread_t *thread = channel->threads;
    char *str = strdup("308");

    for (; !strcmp(thread->uuid, client->thread_uuid) && thread;
        thread = thread->next);
    if (!thread)
        dprintf(client->sock_client, BAD_ARG);
    for (comment_t *t = thread->comments; t; t = t->next) {
        str = realloc(str, sizeof(str) + SIZE_UUID * 2 + sizeof(time_t) +
            MAX_BODY_LENGTH + 6);
        str = copy_str(str, t->thread_uuid, t->user_uuid);
        str = copy_str(str, t->reply_timestamp, t->text);
    }
    dprintf(client->sock_client, "%s", str);
}

static void list_threads(team_t *team, client_t *client)
{
    channel_t *channel = team->channels;
    char *str = strdup("307");

    for (; !strcmp(channel->uuid, client->channel_uuid) && channel;
    channel = channel->next);
    if (!channel)
        dprintf(client->sock_client, BAD_ARG);
    if (client->thread_uuid)
        return(list_threads(channel, client));
    for (thread_t *t = channel->threads; t; t = t->next) {
        str = realloc(str, sizeof(str) + SIZE_UUID * 2 + sizeof(time_t) +
            MAX_NAME_LENGTH + MAX_BODY_LENGTH);
        str = copy_str(str, t->uuid, t->creator_uuid);
        str = copy_str(str, t->thread_timestamp, t->title);
        strcat(str, "|");
        strcat(str, t->body);
    }
    dprintf(client->sock_client, "%s", str);
}

static void list_channels(database_t *database, client_t *client)
{
    team_t *team = database->teams;
    char *str = strdup("306");

    for (; !strcmp(team->uuid, client->team_uuid) && team; team = team->next);
    if (!team)
        dprintf(client->sock_client, BAD_ARG);
    if (client->channel_uuid)
        return(list_threads(team, client));
    for (channel_t *t = team->channels; t; t = t->next) {
        str = realloc(str, sizeof(str) + SIZE_UUID + MAX_NAME_LENGTH +
            MAX_DESCRIPTION_LENGTH + 4);
        str = copy_str(str, t->uuid, t->name);
        strcat(str, "|");
        strcat(str, t->description);
    }
    dprintf(client->sock_client, "%s", str);
}

static void list_teams(database_t *database, client_t *client)
{
    char *str = strdup("305");

    if (client->team_uuid)
        return(list_channels(database->teams, client));
    for (team_t *t = database->teams; t; t = t->next) {
        str = realloc(str, sizeof(str) + SIZE_UUID + MAX_NAME_LENGTH +
            MAX_DESCRIPTION_LENGTH + 5);
        str = copy_str(str, t->uuid, t->name);
        strcat(str, "|");
        strcat(str, t->description);
    }
    dprintf(client->sock_client, "%s", str);
}

void list_cmd(database_t *database, client_t *client, char **tab, int i)
{
    if (!client[i].team_uuid && client[i].use == 1) {
        list_teams(database, &(client[i]));
        return (reset_uuids(client));
    }
    for (team_t *t = database->teams; t; t = t->next)
        if (strcmp(t->uuid, client[i].team_uuid)) {
            list_channels(t, &(client[i]));
            return (reset_uuids(client));
        }
    dprintf(client[i].sock_client, BAD_ARG);
}
