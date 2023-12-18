 #SETUP
NAME		=	push_swap
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	push_swap.h
HEADER_DIR	=	include/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

MPATH_SRCS	=	complex_sort2.c easy_sort.c main.c utils.c\
				ans_list_utils.c do_ope_p.c easy_sort2.c make_a_list.c\
				check_av_make_infos.c do_ope_r.c free_all.c make_ill_list.c\
				check_av_make_infos2.c do_ope_rr.c ft_atoll.c print_ans.c\
				complex_sort.c do_ope_s.c ft_split.c trim_ans.c
MPATH_DIR	=	mandatory/
MPATH		=	$(addprefix $(MPATH_DIR), $(MPATH_SRCS))
OBJ_M		=	$(MPATH:.c=.o)

#CHECKER_NAME=	checker
#BPATH_SRCS	=
#BPATH_DIR	=	bonus/
#BPATH		=	$(addprefix $(BPATH_DIR), $(BPATH_SRCS))
#OBJ_B		=	$(BPATH:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
				@${CC} ${FLAGS} -c $< -o $@

$(NAME):		$(OBJ_M)
				@$(CC) ${FLAGS} $(OBJ_M) -o $(NAME)
				@echo -e "$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

#bonus:			$(OBJ_B)
#				@$(CC) ${FLAGS} $(OBJ_B) -o $(CHECKER_NAME)
#				@echo -e "$(GREEN)$(CHECKER_NAME)(bonus) created!$(DEFAULT)"

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_B)
				@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo -e "$(RED)all deleted!$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean bonus re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m