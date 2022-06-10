/*
** EPITECH PROJECT, 2022
** Network
** File description:
** help_cmd
*/

#include "../../include/client.h"

void help_cmd(char **tab)
{
    char *line = NULL;
    size_t size = 500;
    FILE *file = fopen("./doc/help.txt", "r");

    if (file == NULL)
        return;
    while (getline(&line, &size, file) != -1)
        printf("%s", line);
    free(line);
    fclose(file);
}
