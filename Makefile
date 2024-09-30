# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dzubkova <dzubkova@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 16:34:11 by dzubkova          #+#    #+#              #
#    Updated: 2024/02/27 19:21:10 by dzubkova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C_SRC = client.c
S_SRC = server.c

O_C_SRC = client.o
O_S_SRC = server.o

CFLAGS = -Wall -Wextra -Werror

GREEN		=	\e[38;5;118m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)DONE$(RESET)]

NAME = minitalk
SERVER = server
CLIENT = client

all: $(CLIENT) $(SERVER)

$(CLIENT): $(O_C_SRC)
	$(MAKE) bonus -C ./libft
	cc $(CFLAGS) $(C_SRC) libft/libft.a -o $(CLIENT)
	@printf "$(_SUCCESS)Client is ready.\n"

$(SERVER): $(O_S_SRC)
	$(MAKE) bonus -C ./libft
	cc $(CFLAGS) $(S_SRC) libft/libft.a -o $(SERVER)
	@printf "$(_SUCCESS)Server is ready.\n"

%.o: %.c
	cc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(O_C_SRC) $(O_S_SRC)
	$(MAKE) clean -C ./libft

fclean: clean
	rm -f $(CLIENT)
	rm -f $(SERVER)
	rm -f libft.a
	$(MAKE) fclean -C ./libft

re: fclean all

.PHONY: all clean fclean re