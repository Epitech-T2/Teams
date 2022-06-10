/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** get_database
*/

#include "../../include/server.h"

database_t *get_database(void)
{
    static database_t data = {0};

    return (&data);
}

char *generate_uuid(void)
{
    uuid_t uuid;
    char *out = malloc(37);

    if (out == NULL)
        return NULL;
    uuid_generate_random(uuid);
    uuid_unparse_upper(uuid, out);
    return (out);
}
