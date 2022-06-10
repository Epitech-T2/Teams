/*
** EPITECH PROJECT, 2022
** Network
** File description:
** users_cmd
*/

#include "../../include/server.h"

void users_cmd(database_t *database, client_t *client, char **tab, int i)
{
    char *str = NULL;
    char *nbr = malloc(2);

    if (!client[i].login) {
        dprintf(client[i].sock_client, BAD_ARG);
        return;
    }
    str = strdup("300");
    for (user_t *temp = database->user; temp; temp = temp->next) {
        printf("Name: %s\n", temp->name);
        str = realloc(str, sizeof(str) + MAX_NAME_LENGTH + SIZE_UUID + 5);
        copy_str(str, temp->uuid, temp->name);
        strcat(str, "|");
        sprintf(nbr, "%d", temp->status);
        strcat(str, nbr);
        printf("str: %s\n", str);
    }
    dprintf(client->sock_client, "%s", str);
}
