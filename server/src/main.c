/*
** EPITECH PROJECT, 2022
** Network
** File description:
** main
*/

#include "../include/server.h"

static server_t *init_next(server_t *server)
{
    memset(&server->address, 0, server->length);
    server->address.sin_family = AF_INET;
    server->address.sin_port = htons(server->port);
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->high_sock = 0;
    return (server);
}

static server_t *init_struct_server(char *port)
{
    server_t *server = malloc(sizeof(server_t));
    struct protoent *protocol;
    int proto = 0;
    int optval = 1;

    if (server == NULL)
        return (NULL);
    protocol = getprotobyname("TCP");
    if (protocol == NULL)
        return (NULL);
    proto = protocol->p_proto;
    server->port = atoi(port);
    server->length = sizeof(server->address);
    server->sock_server = socket(AF_INET, SOCK_STREAM, proto);
    if (server->sock_server == -1)
        handle_error("Bad socket\n");
    if (setsockopt(server->sock_server, SOL_SOCKET, SO_REUSEADDR, &optval,
        sizeof(optval)) != 0)
        handle_error("Bad setsockopt\n");
    return (init_next(server));
}

static int set_server(server_t *server)
{
    if (bind(server->sock_server, (struct sockaddr *)&server->address,
        server->length) == -1) {
        close(server->sock_server);
        handle_error("Bind failed");
    }
    if (listen(server->sock_server, 1024) == -1) {
        close(server->sock_server);
        handle_error("Listen failed");
    }
    return (0);
}

static int loop(char **av)
{
    server_t *server = init_struct_server(av[1]);

    if (server == NULL || set_server(server) == 84)
        return (84);
    return (select_func(server));
}

int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "-help") == 0)) {
        print_help();
        return (0);
    }
    if (ac != 2)
        return (84);
    return (loop(av));
}
