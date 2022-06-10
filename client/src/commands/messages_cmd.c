/*
** EPITECH PROJECT, 2022
** Network
** File description:
** messages_cmd
*/

#include "../../include/client.h"

void messages_cmd(char **tab)
{
    client_private_message_print_messages(tab[1], (time_t)atoi(tab[2]), tab[3]);
}
