SRCS		= ./ft_printf.c \
			  ./ft_printf_utils.c \
			  ./ft_check.c \
			  ./ft_getlen.c \
			  ./ft_is.c \
			  ./ft_isrightcont.c \
			  ./ft_calc_print.c \
			  ./ft_print_c.c \
			  ./ft_print_d.c \
			  ./ft_print_p.c \
			  ./ft_print_percent.c \
			  ./ft_print_u.c \
			  ./ft_print_x.c \
			  ./ft_inputpad.c
	
LIBFTDIR	= ./libft/
LIBFT		= libft.a

NAME		= libftprintf.a
OBJS		= $(SRCS:.c=.o)
INCS		= .
RM			= rm -f
LIBC		= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) : $(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	cp $(LIBFTDIR)$(LIBFT) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFTDIR)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	make fclean -C $(LIBFTDIR)

re : fclean all

.PHONY: all clean fclean re
