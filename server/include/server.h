/*
** EPITECH PROJECT, 2022
** Network
** File description:
** server
*/

#ifndef SERVER_H_
    #define SERVER_H_

    #define handle_error(msg) ({ perror(msg); exit(84); })
    #define MAX_CLIENTS 10

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512
    #define SIZE_UUID 37

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <uuid/uuid.h>
    #include <errno.h>
    #include <signal.h>
    #include <unistd.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <netdb.h>
    #include <ctype.h>

    #include "../../libs/myteams/logging_server.h"
    #include "struct.h"
    #include "errors.h"

    static volatile sig_atomic_t run = 1;

    static inline void handler_signal(__attribute__((unused)) int signal)
    {
        run = 0;
    }

    typedef struct server {
        struct sockaddr_in address;
        socklen_t length;
        fd_set rset;
        int sock_server;
        int high_sock;
        int port;
    } server_t;

    typedef struct client {
        int sock_client;
        char *username;
        bool login;
        int use;
        char *uuid;
        char *team_uuid;
        char *channel_uuid;
        char *thread_uuid;
    } client_t;

    typedef struct database {
        client_t *client;
        user_t *user;
        team_t *teams;
    } database_t;

    // Database ===========================

    database_t *get_database(void);
    char *generate_uuid(void);
    bool check_user_int_team(database_t *db, client_t *client,
        char *uuid_team, int id);
    bool check_team_exist(database_t *db, client_t *client, char *uuid_team,
        int id);
    bool check_thread_exist(database_t *db, client_t *client, char **tab,
        int id);
    bool check_user_exist(database_t *db, client_t *client, char *uuid_receiver,
        int id);

    // Utilities ==========================

    int print_help(void);
    int receive_from_client(client_t *client, int i);
    char **str_to_tab(char *str, char *tok);
    int select_func(server_t *server);
    int close_server(server_t *server, client_t *client, int out);
    bool check_channel_exist(database_t *db, client_t *client, char **tab,
        int id);

    // Commands ===========================

    int tab_length(char **tab);
    char *rm_quotes(char *v, client_t client, char *error);
    char *remove_quotes(char *value);

    // Commands ===========================

    int select_command(client_t *client, char **tab, int i);
    void help_cmd(database_t *database, client_t *client, char **tab, int i);
    void login_cmd(database_t *database, client_t *client, char **tab, int i);
    void logout_cmd(database_t *database, client_t *client, char **tab, int i);
    void users_cmd(database_t *database, client_t *client, char **tab, int i);
    void user_cmd(database_t *database, client_t *client, char **tab, int i);
    void send_cmd(database_t *database, client_t *client, char **tab, int i);
    void messages_cmd(database_t *database, client_t *client, char **tab,
        int i);
    void subscribed_cmd(database_t *database, client_t *client, char **tab,
        int i);
    void subscribe_cmd(database_t *database, client_t *client, char **tab,
        int i);
    void unsubscribe_cmd(database_t *database, client_t *client, char **tab,
        int i);
    void use_cmd(database_t *database, client_t *client, char **tab, int i);
    void create_cmd(database_t *database, client_t *client, char **tab, int i);
    void list_cmd(database_t *database, client_t *client, char **tab, int i);
    void info_cmd(database_t *database, client_t *client, char **tab, int i);


#endif /* !SERVER_H_ */
