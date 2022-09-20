# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 07:31:23 by abucia            #+#    #+#              #
#    Updated: 2022/06/02 09:34:45 by abucia           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BONUS_NAME = so_long_bonus
SRC = src/free/free.c src/free/parsing_free.c src/free/texture_free.c		\
		src/global_gameplay/collision.c src/global_gameplay/commands.c		\
		src/global_gameplay/main.c src/global_gameplay/manage.c				\
		src/global_gameplay/player.c src/parser/checker.c src/parser/read.c	\
		src/parser/map_parser.c src/texture/init_texture.c					\
		src/texture/make_map.c src/texture/sort_texture.c					\
		src/utils/common_utils.c src/utils/mlx_utils.c						\
		src/utils/so_long_utils.c src/utils/texture_utils.c
BONUS = src/free/free.c src/free/parsing_free.c src/free/texture_free.c		\
		src/global_gameplay/collision.c src/global_gameplay/commands.c		\
		src/global_gameplay/main.c src/global_gameplay/manage.c				\
		src/global_gameplay/player.c src/parser/checker.c src/parser/read.c	\
		src/parser/map_parser.c src/texture/init_texture.c					\
		src/texture/make_map.c src/texture/sort_texture.c					\
		src/utils/common_utils.c src/utils/mlx_utils.c						\
		src/utils/so_long_utils.c src/utils/texture_utils.c
CC = gcc
OBJ = $(SRC:.c=.o)
OBJ_B = $(BONUS:.c=.o)
DIM = 500
MOV = 20
ATIME = 4
FLAG = -Lmlx -lmlx -framework OpenGL -framework AppKit
GLOBAL_FLAG = -D DIM=$(DIM) -D MOV=$(MOV) -D ATIME=$(ATIME) 
HEADER = src/include/header.h
HEADER_BONUS = src/include/header.h
LMLX = make

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@make -C mlx/
	@$(CC) -o $(NAME) $(OBJ) $(FLAG)
	@echo "$(GREEN)HAVE FUN ! do ./$@ map/<map>$(RST)"
	@echo "$(N_PURPLE) ┌───────────────────────────────────────────────────────────────────────┐$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗            $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝            $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗           $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║           $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝           $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝            $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │   By Abucia                                                           │$(RST)"
	@echo "$(N_PURPLE) └───────────────────────────────────────────────────────────────────────┘$(RST)"

%.o : %.c $(HEADER)
	@$(CC) $(GLOBAL_FLAG) -Ofast -Wall -Wextra -Werror -c $< -o $@

$(LMLX): makemlx

makemlx:
	@${MAKE} -C mlx/
	@cp mlx/libmlx.dylib .

clean : 
	@rm -rf $(OBJ) $(OBJ_B)
	@echo "$(GREEN)************ $@ clean !$(RST)"

fclean : clean
	@rm -rf $(NAME)
	@echo "$(GREEN)************ $@ fclean !$(RST)"

re : fclean all

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(OBJ_B) $(HEADER_BONUS)
	@make -C mlx/
	@$(CC) -o $(BONUS_NAME) $(OBJ_B) $(FLAG)
	@echo "$(GREEN)************ $@ SUCESS$(RST)"
	@echo "$(N_PURPLE) ┌───────────────────────────────────────────────────────────────────────┐$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ███████╗ ██████╗     ██╗      ██████╗ ███╗   ██╗ ██████╗            $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ██╔════╝██╔═══██╗    ██║     ██╔═══██╗████╗  ██║██╔════╝            $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ███████╗██║   ██║    ██║     ██║   ██║██╔██╗ ██║██║  ███╗           $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ╚════██║██║   ██║    ██║     ██║   ██║██║╚██╗██║██║   ██║           $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ███████║╚██████╔╝    ███████╗╚██████╔╝██║ ╚████║╚██████╔╝           $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE) ╚══════╝ ╚═════╝     ╚══════╝ ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝            $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)  -Bonus Part                                                        $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │ $(PURPLE)                                                                     $(RST)$(N_PURPLE) │$(RST)"
	@echo "$(N_PURPLE) │   By Abucia                                                           │$(RST)"
	@echo "$(N_PURPLE) └───────────────────────────────────────────────────────────────────────┘$(RST)"

.PHONY: bonus all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
RST = \033[0m
PURPLE = \033[5;35m
N_PURPLE = \033[1;35m
