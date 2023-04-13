NAME 				=	fractol

INCLUDES			=	-I includes -I $(LIBFT_DIR)includes/ -I $(MLX_DIR)

LIBFT				=	$(LIBFT_DIR)libft.a
LIBFT_DIR			=	libft/
MLX					=	$(MLX_DIR)libmlx.a
MLX_DIR				=	mlx/
LIB_FLAGS			=	-L $(LIBFT_DIR) -lft -L $(MLX_DIR) -lmlx


CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
MINILIBX_FLAGS		=	-Lmlx -lmlx  -framework OpenGL -framework AppKit
RM					=	/bin/rm -f
NORM				=	norminette

DIR_SRCS			=	srcs
DIR_OBJS			=	objs
SUBDIRS				=	main frctl mlx

SRCS_PATHS			=	$(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRCS)/, $(dir)))
OBJS_PATHS			=	$(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRCS				=	$(foreach dir, $(SRCS_PATHS), $(wildcard $(dir)/*.c))
OBJS				=	$(subst $(DIR_SRCS), $(DIR_OBJS), $(SRCS:.c=.o))

$(DIR_OBJS)/%.o :	$(DIR_SRCS)/%.c
					mkdir -p $(DIR_OBJS) $(OBJS_PATHS)
					$(CC) $(CFLAGS) -Imlx $(INCLUDES) -c $< -o $@

all:				$(NAME)

$(LIBFT):
					make -C $(LIBFT_DIR)

$(MLX):
					make -C $(MLX_DIR)


$(NAME):			$(OBJS) $(LIBFT) $(MLX)
					$(CC) $(CFLAGS) $(MINILIBX_FLAGS) -o $(NAME) $(OBJS) $(LIB_FLAGS)

clean:
					make clean -C $(LIBFT_DIR)
					make clean -C $(MLX_DIR)
					$(RM) $(OBJS)
					$(RM) -r $(DIR_OBJS)

fclean:				clean
					make fclean -C $(LIBFT_DIR)
					$(RM) $(NAME)

re:					fclean all

norm:
					$(NORM) */*.h */*/*.c

.PHONY:				all clean fclean re norm
