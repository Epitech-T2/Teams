/*
** EPITECH PROJECT, 2022
** Network
** File description:
** check
*/

#include "../include/client.h"

int check_protocol(char *cmd)
{
    if (isdigit(cmd[0]) == 0 || isdigit(cmd[1]) == 0 || isdigit(cmd[2]) == 0)
        return (84);
    return (0);
}
