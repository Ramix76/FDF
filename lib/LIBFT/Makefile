# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/05 12:18:10 by framos-p          #+#    #+#              #
#    Updated: 2022/12/22 15:35:49 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

DIR_INC = inc
HEADER_LIB = $(DIR_INC)/libft.h
#HEADER_GNL = $(DIR_INC)/get_next_line.h
DIR_OBJS =	OBJS
DIR_SRCS =	srcs

SRCS =	ft_isalpha.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strchr.c ft_toupper.c ft_tolower.c ft_strrchr.c \
		ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strnstr.c ft_memchr.c \
		ft_strnstr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
		ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c  ft_putnbr_fd.c \
		ft_striteri.c ft_strmapi.c ft_split.c ft_itoa.c ft_putendl_fd.c get_next_line.c \
		ft_lstnew.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
		ft_lstclear.c ft_lstiter.c ft_lstadd_front.c 

OBJ = 		$(addprefix $(DIR_OBJS)/, $(SRCS:.c=.o))
#OBJ = 		$(patsubst $(DIR_SRCS)/%, $(DIR_OBJS)/%, $(SRCS:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# Colors
#
NO_COLOR	=	\033[0m
DEF_COLOR	=	\033[0;39m
GRAY		=	\033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE			=	\033[0;97m

all: 		
			@$(MAKE) $(NAME)

$(NAME)::	$(DIR_OBJS) $(OBJ) Makefile
			@ar rcs ${NAME} ${OBJ}
			@echo "\n$(BLUE)Compiling Libft...\n$(END_COLOR)"

$(NAME)::
			@echo "\n$(WHITE)Libft is Compiled!\n$(END_COLOR)"


$(DIR_OBJS):
					@-mkdir -p OBJS

$(DIR_OBJS)/%.o:	$(DIR_SRCS)/%.c $(HEADER_LIB)
					@$(CC) $(CFLAGS) -I $(DIR_INC) -c $< -o $@

clean: 		
			@$(RM) $(OBJ)
			@$(RM) $(DIR_OBJS)

fclean: 	
			@$(MAKE) clean
			@$(RM) $(NAME)

re:			
			@$(MAKE) fclean
			@$(MAKE) all

.PHONY: all clean fclean re
