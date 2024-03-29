# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 14:03:15 by jgourdin          #+#    #+#              #
#    Updated: 2019/01/13 21:05:01 by gmichaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

SRC_NAME = Log.cpp AEntity.cpp EntitiesList.cpp main.cpp Renderer.cpp \
	Time.cpp Inputs.cpp Physics.cpp GameLoop.cpp Player.cpp Game.cpp Projectile.cpp \
	AEnemy.cpp SimpleEnemy.cpp MedEnemy.cpp BigEnemy.cpp Hud.cpp Decors.cpp

INC_NAME = Log.hpp AEntity.hpp EntitiesList.hpp Renderer.hpp Inputs.hpp Time.hpp \
	Player.hpp Game.hpp Physics.hpp GameLoop.hpp Projectile.hpp AEnemy.hpp SimpleEnemy.hpp \
	MedEnemy.hpp BigEnemy.hpp Hud.hpp Decors.hpp

INC_PATH = ./includes

INC_FLAGS = -I./includes

LIB_FLAGS =

LIBS = -lncurses

CC = clang++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC_PATH = src

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ_PATH = obj

OBJ_NAME = $(SRC:.cpp=.o)

OBJ = $(subst $(SRC_PATH),$(OBJ_PATH),$(OBJ_NAME))

INC = $(addprefix $(INC_PATH)/,$(INC_NAME))

RED = \x1B[31m
GRN = \x1B[32m
YEL = \x1B[33m
BLU = \x1B[34m
MAG = \x1B[35m
CYN = \x1B[36m
WHT = \x1B[37m
RESET = \x1B[0m
ERASE = \033[2K

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(LIB_FLAGS) $(LIBS)
	@echo "\n$(BLU)[$(NAME)]$(GRN) Compilation success$(RESET)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.cpp $(INC)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -o $@ -c $<
	@echo "\r$(ERASE)$(BLU)[$(NAME)]$(RESET) $@ created\c"

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_PATH)
	@echo "$(BLU)[$(NAME)]$(RED) .o files deleted$()$(RESET)"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LINKNAME)
	@echo  "$(BLU)[$(NAME)]$(RED) executable file deleted$(RESET)"

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
