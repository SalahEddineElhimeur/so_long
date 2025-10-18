NAME = so_long
CC = cc
BNAME = so_long_bonus
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC = main.c check_map.c check_map_helper.c check_name.c read_map.c img_init.c check_new_position.c ft_printf.c msg.c

BSRC= bonus/main_bonus.c bonus/check_map_bonus.c bonus/check_map_helper_bonus.c bonus/check_name_bonus.c bonus/ft_printf_bonus.c bonus/read_map_bonus.c bonus/img_init_bonus.c bonus/check_new_position_bonus.c bonus/msg_bonus.c

LIBSRC = libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c \
       libft/ft_isprint.c libft/ft_strlen.c libft/ft_memset.c libft/ft_bzero.c \
       libft/ft_memcpy.c libft/ft_memmove.c libft/ft_strlcpy.c libft/ft_strlcat.c \
       libft/ft_calloc.c libft/ft_strdup.c libft/ft_toupper.c libft/ft_tolower.c \
       libft/ft_strchr.c libft/ft_strncmp.c libft/ft_memchr.c libft/ft_memcmp.c \
       libft/ft_strnstr.c libft/ft_atoi.c libft/ft_strrchr.c libft/ft_substr.c \
       libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c \
       libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c \
       libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_lstnew_bonus.c libft/ft_lstadd_front_bonus.c \
       libft/ft_lstsize_bonus.c libft/ft_lstlast_bonus.c libft/ft_lstadd_back_bonus.c \
       libft/ft_lstdelone_bonus.c libft/ft_lstclear_bonus.c libft/ft_lstiter_bonus.c \
       libft/ft_lstmap_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c 

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)
LIBOBJ = $(LIBSRC:.c=.o)

INCLUDE = -Lminilibx-linux/ -lmlx -lXext -lX11

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBOBJ) $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBOBJ) $(INCLUDE)

bonus: $(BNAME)

$(BNAME): $(BOBJ) $(LIBOBJ)
	$(CC) $(CFLAGS)  -o $(BNAME) $(BOBJ) $(LIBOBJ) $(INCLUDE)

clean:
	@$(RM) $(OBJ) $(LIBOBJ) $(BOBJ)

fclean: clean
	@$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean bonus re
