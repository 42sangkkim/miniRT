# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 18:03:53 by sangkkim          #+#    #+#              #
#    Updated: 2023/01/12 02:38:20 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

SRCS := main.c \
			init_scene/init_scene.c init_scene/parse_rt_file.c \
			init_scene/parse_object.c init_scene/parse_capital.c \
			init_scene/parse_util1.c init_scene/parse_util2.c init_scene/print_scene.c\
				init_scene/parser/parser1.c init_scene/parser/parser2.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

INC_DIR := ./headers
SRC_DIR := ./sources

LIBFT_DIR := libft
LIBFT := ft

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I $(INC_DIR) -I $(LIBFT_DIR) -MMD

LDFLAGS := -L $(LIBFT_DIR) -l $(LIBFT)

#RM : rm -f

$(NAME) : $(addprefix $(SRC_DIR)/, $(OBJS))
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(addprefix $(LIBFT_DIR)/, $(LIBFT)) :
	make -C $(LIBFT_DIR)

# %.o : %.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

.PHONY : all clean fclean re #bonus

all : $(NAME)

clean :
	$(RM) $(addprefix $(SRC_DIR)/, $(OBJS))
	$(RM) $(addprefix $(SRC_DIR)/, $(DEPS))

fclean : clean
	$(RM) $(NAME)

re : fclean all

-include $(addprefix $(DEP_DIR)/, $(DEPS))
