/*
** EPITECH PROJECT, 2022
** Network
** File description:
** user_cmd
*/

#include "../../include/client.h"

void user_cmd(char **tab)
{
    if (atoi(tab[3]) > 1)
        handle_error("Bad information about the user connexion (user_cmd)");
    client_print_user(tab[1], tab[2], atoi(tab[3]));
}
