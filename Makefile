FLAGS		= -Wall -Wextra -Werror -O3
CC			= gcc

LINCS		= ./libft/includes
MLX_INC		= ./minilibx
INCS		= -I ./incs -I $(MLX_INC) -I $(LINCS)

LIBS		= ./libft
LIBFT 		= -L$(LIBS) -lft

MLX_PATH 	= ./minilibx/
LIBMLX		= -L./minilibx -lmlx -framework OpenGL -framework Appkit

LANGAGE		= c
NAME		= fractol

SDL2		= -framework SDL2
SDL2_MIXER	= -framework SDL2_mixer
SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER	= -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/
SDL			= -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER	= -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)

SRC_DIR = srcs
OBJ_DIR = objs

LIST	=	ft_data \
			ft_terminal_ascii \
			ft_fractol

OBJO = $(LIST:.c=.o)
SRC = $(addprefix $(SRC_DIR)/, $(LIST))
OBJ = $(addprefix $(OBJ_DIR)/, $(OBJO))

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(FLAGS) $(INCS) $(SDL_HEADER) $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBS)
	@make -C $(MLX_PATH)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ) $(LIBFT) $(LIBMLX) $(SDL) $(SDL_HEADER)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] created"

clean:
	@make clean -C $(LIBS)
	@make clean -C $(MLX_PATH)
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

clean2:
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

fclean: clean
	@make fclean -C $(LIBS)
	@/bin/rm -f $(NAME)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] bin deleted"

sdl_install :
	curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
	unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/

re: fclean all

.PHONY: all clean clean2 fclean re leaks -leaks
