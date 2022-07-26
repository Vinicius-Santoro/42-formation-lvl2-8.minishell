NAME		=	minishell
HEADER		=	minishell.h
INCLUDE		=	-I includes

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror

LIBFT		=	./libft/libft.a

SRC_PATH	=	./src/
OBJ_PATH	=	./obj/

SRC_FILES	=	builtins/cd.c \
				builtins/echo.c \
				builtins/env.c \
				builtins/exit.c \
				builtins/export.c \
				builtins/pwd.c \
				builtins/unset.c \
				executor/exec_command.c \
				parser/parse_conditionals.c \
				parser/parse.c \
				tokenizer/tokenizer.c \
				utils/cmd_split.c \
				utils/error.c \
				utils/free.c \
				utils/get_path.c \
				utils/open.c \
				utils/signal.c \
				main.c

SRC			=	$(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_PATH),$(subst .c,.o,$(SRC_FILES)))

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJ_PATH) $(OBJ)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -lreadline

$(OBJ_PATH):	
				mkdir -p $(OBJ_PATH)executor
				mkdir -p $(OBJ_PATH)builtins
				mkdir -p $(OBJ_PATH)parser
				mkdir -p $(OBJ_PATH)tokenizer
				mkdir -p $(OBJ_PATH)utils
				
$(LIBFT):
				make bonus -C ./libft

clean:
				$(RM) obj
				make clean -C libft

fclean:			clean
				$(RM) $(NAME)
				make fclean -C libft
				

re:				fclean all

.PHONY:			all, clean, fclean, re