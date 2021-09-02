# Name of the program built
NAME_CLIENT		:=		client
NAME_SERVER		:=		server

# Name directory
PATH_SRC			:=		src
PATH_CLIENT			:=		$(PATH_SRC)/client
PATH_SERVER			:=		$(PATH_SRC)/server
PATH_BUILD			:=		build
PATH_LIBFT			:=		libft

# List of sources
SRCS_CLIENT			:=		$(shell find $(PATH_CLIENT) -name *.c)
OBJS_CLIENT			:=		$(SRCS_CLIENT:%.c=$(PATH_BUILD)/%.o)
SRCS_SERVER			:=		$(shell find $(PATH_SERVER) -name *.c)
OBJS_SERVER			:=		$(SRCS_SERVER:%.c=$(PATH_BUILD)/%.o)
DEPS				:=		$(OBJS:.o=.d)
INC_DIRS			:=		$(shell find $(PATH_SRC) -type d)

# Compiler
CC					:=		gcc

# Flags - compilation
FLAG_WARNING		:=		-Wall -Wextra -Werror
FLAG_INC			:= 		$(addprefix -I, $(INC_DIRS))
FLAG_MAKEFILE		:=		-MMD -MP
FLAG_DEBUG			:= 		-g
FLAG_OPTIMIZATION	:=		-O3
FLAGS_COMP			:= 		$(FLAG_WARNING) $(FLAG_INC) $(FLAG_MAKEFILE) $(FLAG_DEBUG) $(FLAG_OPTIMIZATION)

# Flags - memory leak check
FLAG_MEM_LEAK		:= 		-fsanitize=address

# Flags - linking
FLAG_LIBFT			:=		-L$(PATH_LIBFT) -lft 

# Others commands
RM					:=		rm -rf

# Color Code and template code
_YELLOW				:=		\e[38;5;184m
_GREEN				:=		\e[38;5;46m
_RESET				:=		\e[0m
_INFO				:=		[$(_YELLOW)INFO$(_RESET)]
_SUCCESS			:=		[$(_GREEN)SUCCESS$(_RESET)]

# General functions
all:						init $(NAME_CLIENT) $(NAME_SERVER)
							@ printf "$(_SUCCESS) Compilation done\n"

init:
							@ printf "$(_INFO) Initialize $(NAME_CLIENT) and $(NAME_SERVER)\n"
							@ make -C $(PATH_LIBFT)

$(NAME_CLIENT):			$(OBJS_CLIENT) 
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS_CLIENT) $(FLAG_LIBFT)

$(NAME_SERVER):			$(OBJS_SERVER)
							@ $(CC) $(FLAGS_COMP) -o $@ $(OBJS_SERVER) $(FLAG_LIBFT)

$(PATH_BUILD)/%.o:	%.c
							@ mkdir -p $(dir $@)
							@ $(CC) $(FLAGS_COMP) -c $< -o $@

bonus:						all

clean:
							@ $(RM) $(PATH_BUILD)
							@ make -C $(PATH_LIBFT) clean
							@ printf "$(_INFO) Deleted files and directory\n"

fclean:						clean
							@ $(RM) $(NAME_CLIENT) $(NAME_SERVER)
							@ make -C $(PATH_LIBFT) fclean

re:							fclean all

# Debugging functions

debug:						FLAGS_COMP += $(FLAG_MEM_LEAK)
debug:						re

# Format functions

normH:
							@ norminette $(shell find $(PATH_SRC) -name *.h)
							@ make -C $(PATH_LIBFT) normH

normC:
							@ norminette $(shell find $(PATH_SRC) -name *.c)
							@ make -C $(PATH_LIBFT) normC

norm:						normH normC

.PHONY:						all clean fclean re

-include $(DEPS)
