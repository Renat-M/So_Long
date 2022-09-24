MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit
NAME = so_long
SRC = ft_parcer.c ft_parcer2.c ft_movements.c ft_draw_map.c so_long.c
HEAD = so_long.h
INCLUDES = -I$(HEAD) -Ilibft/libft.h -Imlx/mlx.h
GCC = clang
OBJ = $(patsubst %.c, %.o, $(SRC))
LIBFT = ./libft/

all: $(NAME)

$(NAME): $(OBJ) $(HEAD)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C mlx
	# $(GCC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	cp mlx/libmlx.dylib libmlx.dylib
	$(GCC) libft/libft.a $(INCLUDES) $(OBJ) $(MLX) -o $(NAME)
%.o: %.c $(HEAD) libft/libft.h
	$(GCC) -c -Iso_long.h -Ilibft/libft.h -Imlx $< -o $@
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT) clean
fclean: clean 
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re