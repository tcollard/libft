# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcollard <tcollard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 14:51:47 by tcollard          #+#    #+#              #
#    Updated: 2019/03/02 15:36:26 by jocohen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

END = \x1b[0m
GREEN = \x1b[32m

PATH_PRINTF = ft_printf/
PATH_LST = lst/
PATH_MATH = math/
PATH_MEM = mem/
PATH_PUT = put/
PATH_STR = str/
PATH_OTHER = others/

PATH_SRC = ./srcs/
INCS_LIB = ./includes/libft.h
INCS_PRINT = ./includes/ft_printf.h
PATH_OBJ = ./obj/

SRC = $(PATH_LST)ft_lstnew.c \
      $(PATH_LST)ft_lstdelone.c \
      $(PATH_LST)ft_ldbl_funcs.c \
      $(PATH_LST)ft_lstfind.c \
      $(PATH_LST)ft_lstsize.c \
      $(PATH_LST)ft_lstdel.c \
      $(PATH_LST)ft_lstadd.c \
      $(PATH_LST)ft_lstiter.c \
      $(PATH_LST)ft_lstmap.c \
      $(PATH_LST)ft_lst_push_back.c \
      $(PATH_LST)ft_lst_rev.c \
      $(PATH_MATH)ft_sqrt.c \
      $(PATH_MATH)ft_count_digit.c \
      $(PATH_MATH)ft_recursive_factorial.c \
      $(PATH_MATH)ft_itoa_base.c \
      $(PATH_MATH)ft_lenbyte.c \
      $(PATH_MEM)ft_memalloc.c \
      $(PATH_MEM)ft_memccpy.c \
      $(PATH_MEM)ft_memchr.c \
      $(PATH_MEM)ft_memcmp.c \
      $(PATH_MEM)ft_memcpy.c \
      $(PATH_MEM)ft_memdel.c \
      $(PATH_MEM)ft_memdel2.c \
      $(PATH_MEM)ft_memdel_0.c \
      $(PATH_MEM)ft_memmove.c \
      $(PATH_MEM)ft_memset.c \
      $(PATH_PUT)ft_putchar.c \
      $(PATH_PUT)ft_putchar_fd.c \
      $(PATH_PUT)ft_putendl.c \
      $(PATH_PUT)ft_putendl_fd.c \
      $(PATH_PUT)ft_putnbr.c \
      $(PATH_PUT)ft_putnbr_fd.c \
      $(PATH_PUT)ft_putstr.c \
      $(PATH_PUT)ft_putstr_fd.c \
      $(PATH_PUT)ft_putwstr.c \
      $(PATH_PUT)get_next_line.c \
      $(PATH_STR)ft_atoi.c \
      $(PATH_STR)ft_bzero.c \
      $(PATH_STR)ft_isalnum.c \
      $(PATH_STR)ft_isalpha.c \
      $(PATH_STR)ft_isascii.c \
      $(PATH_STR)ft_isdigit.c \
      $(PATH_STR)ft_isprint.c \
	  $(PATH_STR)ft_isspace.c \
      $(PATH_STR)ft_itoa.c \
      $(PATH_STR)ft_strcat.c \
      $(PATH_STR)ft_strcatc.c \
      $(PATH_STR)ft_strchr.c \
      $(PATH_STR)ft_strclr.c \
      $(PATH_STR)ft_strcmp.c \
      $(PATH_STR)ft_strcpy.c \
      $(PATH_STR)ft_strdel.c \
      $(PATH_STR)ft_strdup.c \
      $(PATH_STR)ft_strequ.c \
      $(PATH_STR)ft_striter.c \
      $(PATH_STR)ft_striteri.c \
      $(PATH_STR)ft_strjoin.c \
      $(PATH_STR)ft_strlcat.c \
      $(PATH_STR)ft_strlen.c \
      $(PATH_STR)ft_strmap.c \
      $(PATH_STR)ft_strmapi.c \
      $(PATH_STR)ft_strncat.c \
      $(PATH_STR)ft_strncmp.c \
      $(PATH_STR)ft_strncpy.c \
      $(PATH_STR)ft_strnequ.c \
      $(PATH_STR)ft_strnew.c \
      $(PATH_STR)ft_strnstr.c \
      $(PATH_STR)ft_strrchr.c \
      $(PATH_STR)ft_strrev.c \
      $(PATH_STR)ft_strsplit.c \
      $(PATH_STR)ft_splitwhitespace.c \
      $(PATH_STR)ft_strstr.c \
      $(PATH_STR)ft_strsub.c \
      $(PATH_STR)ft_strtrim.c \
      $(PATH_STR)ft_tolower.c \
      $(PATH_STR)ft_toupper.c \
      $(PATH_STR)ft_strwhcpy.c \
      $(PATH_STR)ft_strwhlen.c \
      $(PATH_STR)ft_twod_dup.c \
      $(PATH_STR)ft_unicode.c \
      $(PATH_STR)ft_wstrlen.c \
      $(PATH_PRINTF)apply_flag_hashtag.c \
      $(PATH_PRINTF)apply_flag_minus.c \
      $(PATH_PRINTF)apply_flag_plus.c \
      $(PATH_PRINTF)apply_flag_space.c \
      $(PATH_PRINTF)apply_flag_zero.c \
      $(PATH_PRINTF)check_all.c \
      $(PATH_PRINTF)conversion.c \
      $(PATH_PRINTF)conversion_nb.c \
      $(PATH_PRINTF)conversion_nb2.c \
      $(PATH_PRINTF)conversion_str.c \
      $(PATH_PRINTF)conversion_wchar.c \
      $(PATH_PRINTF)flag.c \
      $(PATH_PRINTF)ft_atoi_base.c \
      $(PATH_PRINTF)ft_itoa_base_neg.c \
      $(PATH_PRINTF)ft_itoa_base_ull.c \
      $(PATH_PRINTF)ft_itoa_ll.c \
      $(PATH_PRINTF)ft_printf.c \
      $(PATH_PRINTF)mask_wchar.c \
      $(PATH_PRINTF)modifier.c \
      $(PATH_PRINTF)precision.c \
      $(PATH_PRINTF)struct.c \
	  $(PATH_OTHER)ft_path.c

.PHONY: all clean fclean re build

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix $(PATH_SRC),$(SRC))
OBJS = $(addprefix $(PATH_OBJ), $(OBJ))

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(PATH_OBJ)%.o : $(PATH_SRC)%.c $(INCS_LIB) $(INCS_PRINT) Makefile
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_LST) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_MATH) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_MEM) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_PUT) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_STR) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_OTHER) 2> /dev/null || true
	@mkdir $(PATH_OBJ)$(PATH_PRINTF) 2> /dev/null || true
	@gcc $(CFLAGS) -I $(INCS_LIB) -I $(INCS_PRINT) -o $@ -c $<
	@echo " "
	@printf "\033[1A"
	@./progress_bar.sh $(NAME)

clean :
	@/bin/rm -f $(OBJS)
	@rmdir $(PATH_OBJ)$(PATH_LST) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_MATH) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_MEM) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_PUT) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_STR) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_STR) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_OTHER) 2> /dev/null || true
	@rmdir $(PATH_OBJ)$(PATH_PRINTF) 2> /dev/null || true
	@rmdir $(PATH_OBJ) 2> /dev/null || true

fclean : clean
	@/bin/rm -f $(NAME)
	@echo "$(NAME):\t\t$(GREEN)[CLEAN]$(END)"


re : fclean all
