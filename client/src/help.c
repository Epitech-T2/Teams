/*
** EPITECH PROJECT, 2022
** Network
** File description:
** help
*/

#include "../include/client.h"

int print_help_client(void)
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip   is the server ip address on which the server socket \
        \rlistens\n");
    printf("\tport is the port number on which the server socket listens\n");
    return (0);
}
