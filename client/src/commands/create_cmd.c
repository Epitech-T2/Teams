/*
** EPITECH PROJECT, 2022
** Network
** File description:
** create_cmd
*/

#include "../../include/client.h"

void create_team_cmd(char **tab)
{
    client_event_team_created(tab[1], tab[2], tab[3]);
    client_print_team_created(tab[1], tab[2], tab[3]);
}

void create_channel_cmd(char **tab)
{
    client_event_channel_created(tab[1], tab[2], tab[3]);
    client_print_channel_created(tab[1], tab[2], tab[3]);
}

void create_thread_cmd(char **tab)
{
    client_event_thread_created(tab[1], tab[2], (time_t)atoi(tab[3]), tab[4],
        tab[5]);
    client_print_thread_created(tab[1], tab[2], (time_t)atoi(tab[3]), tab[4],
        tab[5]);
}

void create_reply_cmd(char **tab)
{
    client_event_thread_reply_received(tab[1], tab[2], tab[3], tab[4]);
    client_print_reply_created(tab[2], tab[3], (time_t)atoi(tab[5]), tab[4]);
}
