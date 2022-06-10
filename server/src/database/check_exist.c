/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** check_teams
*/

#include "../../include/server.h"

bool check_user_exist(database_t *db, client_t *client, char *uuid_receiver,
    int id)
{
    user_t *user = db->user;

    if (user == NULL)
        return (false);
    for (; user; user = user->next) {
        if (strcmp(user->uuid, uuid_receiver) == 0)
            return (true);
        else if (strcmp(user->uuid, uuid_receiver))
            return (false);
    }
}

bool check_user_int_team(database_t *db, client_t *client, char *uuid_team,
    int id)
{
    team_t *teams = db->teams;
    user_t *user;

    for (; teams; teams = teams->next)
        if (strcmp(teams->uuid, uuid_team) == 0)
            user = teams->authorized_users;
    if (user == NULL)
        return (false);
    for (; user; user = user->next) {
        if (strcmp(user->uuid, client[id].uuid) == 0)
            return (true);
        else if (strcmp(user->uuid, client[id].uuid))
            return (false);
    }
}

bool check_team_exist(database_t *db, client_t *client, char *uuid_team, int id)
{
    team_t *teams = db->teams;

    if (teams == NULL)
        return (false);
    for (; teams; teams = teams->next)
        if (strcmp(teams->uuid, uuid_team) == 0)
            return (true);
    return (false);
}

bool check_channel_exist(database_t *db, client_t *client, char **tab, int id)
{
    bool team_exist = false;
    channel_t *channel = db->teams->channels;

    team_exist = check_user_int_team(db, client, tab[1], id);
    if (team_exist == false)
        return (false);
    for (; channel; channel = channel->next)
        if (strcmp(channel->uuid, tab[2]) == 0)
            return (true);
    return (false);
}

bool check_thread_exist(database_t *db, client_t *client, char **tab, int id)
{
    bool channel_exist = false;
    thread_t *thread = db->teams->channels->threads;

    channel_exist = check_channel_exist(db, client, tab, id);
    if (channel_exist == false)
        return (false);
    for (; thread; thread = thread->next)
        if (strcmp(thread->uuid, tab[3]) == 0)
            return (true);
    return (false);
}
