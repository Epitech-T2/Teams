/*
** EPITECH PROJECT, 2022
** Network
** File description:
** messages_cmd
*/

#include "../../include/server.h"

void messages_cmd(database_t *database, client_t *client, char **tab, int i)
{
    if (check_user_exist(database, client, tab[1], i) == false)
        dprintf(client[i].sock_client, "501|This user don't exist");
    else
        dprintf(client[i].sock_client, "302|0|Sorry this command doesn't work");
}
