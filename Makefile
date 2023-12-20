CC = cc
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address

SRCS_SERV = ./server.c ./modified_atoi.c ./utils.c
SRCS_SERV_BONUS = ./server_bonus.c ./modified_atoi.c ./utils_bonus.c
SRCS_CLI = ./client.c ./modified_atoi.c ./utils.c
SRCS_CLI_BONUS = ./client_bonus.c ./modified_atoi.c ./utils_bonus.c
OBJS_SERV = $(SRCS_SERV:.c=.o)
OBJS_SERV_BONUS = $(SRCS_SERV_BONUS:.c=.o)
OBJS_CLI = $(SRCS_CLI:.c=.o)
OBJS_CLI_BONUS = $(SRCS_CLI_BONUS:.c=.o)
SERVER = server
CLIENT = client
NAME = $(SERVER) $(CLIENT)

ifdef WITH_BONUS
	SRCS_SERV := $(SRCS_SERV_BONUS)
	SRCS_CLI := $(SRCS_CLI_BONUS)
	OBJS_SERV := $(SRCS_SERV:.c=.o)
	OBJS_CLI := $(SRCS_CLI:.c=.o)
endif

all: $(NAME)

server: $(OBJS_SERV)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS_SERV) -o $(SERVER) -L./libft -lft

client: $(OBJS_CLI)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) $(OBJS_CLI) -o $(CLIENT) -L./libft -lft

bonus:
	make WITH_BONUS=1 all
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C ./libft clean
	rm -f $(OBJS_SERV) $(OBJS_CLI) $(OBJS_SERV_BONUS) $(OBJS_CLI_BONUS)

fclean: clean
	$(MAKE) -C ./libft fclean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all bonus clean fclean re
