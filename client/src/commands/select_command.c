/*
** EPITECH PROJECT, 2022
** Network
** File description:
** select_command
*/

#include "../../include/commands.h"

int select_command(client_t *client, char **tab)
{
    if (strcmp("200", tab[0]) == 0) {
        login_cmd(client, tab);
        return (0);
    }
    if (atoi(tab[0]) >= 400 && atoi(tab[0]) <= 599) {
        errors_cmd(tab);
        return (0);
    }
    for (int i = 0; proto[i] != NULL; i++) {
        if (strcmp(tab[0], proto[i]) == 0) {
            funct[i](tab);
            return (0);
        }
    }
    return (84);
}
