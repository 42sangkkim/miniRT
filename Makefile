# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/02 18:03:53 by sangkkim          #+#    #+#              #
#    Updated: 2023/01/12 22:01:55 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME := miniRT

SRCS := main.c \
			init_scene/init_scene.c init_scene/parse_rt_file.c \
			init_scene/parse_object.c init_scene/parse_capital.c \
			init_scene/parse_util1.c init_scene/parse_util2.c init_scene/print_scene.c \
				init_scene/parser/parser1.c init_scene/parser/parser2.c \
			init_mlx/init_mlx.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

INC_DIR := ./headers
SRC_DIR := ./sources

LIBFT_DIR := ./libft
LIBFT := ft
LIBFT_FLAG := -L $(LIBFT_DIR) -l $(LIBFT)

MLX_DIR := ./minilibx
MLX := mlx
MLX_FLAG := -L $(MLX_DIR) -l $(MLX) -framework OpenGL -framework AppKit -lz

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I $(INC_DIR) -I $(LIBFT_DIR) -I $(MLX_DIR) -MMD
LDFLAGS := $(LIBFT_FLAG) $(MLX_FLAG)

#RM : rm -f

$(NAME) : $(addprefix $(SRC_DIR)/, $(OBJS))
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/libmlx.dylib ./
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
