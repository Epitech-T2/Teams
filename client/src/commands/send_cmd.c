/*
** EPITECH PROJECT, 2022
** Network
** File description:
** send_cmd
*/

#include "../../include/client.h"

void send_cmd(char **tab)
{
    client_event_private_message_received(tab[1], tab[2]);
}
