# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sangkkim <sangkkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 21:23:49 by sangkkim          #+#    #+#              #
#    Updated: 2023/01/05 15:05:10 by sangkkim         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc
CFLAGS := -Wall -Wextra -Werror
CPPFLAGS := -I ./ -MMD

# AR := ar
# ARFLAGS:= rv

# RM := rm -f

PART1_DIR := part1
PART2_DIR := part2
CUSTOM_DIR := custom
BONUS_DIR := bonus

PART1_SRCS := ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c
PART2_SRCS := ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
CUSTOM_SRCS := ft_strtol.c ft_strtod.c ft_strcmp.c ft_isspace.c
BONUS_SRCS := ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

MANDATORY_SRCS := $(addprefix $(PART1_DIR)/, $(PART1_SRCS)) \
				  $(addprefix $(PART2_DIR)/, $(PART2_SRCS)) \
				  $(addprefix $(CUSTOM_DIR)/, $(CUSTOM_SRCS))
MANDATORY_OBJS := $(MANDATORY_SRCS:.c=.o)
MANDATORY_DEPS := $(MANDATORY_SRCS:.c=.d)

BONUS_SRCS := $(addprefix $(BONUS_DIR)/, $(BONUS_SRCS))
BONUS_OBJS := $(BONUS_SRCS:.c=.o)
BONUS_DEPS := $(BONUS_SRCS:.c=.d)

# %.o : %.c
# 	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

$(NAME) : $(MANDATORY_OBJS)
	$(AR) $(ARFLAGS)c $(NAME) $(MANDATORY_OBJS)

.PHONY : all clean fclean re bonus

all : $(NAME)

clean :
	$(RM) $(MANDATORY_OBJS) $(BONUS_OBJS)
	$(RM) $(MANDATORY_DEPS) $(BONUS_DEPS)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus : $(NAME) $(BONUS_OBJS)
	$(AR) $(ARFLAGS)r $(NAME) $(BONUS_OBJS)

-include $(DEPS)

