NAME = so_long
NAMEB = so_long_bonus
CC = cc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror
FMLX = -lmlx -framework OpenGL -framework AppKit

SRC = ./Mandatory/so_long.c \
    ./Mandatory/object_enviro1.c \
    ./Mandatory/object_enviro2.c \
    ./Mandatory/initiali_destroy.c \
    ./Mandatory/get_nl/get_next_line_utils.c \
    ./Mandatory/get_nl/get_next_line.c \
    ./Mandatory/check_file_and_mp/check_maps_utils.c \
    ./Mandatory/check_file_and_mp/check_maps_utils1.c \
    ./Mandatory/check_file_and_mp/check_maps_utils2.c \
    ./Mandatory/check_file_and_mp/validation_file.c \
    ./Mandatory/lb_used/ft_strjoin.c \
    ./Mandatory/lb_used/ft_putchar_fd.c \
    ./Mandatory/lb_used/ft_calloc.c \
    ./Mandatory/lb_used/ft_bzero.c \
    ./Mandatory/lb_used/ft_putstr_fd.c \
    ./Mandatory/lb_used/ft_strdup.c \
    ./Mandatory/lb_used/ft_split.c \
    ./Mandatory/lb_used/ft_putendl_fd.c \
    ./Mandatory/lb_used/ft_strlen.c \
    ./Mandatory/lb_used/ft_substr.c tr_stderr.c

SRCB =  ./bonus/so_long.c \
    ./bonus/object_enviro1.c \
    ./bonus/object_enviro2.c \
    ./bonus/object_enviro3.c \
    ./bonus/initiali_destroy.c \
    ./bonus/get_nl/get_next_line_utils.c \
    ./bonus/get_nl/get_next_line.c \
    ./bonus/check_file_and_mp/check_maps_utils.c \
    ./bonus/check_file_and_mp/check_maps_utils1.c \
    ./bonus/check_file_and_mp/check_maps_utils2.c \
    ./bonus/check_file_and_mp/validation_file.c \
    ./bonus/lb_used/ft_bzero.c \
    ./bonus/lb_used/ft_calloc.c \
    ./bonus/lb_used/ft_putchar_fd.c \
    ./bonus/lb_used/ft_putendl_fd.c \
    ./bonus/lb_used/ft_strjoin.c \
    ./bonus/lb_used/ft_putnbr.c \
    ./bonus/lb_used/ft_split.c \
    ./bonus/lb_used/ft_strdup.c \
    ./bonus/lb_used/ft_strlen.c \
    ./bonus/lb_used/ft_substr.c tr_stderr.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(FMLX) $(OBJ) -o $(NAME)

bonus: $(OBJB)
	$(CC) $(FLAGS) $(FMLX) $(OBJB) -o $(NAMEB)

%.o: %.c Mandatory/so_long.h bonus/so_long.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJB)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAMEB)

re: fclean all

.PHONY: clean