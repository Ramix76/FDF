# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: framos-p <framos-p@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 17:37:28 by framos-p          #+#    #+#              #
#    Updated: 2023/01/09 12:31:08 by framos-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= fdf

SRC_DIR		:= srcs/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -Wall -Werror -Wextra
#FSANITIZE	:= -fsanitize=address -g3
NOFLAGS		:= -g
RM			:= rm -f

INC		 		:= inc/
LIB				:= lib/
LIBFT_DIR		:= $(LIB)LIBFT/
LIBFT			:= $(LIBFT_DIR)libft.a
MINILIBX_DIR	:= $(LIB)minilibx/minilibx_macos/
MINILIBX		:= $(MINILIBX_DIR)libmlx.a
MINILIBXCC		:= -I mlx -L $(MINILIBX_DIR) -lmlx
HEADER 			:= -I$(INC) -I$(LIBFT_DIR) -I$(MINILIBX_DIR)
OPENGL			:= -framework OpenGL -framework AppKit

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#Sources

SRC_FILES	=	draw_pixels  main keys utils read_maps error check_init_map
SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

all:	$(NAME)
			
-include 	${DEPS}
$(NAME)::	$(LIBFT) $(MINILIBX) $(OBJ)
			@make -sC $(LIBFT_DIR)
			@make -sC $(MINILIBX_DIR)
			@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)
			@echo "\n👉 $(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBFT) $(MINILIBXCC) $(OPENGL) -o $(NAME)$(DEF_COLOR)"

$(NAME)::
			@echo "\n$(GREEN)✨ FDF compiled!\n$(DEF_COLOR)"

bonus:		
			@$(MAKE) all
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS) | $(OBJF)
			@echo "🍩 $(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) $(CFLAGS) -MMD -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(LIBFT):
			@make -C $(LIBFT_DIR)
			@echo "$(GREEN)Libft compiled!\n$(DEF_COLOR)"

$(MINILIBX):
			@make -C $(MINILIBX_DIR)
			@echo "\n$(GREEN)Minilibx compiled!\n$(DEF_COLOR)"

clean:
			@make clean -sC $(LIBFT_DIR)
			@echo "\n$(CYAN)Libft object and dependency files cleaned!\n$(DEF_COLOR)"
			@make clean -C $(MINILIBX_DIR)
			@echo "\n$(CYAN)Minilibx object files cleaned!\n$(DEF_COLOR)"
			@$(RM) -rf $(OBJ_DIR)
			@echo "\n$(CYAN)Fdf object files cleaned!\n$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "\n$(CYAN)Fdf executable files cleaned!\n$(DEF_COLOR)"
			@$(RM) -f $(MINILIBX_DIR)libmlx.a
			@echo "\n$(CYAN)libmlx.a lib cleaned!\n$(DEF_COLOR)"
			@$(RM) -f $(LIBFT_DIR)libft.a
			@echo "\n$(CYAN)libft.a lib cleaned!\n$(DEF_COLOR)"


re:			fclean 
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

.PHONY:		all clean fclean re norm
