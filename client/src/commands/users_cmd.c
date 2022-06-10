/*
** EPITECH PROJECT, 2022
** Network
** File description:
** users_cmd
*/

#include "../../include/client.h"

void users_cmd(char **tab)
{
    int i = 1;
    int len = 0;
    int status = 0;

    for (len = 0; tab[len]; len++);
    while (i <= (len - 3)) {
        status = atoi(tab[i + 2]);
        if (status > 1)
            handle_error("Bad information about the user connexion (user_cmd)");
        client_print_user(tab[i], tab[i + 1], status);
        i += 3;
    }
}
