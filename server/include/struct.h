/*
** EPITECH PROJECT, 2022
** Teams
** File description:
** structs
*/

#ifndef STRUCTS_H_
    #define STRUCTS_H_

    #include <uuid/uuid.h>

    typedef struct user {
        char *uuid;
        char *name;
        bool status;
        struct user *next;
    } user_t;

    typedef struct comment {
        char *text;
        char *thread_uuid;
        char *user_uuid;
        time_t reply_timestamp;
        struct comment *next;
    } comment_t;

    typedef struct thread {
        char *title;
        char *body;
        char *uuid;
        char *creator_uuid;
        time_t thread_timestamp;
        comment_t *comments;
        struct thread *next;
    } thread_t;

    typedef struct channel {
        char *name;
        char *description;
        char *uuid;
        thread_t *threads;
        struct channel *next;
    } channel_t;

    typedef struct team {
        char *name;
        char *description;
        char *uuid;
        channel_t *channels;
        user_t *authorized_users;
        struct team *next;
    } team_t;

#endif /* !STRUCTS_H_ */
