# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pscott <pscott@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 13:54:38 by pscott            #+#    #+#              #
#    Updated: 2019/01/26 15:02:40 by pscott           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= gcc
WFLAGS	:= -Wall -Wextra -Werror
RM		:= rm -rf
NAME	:= ft_ls 

SRCDIR	:= srcs

SRC		:= ft_ls.c arg_parser.c errors.c options.c free.c print_helpers.c \
	ldir.c append_path.c opt_l.c open_once.c recursion.c time_utils.c xattr.c \
	link_utils.c sorting.c reverse_ft_strcmp.c devices_utils.c \
	permissions_utils.c options_adding.c add_sorted_ldir.c printf_select.c \
	get_uhlen.c ino.c failed_uid.c lreg.c get_max.c

INCL	:= -I includes/ -I libft/includes

LIBS	:= -L libft -lft
SRCS	:= $(addprefix $(SRCDIR)/, $(SRC))
LS		:= $(SRCS)

OBJS	:= $(LS:.c=.o)
DEPS	:= includes/ft_ls.h

COMP	:= $(CC) $(WFLAGS) $(INCL) $(LIBS)
OPT		:= -lR 

all: $(NAME)

libft/libft.a:
	$(MAKE) -C libft -j

d: all
	@./$(NAME) $(OPT)

ls: all
	@ls $(OPT)

$(NAME): $(OBJS) libft/libft.a Makefile
	$(COMP) -o $(NAME) $(LS)

%.o: %.c $(DEPS)
	$(CC) -o $@ -c $< $(WFLAGS) $(INCL)

clean:
	@make clean -C libft
	@$(RM) *dSYM*
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C libft
	@$(RM) $(NAME)
	@$(RM) a.out

re: fclean all

.PHONY: all clean fclean re d fsa val
