# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlinhard <mlinhard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 10:37:09 by mlinhard          #+#    #+#              #
#    Updated: 2016/12/17 04:08:10 by mlinhard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror
# FLAGS	=
CC		= gcc $(FLAGS)
INCS 	= -I./incs -I./libft/includes -I./minilibx
LIBS	= ./libft
LIBFT 	= -L$(LIBS) -lft
LIBMLX	= -L./minilibx -lmlx -framework OpenGL -framework AppKit
LIBMLX2	= -L./minilibx -lmlx -L/usr/X11/lib -lX11 -lXext -framework OpenGL -framework AppKit
LANGAGE	= c
NAME	= fractol

SRC_DIR = srcs
OBJ_DIR = objs

LIST	=	ft_data \
			ft_sdl_music \
			ft_mlx_init \
			ft_mlx_loop \
			ft_mlx_hook \
			ft_mlx_img \
			ft_mlx_scene \
			ft_mlx_scene_img \
			ft_mlx_scene_img_push \
			ft_mlx_scene_layer \
			ft_mlx_scene_img_init \
			ft_mlx_s0_mouse_action \
			ft_terminal_ascii \
			ft_terminal_log \
			ft_display_help \
			ft_exit \
			ft_free \
			ft_scene_0_intro \
			ft_fractol

SRC := $(addprefix $(SRC_DIR)/, $(addsuffix .$(LANGAGE), $(LIST)))
OBJ := $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(LIST)))

C_END	= "\033[0m"
C_GOOD	= "\033[32m"
C_GREY  = "\033[1;30m"
C_BAD	= "\033[31m"
C_BLUE	= "\033[34;1m"

SDL2		= -framework SDL2
SDL2_MIXER	= -framework SDL2_mixer
SDL2_HEADER			= -I ~/Library/Frameworks/SDL2.framework/Headers/
SDL2_HEADER_MIXER	= -I ~/Library/Frameworks/SDL2_mixer.framework/Headers/
SDL			= -F ~/Library/Frameworks $(SDL2_MIXER) $(SDL2)
SDL_HEADER	= -F ~/Library/Frameworks $(SDL2_HEADER_MIXER) $(SDL2_HEADER)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBS)
	@make -C ./minilibx
	$(CC) $(OBJ) -o $@ $(FLAGS) $(INCS) $(LIBFT) $(LIBMLX) $(SDL) $(SDL_HEADER)
	@echo "✅  ["$(C_GOOD) $(NAME) $(C_END)"] created"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(LANGAGE)
	@mkdir -p $(dir $@)
	$(CC) $(INCS) $(SDL_HEADER) -o $@ -c $<

clean:
#	@make clean -C $(LIBS)
#	@make clean -C ./minilibx
	@/bin/rm -rf $(OBJ_DIR)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] $(OBJ_DIR) folder deleted"

fclean: clean
	@/bin/rm -rf *.dSYM
#	@make fclean -C $(LIBS)
	@/bin/rm -f $(NAME)
	@echo "⚰  ["$(C_GREY) $(NAME) $(C_END)"] bin deleted"

sdl_install :
	curl https://dl.dropboxusercontent.com/u/22561204/SDL/Archive.zip > /tmp/Archive.zip
	unzip -o /tmp/Archive.zip -d ~/Library/Frameworks/

re: fclean $(NAME)

.PHONY: all clean clean2 fclean re fractol sdl_install
