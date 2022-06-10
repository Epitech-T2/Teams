/*
** EPITECH PROJECT, 2022
** Network
** File description:
** help_cmd
*/

#include <errno.h>
#include "../../include/server.h"

void help_cmd(database_t *database, client_t *client, char **tab, int i)
{
    dprintf(client[i].sock_client, "100");
}
