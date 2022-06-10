##
## EPITECH PROJECT, 2022
## Network
## File description:
## Makefile
##

SRCSVR =	server/src/main.c \
			server/src/help.c \
			server/src/server.c \
			server/src/close_socket.c \
			server/src/utilities.c \
			server/src/recv.c \
			server/src//parser.c \
			server/src/commands/create_cmd.c \
			server/src/commands/help_cmd.c \
			server/src/commands/info_cmd.c \
			server/src/commands/list_cmd.c \
			server/src/commands/login_cmd.c \
			server/src/commands/logout_cmd.c \
			server/src/commands/messages_cmd.c \
			server/src/commands/select_command.c \
			server/src/commands/send_cmd.c \
			server/src/commands/use_cmd.c \
			server/src/commands/subscribe_cmd.c \
			server/src/commands/subscribed_cmd.c \
			server/src/commands/unsubscribe_cmd.c \
			server/src/commands/user_cmd.c \
			server/src/commands/users_cmd.c \
			server/src/database/check_exist.c \
			server/src/database/get_database.c \

SRCCLT =	client/src/main.c \
			client/src/help.c \
			client/src/client.c \
			client/src/recv.c \
			client/src/send.c \
			client/src/close_socket.c \
			client/src/utilities.c \
			client/src/check.c \
			client/src/commands/create_cmd.c \
			client/src/commands/errors_cmd.c \
			client/src/commands/help_cmd.c \
			client/src/commands/info_cmd.c \
			client/src/commands/list_cmd.c \
			client/src/commands/login_cmd.c \
			client/src/commands/logout_cmd.c \
			client/src/commands/messages_cmd.c \
			client/src/commands/shared_cmd.c \
			client/src/commands/select_command.c \
			client/src/commands/send_cmd.c \
			client/src/commands/subscribe_cmd.c \
			client/src/commands/subscribed_cmd.c \
			client/src/commands/unsubscribe_cmd.c \
			client/src/commands/user_cmd.c \
			client/src/commands/users_cmd.c \

OBJSVR = 	$(SRCSVR:.c=.o)

OBJCLT = 	$(SRCCLT:.c=.o)

NAMESVR = 	myteams_server

NAMECLT = 	myteams_cli

CC = gcc

LDFLAGS += 	-L ./libs/myteams/ -lmyteams -luuid

CFLAGS += 	-g -Wall -Wextra -I ./libs/myteams

all: 	myteams_server myteams_cli

myteams_server: 	$(OBJSVR)
		$(CC) $(CFLAGS) -o $(NAMESVR) $(OBJSVR) $(LDFLAGS)

myteams_cli:		$(OBJCLT)
		$(CC) $(CFLAGS) -o $(NAMECLT) $(OBJCLT) $(LDFLAGS)

clean:
		rm -f $(OBJSVR) $(OBJCLT)

fclean: clean
		rm -f $(NAMESVR) $(NAMECLT)

re: fclean all

.PHONY: all myteams_server myteams_cli clean fclean re
