/*
** EPITECH PROJECT, 2022
** Network
** File description:
** client
*/

#ifndef CLIENT_H_
    #define CLIENT_H_

    #define handle_error(msg) ({ perror(msg); exit(84); })
    #define MAX_CLIENTS 10

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <sys/time.h>
    #include <unistd.h>
    #include <signal.h>
    #include <arpa/inet.h>
    #include <stdbool.h>
    #include <netdb.h>
    #include <ctype.h>
    #include "../../libs/myteams/logging_client.h"

    static volatile sig_atomic_t run = 1;

    static inline void handler_signal_client(int signal)
    {
        run = 0;
    }

    typedef struct client {
        struct sockaddr_in address_client;
        int sock_client;
        socklen_t lenght;
        int port;
        fd_set rset;
        bool login;
        char *username;
        char *uuid;
        char *uuid_team;
        char *uuid_channel;
        char *uuid_thread;
        char *uuid_reply;
    } client_t;

    int print_help_client(void);
    int select_func_client(client_t *client);
    int close_client(client_t *client, int out);
    int error_close_client(client_t *client, int out);
    int recv_message(client_t *client);
    int send_client(client_t *client, char *cmd, ssize_t size_line);
    int select_command(client_t *client, char **tab);
    char **str_to_tab(char *str, char *tok);
    int check_protocol(char *cmd);
    client_t *get_client(void);

    // Commands ------------------

    void users_cmd(char **tab);
    void user_cmd(char **tab);
    void use_cmd(char **tab);
    void unsubscribe_cmd(char **tab);
    void subscribed_team_cmd(char **tab);
    void subscribed_cmd(char **tab);
    void subscribe_cmd(char **tab);
    void shared_cmd(char **tab);
    void send_cmd(char **tab);
    void messages_cmd(char **tab);
    void logout_cmd(char **tab);
    void login_cmd(client_t *client, char **tab);
    void list_team_cmd(char **tab);
    void list_channel_cmd(char **tab);
    void list_thread_cmd(char **tab);
    void list_reply_cmd(char **tab);
    void info_team_cmd(char **tab);
    void info_channel_cmd(char **tab);
    void info_thread_cmd(char **tab);
    void info_reply_cmd(char **tab);
    void help_cmd(__attribute__((unused)) char **tab);
    void errors_cmd(char **tab);
    void create_team_cmd(char **tab);
    void create_channel_cmd(char **tab);
    void create_thread_cmd(char **tab);
    void create_reply_cmd(char **tab);

#endif /* !CLIENT_H_ */
