/*
** EPITECH PROJECT, 2022
** Network
** File description:
** send_cmd
*/

#include "../../include/server.h"

static void send_two(client_t *client, char **tab, int i)
{
    server_event_private_message_sended(client[i].uuid, tab[1], tab[2]);
    for (int j = 0; j <= MAX_CLIENTS; i++) {
        if (j != i && client[j].login == true &&
            strcmp(tab[1], client[j].uuid)) {
            dprintf(client[j].sock_client, "202|%s|%s",
                client[i].uuid, tab[2]);
        }
    }
}

void send_cmd(database_t *database, client_t *client, char **tab, int i)
{
    dprintf(client[i].sock_client, "202|0|Sorry this command doesn't work");
    return (0);
    tab[1] = tab[1] ? rm_quotes(tab[1], client[i], BAD_ARG) : NULL;
    tab[2] = tab[2] ? rm_quotes(tab[2], client[i], BAD_ARG) : NULL;
    if (check_user_exist(database, client, tab[1], i) == false)
        dprintf(client[i].sock_client, "501|This user don't exist");
    else if (strlen(tab[2]) > MAX_BODY_LENGTH)
        dprintf(client[i].sock_client, "501|The length of the message is too " \
        "long");
    else
        send_two(client, tab, i);
}
