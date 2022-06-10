/*
** EPITECH PROJECT, 2022
** Network
** File description:
** main
*/

#include "../include/client.h"

static client_t *init_next(client_t *client, char* ip)
{
    memset(&client->address_client, 0, client->lenght);
    client->address_client.sin_family = AF_INET;
    client->address_client.sin_port = htons(client->port);
    client->address_client.sin_addr.s_addr = inet_addr(ip);
    client->login = false;
    client->username = NULL;
    client->uuid = NULL;
    return (client);
}

static client_t *init_struct_client(char *ip, char *port)
{
    client_t *client = get_client();
    struct protoent *protocol;
    int proto = 0;
    int optval = 1;

    if (client == NULL)
        return (NULL);
    protocol = getprotobyname("TCP");
    if (protocol == NULL)
        return (NULL);
    proto = protocol->p_proto;
    client->port = atoi(port);
    client->lenght = sizeof(client->address_client);
    client->sock_client = socket(AF_INET, SOCK_STREAM, proto);
    if (client->sock_client == -1)
        handle_error("Bad socket\n");
    if (setsockopt(client->sock_client, SOL_SOCKET, SO_REUSEADDR, &optval,
        sizeof(optval)) != 0)
        handle_error("Bad setsockopt\n");
    return (init_next(client, ip));
}

static int set_client(client_t *client)
{
    if (connect(client->sock_client, (struct sockaddr *)&client->address_client,
        client->lenght) == -1) {
        close(client->sock_client);
        handle_error("Bad connect\n");
    }
    return (0);
}

static int loop(char **av)
{
    client_t *client = init_struct_client(av[1], av[2]);

    if (client == NULL)
        handle_error("Bad initialization\n");
    if (set_client(client) == 84)
        return (close_client(client, 84));
    return (select_func_client(client));
}

int main(int ac, char **av)
{
    if (ac == 2 && (strcmp(av[1], "-help") == 0)) {
        print_help_client();
        return (0);
    }
    if (ac != 3)
        handle_error("Bad number of arguments\n");
    return (loop(av));
}
