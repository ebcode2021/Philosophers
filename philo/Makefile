# PROGRAM_NAME
NAME = philo

# VARIABLE
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# PHILOSOPHERS_SRC
SRCS = main.c \
		print.c \
		routine.c \
		init_inform.c \
		init_philos.c
SRCS_DIR = src/
SRCS_PATH = $(addprefix $(SRCS_DIR), $(SRCS))

INCS = includes/
OBJS = $(SRCS_PATH:.c=.o)

# SANITIZE
ifdef SANITIZE
	CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g3
endif

# COMMANDS
%.o : %.c
	@echo "$(YELLOW) *** Generating push_swap objects... *** $(DEFAULT)"
	$(CC) $(CFLAGS) -c $< -o $@  -I$(INCS)

$(NAME) : $(OBJS)
	@echo "$(GREEN) *** Compiling philo ... *** $(DEFAULT)"
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN) *** Compile Done!! *** $(DEFAULT)"

all : $(NAME)
	@echo "$(GREEN) *** Project Ready! *** $(DEFAULT)"

clean :
	$(RM) $(OBJS)
	@echo "$(RED) *** Deleteing Objects Done! *** $(DEFAULT)"

fclean : clean
	$(RM) $(NAME)
	@echo "$(RED) *** Delete Program Done! *** $(DEFAULT)"

re :
	make fclean
	make all

sanitize :
	make SANITIZE=1 re

.PHONY : all clean fclean re sanitize

# COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m