# COLORS
MAGENTA = \033[35;1m
YELLOW  = \033[33;1m
GREEN   = \033[32;1m
WHITE   = \033[37;1m
RESET   = \033[0m
GRAY 	= \033[0;90m
BLUE    = \033[34;1m
CYAN    = \033[37;1m
BOLD	= \033[1m
RED		= \033[31;1m

#---------- BASE ----------#

# FILES 
CPP_FILES = tests.cpp Account.cpp\

# DIRECTORIES 
SRC_DIR = src/
OBJ_DIR = objs/

# OBJECTS
CPP_OFILES = $(addprefix $(OBJ_DIR), $(CPP_FILES:.cpp=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	@ mkdir -p $(OBJ_DIR)
	@ echo "$(BLUE)-Compiling File: $(CYAN)src/$(RESET)$(notdir $<)"
	@ $(CC) $(FLAGS) -c $< -o $@ -g

#---------- FLAGS & COMPILATION ----------#

CC = c++
NAME = ex02
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)
$(NAME): compiling $(CPP_OFILES)
	@ echo
	@ $(CC) $(CFLAGS) $(CPP_OFILES) -o $(NAME)
	@ echo "$(YELLOW)COMPILATION FINISHED!$(RESET)"

debug: all
	@ echo
	@ echo "$(RED)DEBUG MODE ACTIVATED!$(RESET)"
	@ valgrind -s ./$(NAME)

libft:
	@ make --silent -C include/libft/ bonus

#---------- CLEAN ----------#

clean:
	@ echo "$(RED)CLEANING PROJECT ... $(RESET)"
	@ rm -rf $(OBJ_DIR)
	@ echo "$(YELLOW)PROJECT CLEANED!\n $(RESET)"

fclean: clean
	@ rm -f $(NAME)

re: fclean all

rebug: re debug

compiling:
	@ echo "$(MAGENTA)COMPILING PROJECT: $(RESET)"

.PHONY: all clean fclean re compiling debug rebug
