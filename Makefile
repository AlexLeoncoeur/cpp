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
CPPFILES = \

# DIRECTORIES 
SRC_DIR = src/
OBJ_DIR = objs/

# OBJECTS
CPP_OFILES = $(addprefix $(OBJ_DIR), $(CPP_FILES:.c=.o))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@ mkdir -p $(OBJ_DIR)
	@ echo "$(BLUE)-Compiling File: $(CYAN)src/$(RESET)$(notdir $<)"
	@ $(CC) $(FLAGS) -c $< -o $@ -g

#---------- FLAGS & COMPILATION ----------#

CC = c++
NAME = ex00
CFLAGS = -Wall -Werror -Wextra -std=c++98

all: libft $(NAME)
$(NAME): compiling $(PARSER_OFILES) $(RAY_CASTING_OFILES) $(BUILT_IN_OFILES) $(OFILES) $(MLX42)
	@ echo
	@ $(CC) $(CFLAGS) $(PARSER_OFILES) $(RAY_CASTING_OFILES) $(BUILT_IN_OFILES) $(OFILES) include/libft/libft.a $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
	@ echo "$(YELLOW)COMPILATION FINISHED!$(RESET)"

debug: all
	@ echo
	@ $(CC) $(CFLAGS) $(PARSER_OFILES) $(RAY_CASTING_OFILES) $(BUILT_IN_OFILES) $(OFILES) include/libft/libft.a $(MLX42) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME) -g -fsanitize=address
	@ echo "$(RED)DEBUG MODE ACTIVATED!$(RESET)"

libft:
	@ make --silent -C include/libft/ bonus

$(MLX42):
	@ make -C ./include/MLX42/build
	@ make -C ./include/MLX42/build -j4

bonus: all $(BONUS_NAME)
$(BONUS_NAME): $(BONUS_OFILES) $(BONUS_ORDER_OFILES)
	@ $(CC) $(CFLAGS) $(BONUS_OFILES) $(BONUS_ORDER_OFILES) -o $(BONUS_NAME)

#---------- CLEAN ----------#

clean:
	@ echo "$(RED)CLEANING PROJECT ... $(RESET)"
	@ rm -rf $(OBJ_DIR)
	@ make --silent -C "include/libft/" fclean
	@ make --silent -C "include/MLX42/build/" clean
	@ echo "$(YELLOW)PROJECT CLEANED!\n $(RESET)"

fclean: clean
	@ rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebug: re debug
	@ ./cub3d maps/map_5.cub

compiling:
	@ echo "$(MAGENTA)COMPILING PROJECT: $(RESET)"

.PHONY: all clean fclean re bonus compiling libft MLX42 debug rebug
