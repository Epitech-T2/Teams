/*
** EPITECH PROJECT, 2022
** Network
** File description:
** list_cmd
*/

#include "../../include/client.h"

void list_team_cmd(char **tab)
{
    int i = 1;
    int len = 0;

    for (len = 0; tab[len]; len++);
    while (i <= (len - 3)) {
        client_print_teams(tab[i], tab[i + 1], tab[i + 2]);
        i += 3;
    }
}

void list_channel_cmd(char **tab)
{
    int i = 1;
    int len = 0;

    for (len = 0; tab[len]; len++);
    while (i <= (len - 3)) {
        client_team_print_channels(tab[i], tab[i + 1], tab[i + 2]);
        i += 3;
    }
}

void list_thread_cmd(char **tab)
{
    int i = 1;
    int len = 0;

    for (len = 0; tab[len]; len++);
    while (i <= (len - 5)) {
        client_channel_print_threads(tab[i], tab[i + 1], (time_t)atoi(tab[i + 2]),
            tab[i + 3], tab[i + 4]);
        i += 5;
    }
}

void list_reply_cmd(char **tab)
{
    int i = 1;
    int len = 0;

    for (len = 0; tab[len]; len++);
    while (i <= (len - 4)) {
        client_thread_print_replies(tab[i], tab[i + 1],
            (time_t)atoi(tab[i + 2]), tab[i + 3]);
        i += 4;
    }
}
