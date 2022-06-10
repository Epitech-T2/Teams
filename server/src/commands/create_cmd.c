/*
** EPITECH PROJECT, 2022
** Network
** File description:
** create_cmd
*/

#include "../../include/server.h"

static void create_comment(char **tab, thread_t *thread, team_t *team,
client_t *client)
{
    comment_t *new = malloc(sizeof(comment_t));

    new->text = tab[1];
    new->next = thread->comments;
    new->thread_uuid = thread->uuid;
    new->user_uuid = client->uuid;
    new->reply_timestamp = time(NULL);
    thread->comments = new;
    server_event_reply_created(thread->uuid, client->uuid, new->text);
    dprintf(client->sock_client, "208|%s|%s|%s|%s", team->uuid, thread->uuid,
    client->uuid, tab[1], new->reply_timestamp);
}

static void create_thread(char **tab, channel_t *channel, team_t *team,
    client_t *client)
{
    thread_t *new = malloc(sizeof(thread_t));
    uuid_t new_uuid;

    if (!client->thread_uuid) {
        new->comments = NULL;
        new->body = tab[2];
        new->title = tab[1];
        new->creator_uuid = client->uuid;
        new->thread_timestamp = time(NULL);
        new->uuid = malloc(37);
        uuid_generate_random(new_uuid);
        uuid_unparse_upper(new_uuid, new->uuid);
        new->next = channel->threads;
        channel->threads = new;
        server_event_thread_created(channel->uuid, new->uuid, client->uuid,
            new->title, new->body);
        dprintf(client->sock_client, "207|%s|%s|%s|%s|%s", new->uuid,
        client->uuid, new->thread_timestamp, tab[1], tab[2]);
        return;
    }
    for (new = channel->threads; new; new = new->next)
        if (strcmp(new->uuid, client->thread_uuid) == 0)
            return(create_comment(tab, new, team, client));
}

static void create_channel(char **tab, team_t *team, client_t *client)
{
    channel_t *new = malloc(sizeof(channel_t));
    uuid_t new_uuid;

    if (!client->channel_uuid) {
        new->description = tab[2];
        new->name = tab[1];
        new->threads = NULL;
        new->uuid = malloc(37);
        uuid_generate_random(new_uuid);
        uuid_unparse_upper(new_uuid, new->uuid);
        new->next = team->channels;
        team->channels = new;
        server_event_channel_created(team->uuid, new->uuid, new->name);
        dprintf(client->sock_client, "206|%s|%s|%s", new->uuid, tab[1], tab[2]);
        return;
    }
    for (new = team->channels; new; new = new->next)
        if (strcmp(new->uuid, client->channel_uuid) == 0)
            return (create_thread(tab, new, team, client));
}

static void create_team(char **tab, database_t *database, client_t *client)
{
    team_t *new = malloc(sizeof(team_t));
    user_t *user = malloc(sizeof(user_t));
    uuid_t new_uuid;

    new->uuid = malloc(37);
    user->name = client->username;
    user->uuid = client->uuid;
    user->status = true;
    user->next = NULL;
    new->description = tab[2];
    new->name = tab[1];
    new->channels = NULL;
    new->authorized_users = user;
    uuid_generate_random(new_uuid);
    uuid_unparse_upper(new_uuid, new->uuid);
    new->next = database->teams;
    database->teams = new;
    server_event_team_created(new->uuid, new->name, client->uuid);
    dprintf(client->sock_client, "205|%s|%s|%s", new->uuid, tab[1], tab[2]);
}

void create_cmd(database_t *database, client_t *client, char **tab, int i)
{
    for (int j = 1; tab[j] ;j++ ) {
        tab[j] = rm_quotes(tab[j], client[i], BAD_ARG);
        if (!tab[j]) return;
    }
    if (!tab[1] || (!client[i].thread_uuid && !tab[2])) {
        dprintf(client[i].sock_client, BAD_ARG);
        reset_uuids(client);
        return;
    }
    if (!client[i].team_uuid && client[i].use == 1) {
        create_team(tab, database, &(client[i]));
        return (reset_uuids(client));
    }
    for (team_t *temp = database->teams; temp; temp = temp->next) {
        if (strcmp(temp->uuid, client[i].team_uuid) == 0) {
            create_channel(tab, temp, &(client[i]));
            return (reset_uuids(client));
        }
    }
    dprintf(client[i].sock_client, BAD_ARG);
}
