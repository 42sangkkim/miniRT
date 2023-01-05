# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 18:03:53 by sangkkim          #+#    #+#              #
#    Updated: 2023/01/04 19:33:58 by sangkkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

SRCS := main.c \
		init_scene/init_scene.c init_scene/parse_scene.c init_scene/parse_object.c init_scene/parse_utils.c init_scene/get_next_line.c
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
