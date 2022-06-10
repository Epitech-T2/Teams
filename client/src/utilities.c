/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** utilities
*/

#include "../include/client.h"

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
