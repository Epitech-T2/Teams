/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** utilities
*/

#include "../include/server.h"

char *copy_str(char *str_cp, char *src1, char *src2)
{
    strcat(str_cp, "|");
    strcat(str_cp, src1);
    strcat(str_cp, "|");
    strcat(str_cp, src2);
    return (str_cp);
}

char **str_to_tab(char *str, char *tok)
{
    int i = 0;
    char **tab = malloc(sizeof(char *));
    char *token = strtok(str, tok);

    if (!str || !tab || !token)
        return (NULL);
    while (1) {
        tab[i] = strdup(token);
        i++;
        tab = realloc(tab, (sizeof(char *) * (i + 1)));
        token = strtok(NULL, tok);
        if (token == NULL) {
            tab[i] = token;
            break;
        }
    }
    free(token);
    return (tab);
}

void reset_uuids(client_t *client)
{
    client->team_uuid = NULL;
    client->channel_uuid = NULL;
    client->thread_uuid = NULL;
}
