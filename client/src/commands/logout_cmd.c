/*
** EPITECH PROJECT, 2022
** Network
** File description:
** logout_cmd
*/

#include "../../include/client.h"

client_t *get_client(void)
{
    static client_t *client = NULL;

    if (!client) client = malloc(sizeof(client_t));

    return (client);
}

void logout_cmd(char **tab)
{
    client_event_logged_out(tab[1], tab[2]);
    close(get_client()->sock_client);
    free(get_client());
    exit(0);
    get_client()->login == false;
}
