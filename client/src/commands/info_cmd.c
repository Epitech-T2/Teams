/*
** EPITECH PROJECT, 2022
** Network
** File description:
** info_cmd
*/

#include "../../include/client.h"

void info_team_cmd(char **tab)
{
    client_print_user(tab[1], tab[2], atoi(tab[3]));
}

void info_channel_cmd(char **tab)
{
    client_print_team(tab[1], tab[2], tab[3]);
}

void info_thread_cmd(char **tab)
{
    client_print_channel(tab[1], tab[2], tab[3]);
}

void info_reply_cmd(char **tab)
{
    client_print_thread(tab[1], tab[2], (time_t)tab[3], tab[4], tab[5]);
}
