/*
** EPITECH PROJECT, 2022
** Network
** File description:
** subscribed_cmd
*/

#include "../../include/client.h"

void subscribed_cmd(char **tab)
{
    client_print_teams(tab[1], tab[2], tab[3]);
}

void subscribed_team_cmd(char **tab)
{
    client_print_users(tab[1], tab[2], atoi(tab[3]));
}
