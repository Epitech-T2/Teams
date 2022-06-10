/*
** EPITECH PROJECT, 2022
** Network
** File description:
** select_command
*/

#include "../../include/server.h"

int select_command(client_t *client, char **tab, int id)
{
    database_t *database = get_database();
    const char *command[15] = {"help", "login", "logout", "users", "user",
        "send", "messages", "subscribe", "subscribed", "unsubscribe", "use",
        "create", "list", "info", NULL};
    void (*func[14])(database_t *database, client_t *client, char **tab, int id)
        = {&help_cmd, &login_cmd, &logout_cmd, &users_cmd, &user_cmd, &send_cmd,
        &messages_cmd, &subscribe_cmd, &subscribed_cmd, &unsubscribe_cmd,
        &use_cmd, &create_cmd, &list_cmd, &info_cmd};
    if (!client[id].login && strcmp(tab[0], "login")) {
        dprintf(client[id].sock_client, "501|Please login first");
        return (0);
    }
    for (int i = 0; command[i] != NULL; i++) {
        if (strcmp(tab[0], command[i]) == 0) {
            (*func[i])(database, client, tab, id);
            return (0);
        }
    }
    dprintf(client[id].sock_client, "500");
}
