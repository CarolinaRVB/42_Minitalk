# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 09:27:31 by crebelo-          #+#    #+#              #
#    Updated: 2023/12/03 09:27:31 by crebelo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CC = cc

CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address

RM = rm -f

INCLUDE = minitalk.h

LIBFT_DIR = libft

LIBFT_A = $(LIBFT_DIR)/libft.a

SERVER_SRC = server.c

CLIENT_SRC = client.c

SERVER_BONUS_SRC = server_bonus.c

CLIENT_BONUS_SRC = client_bonus.c

all: $(NAME)

$(NAME): server client

server: $(SERVER_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(LIBFT_A) -o $@

client: $(CLIENT_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(LIBFT_A) -o $@

bonus: server_bonus client_bonus

server_bonus: $(SERVER_BONUS_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(SERVER_BONUS_SRC) $(LIBFT_A) -o $@

client_bonus: $(CLIENT_BONUS_SRC)
	@make -C $(LIBFT_DIR) > /dev/null
	@$(CC) $(CFLAGS) $(CLIENT_BONUS_SRC) $(LIBFT_A) -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(NAME) server client server_bonus client_bonus

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all
