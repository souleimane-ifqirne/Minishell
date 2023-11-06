##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile a function with the whole lib
##

NAME	= libmy.a

RM	= rm -f

SRCS	= 	./lib/my/my_putchar.c		\
		./lib/my/my_printf_4.c          \
		./lib/my/my_printf_3.c          \
		./lib/my/my_printf_2.c		\
		./lib/my/my_printf.c		\
		./lib/my/my_getnbr.c		\
		./lib/my/my_strncat.c		\
		./lib/my/my_put_nbr.c		\
		./lib/my/my_strcat.c		\
	 	./lib/my/my_isneg.c		\
		./lib/my/my_strncmp.c		\
		./lib/my/my_putstr.c		\
		./lib/my/my_strcmp.c		\
		./lib/my/my_strlen.c		\
		./lib/my/my_swap.c		\
		./lib/my/my_strncpy.c		\
		./lib/my/my_revstr.c		\
		./lib/my/my_strcpy.c		\
		./lib/my/my_str_to_word_array.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -I ./
CFLAGS	+= -Wall -Wextra

all:	$(NAME)

$(NAME): $(OBJS)
	 ar rc $(NAME) $(OBJS)
	 rm lib/my/*.o
	 gcc main.c my_exit.c my_getenv.c my_env.c my_cd.c my_setenv.c my_unsetenv.c my_path.c my_cd2.c -L. -lmy -o mysh

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
