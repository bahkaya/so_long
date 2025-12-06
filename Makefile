NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT =./libft/libft.a
PRINTF =./printf/libftprintf.a


MLX_DIR = minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz

SRCS_GET_NEXT_LINE =	\
./get_next_line/get_next_line.c			\
./get_next_line/get_next_line_utils.c


SRCS = \
	so_long.c \
	ft_check_map.c

OBJS = $(SRCS:.c=.o) 
OBJS_GET_NEXT_LINE = $(SRCS_GET_NEXT_LINE:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(OBJS_GET_NEXT_LINE) $(LIBFT) $(PRINTF) $(MLX_LIB)
	@$(CC) $(CFLAGS) $(OBJS) $(OBJS_GET_NEXT_LINE) $(PRINTF) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C ./libft
$(PRINTF):
	@make -C ./printf

$(MLX_LIB):
	@make -s -C $(MLX_DIR)

%.o: %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(LIBFT)
	@rm -f $(PRINTF)
	@rm -f $(OBJS)
	@rm -f $(OBJS_GET_NEXT_LINE)
	@make clean -C ./libft
	@make clean -C ./printf
	

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make fclean -C ./printf

re: fclean all

test:
	@$(CC) $(CFLAGS) $(OBJS) test.c

.PHONY: all clean fclean re