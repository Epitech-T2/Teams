/*
** EPITECH PROJECT, 2022
** Network
** File description:
** unsubscribe_cmd
*/

#include "../../include/client.h"

void unsubscribe_cmd(char **tab)
{
    client_print_unsubscribed(tab[1], tab[2]);
}
