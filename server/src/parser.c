/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** parser
*/

#include "../include/server.h"

int tab_length(char **tab)
{
    int i = 0;

    for (i = 0; tab[i]; i++);
    return i;
}

char *rm_quotes(char *v, client_t client, char *error)
{
    char *tmp = remove_quotes(v);

    if (tmp == NULL) {
        dprintf(client.sock_client, error);
        return (NULL);
    }
    return (tmp);
}

char *remove_quotes(char *value)
{
    char *value_cpy = NULL;

    if (value == NULL || strlen(value) <= 1)
        return (NULL);
    value_cpy = strdup(value);
    if (value_cpy == NULL)
        return (NULL);
    if (value[0] != '\"' || value[strlen(value) - 1] != '\"')
        return (NULL);
    value_cpy++;
    value_cpy[strlen(value_cpy) - 1] = '\0';
    return (value_cpy);
}
