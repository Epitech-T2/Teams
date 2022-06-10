/*
** EPITECH PROJECT, 2022
** Network
** File description:
** subscribe_cmd
*/

#include "../../include/client.h"

void subscribe_cmd(char **tab)
{
    client_print_subscribed(tab[1], tab[2]);
}
