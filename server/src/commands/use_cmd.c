/*
** EPITECH PROJECT, 2022
** Network
** File description:
** use_cmd
*/

#include "../../include/server.h"

void use_thread(database_t *database, client_t *client, char **tab, int id)
{
    if (check_thread_exist(database, client, tab, id) ==
        true) {
        client[id].use = 4;
        client[id].team_uuid = strdup(tab[1]);
        client[id].channel_uuid = strdup(tab[2]);
        client[id].thread_uuid = strdup(tab[3]);
    } else
        dprintf(client[id].sock_client, "401");
}

void use_channel(database_t *database, client_t *client, char **tab, int id)
{
    if (check_channel_exist(database, client, tab, id) == true) {
        client[id].use = 3;
        client[id].team_uuid = strdup(tab[1]);
        client[id].channel_uuid = strdup(tab[2]);
    } else
        dprintf(client[id].sock_client, "401");
}

void use_team(database_t *database, client_t *client, char **tab, int id)
{
    if (check_team_exist(database, client, tab[1], id) == true) {
        if (check_user_int_team(database, client, tab[1], id) == true) {
            client[id].use = 2;
            client[id].team_uuid = strdup(tab[1]);
        } else
            dprintf(client[id].sock_client, "401");
    } else
        dprintf(client[id].sock_client, "401");
}

void use_cmd(database_t *database, client_t *client, char **tab, int i)
{
    int size = tab_length(tab);

    client[i].use = (tab[1] == NULL) ? 1 : 0;
    if (size == 4 && tab[1] && tab[2] && tab[3]) {
        tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
        tab[2] = rm_quotes(tab[2], client[i], BAD_ARG);
        tab[3] = rm_quotes(tab[3], client[i], BAD_ARG);
        if (!tab[1] || !tab[2] || !tab[3])
            return;
        use_thread(database, client, tab, i);
    }
    if (size == 3 && tab[1] && tab[2]) {
        tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
        tab[2] = rm_quotes(tab[2], client[i], BAD_ARG);
        if (!tab[1] || !tab[2])
            return;
        use_channel(database, client, tab, i);
    }
    if (size == 2 && tab[1]) {
        tab[1] = rm_quotes(tab[1], client[i], BAD_ARG);
        if (!tab[1])
            return;
        use_team(database, client, tab, i);
    }
    return;
}
