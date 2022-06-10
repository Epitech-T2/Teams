/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** commands
*/

#ifndef COMMANDS_H_
    #define COMMANDS_H_

    #include "./client.h"

    static const char *proto[24] = {
        "100",
        "201",
        "300",
        "301",
        "202",
        "302",
        "203",
        "303",
        "304",
        "204",
        "205",
        "206",
        "207",
        "208",
        "305",
        "306",
        "307",
        "308",
        "309",
        "310",
        "311",
        "312",
        "313",
        NULL
    };

    typedef void (*commands)(char **tab);

    static const commands funct[] = {
        &help_cmd,
        &logout_cmd,
        &users_cmd,
        &user_cmd,
        &send_cmd,
        &messages_cmd,
        &subscribe_cmd,
        &subscribed_cmd,
        &subscribed_team_cmd,
        &unsubscribe_cmd,
        &create_team_cmd,
        &create_channel_cmd,
        &create_thread_cmd,
        &create_reply_cmd,
        &list_team_cmd,
        &list_channel_cmd,
        &list_thread_cmd,
        &list_reply_cmd,
        &info_team_cmd,
        &info_channel_cmd,
        &info_thread_cmd,
        &info_reply_cmd,
        &shared_cmd,
        NULL
    };

    #endif /* !CLIENT_H_ */
