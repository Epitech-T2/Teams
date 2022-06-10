/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** errors_cmd
*/

#include "../../include/client.h"

static void errors_global(char **tab)
{
    if (strcmp(tab[0], "500") == 0)
        printf("Command not found\n");
    if (strcmp(tab[0], "501") == 0)
        printf("Error: %s\n", tab[1]);
}

static void errors_cmd_next(char **tab)
{
    if (strcmp(tab[0], "403") == 0)
        client_error_unknown_team(tab[1]);
    if (strcmp(tab[0], "404") == 0)
        client_error_unknown_channel(tab[1]);
    if (strcmp(tab[0], "405") == 0)
        client_error_unknown_thread(tab[1]);
    errors_global(tab);
}

void errors_cmd(char **tab)
{
    if (strcmp(tab[0], "400") == 0)
        client_error_already_exist();
    if (strcmp(tab[0], "401") == 0)
        client_error_unauthorized();
    if (strcmp(tab[0], "402") == 0)
        client_error_unknown_user(tab[1]);
    errors_cmd_next(tab);
}
