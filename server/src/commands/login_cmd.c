/*
** EPITECH PROJECT, 2022
** Network
** File description:
** login_cmd
*/

#include "../../include/server.h"

static void share_log_client(client_t *client, int id)
{
    for (int i = 0; i <= MAX_CLIENTS; i++)
        if (i != id && client[i].login == true)
            dprintf(client[i].sock_client, "313|Client %s logged in with "\
                "login %s", client[id].uuid, client[id].username);
}

static void new_user(database_t *database, client_t *client, char **tab, int i)
{
    user_t *temp = malloc(sizeof(user_t));

    client[i].uuid = strdup(generate_uuid());
    temp->name = tab[1];
    temp->uuid = client[i].uuid;
    temp->next = database->user;
    temp->status = true;
    temp->next = database->user;
    database->user = temp;
    server_event_user_created(client[i].uuid, client[i].username);
    server_event_user_logged_in(client[i].uuid);
    dprintf(client[i].sock_client, "200|%s|%s", client[i].uuid,
        client[i].username);
    share_log_client(client, i);
}

static void login_next(database_t *database, client_t *client, char **tab,
    int i)
{
    user_t *temp = database->user;

    client[i].login = true;
    client[i].username = tab[1];
    for (; temp; temp = temp->next) {
        if (strcmp(temp->name, tab[1]) == 0) {
            client[i].uuid = temp->uuid;
            server_event_user_logged_in(client[i].uuid);
            dprintf(client[i].sock_client, "200|%s|%s", client[i].uuid,
                client[i].username);
            share_log_client(client, i);
            return;
        }
    }
    new_user(database, client, tab, i);
}

void login_cmd(database_t *database, client_t *client, char **tab, int i)
{
    tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
    if (!tab[1])
        return;
    if (strcmp(tab[1], "") == 0 || strcmp(tab[1], "\"\"") == 0 ||
        strlen(tab[1]) > MAX_NAME_LENGTH) {
        dprintf(client[i].sock_client, INVALID_USERNAME);
        return;
    }
    login_next(database, client, tab, i);
}
