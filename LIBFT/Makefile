# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 00:15:57 by settaqi           #+#    #+#              #
#    Updated: 2019/10/21 07:16:52 by settaqi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

file_srcs = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
ft_tolower.c ft_toupper.c

bonus_srcs = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
ft_lstdelone_bonus.c ft_lstlast_bonus.c ft_lstnew_bonus.c \
ft_lstsize_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
ft_lstmap_bonus.c

file_objects = ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o \
ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o \
ft_itoa.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o \
ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o \
ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o \
ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o \
ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o \
ft_tolower.o ft_toupper.o

bonus_objects = ft_lstadd_back_bonus.o ft_lstadd_front_bonus.o \
ft_lstdelone_bonus.o ft_lstlast_bonus.o ft_lstnew_bonus.o \
ft_lstsize_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o \
ft_lstmap_bonus.o

objects = $(wildcard *.o)


all: $(NAME)

$(NAME):
	@gcc -c -Wextra -Werror -Wall $(file_srcs)
	@ar rc libft.a $(file_objects)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(objects)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

bonus:
	@gcc -c -Wextra -Werror -Wall $(bonus_srcs)
	@ar -rsv $(NAME) $(bonus_objects)
	@ranlib $(NAME)

.PHONY: clean bonus fclean all re