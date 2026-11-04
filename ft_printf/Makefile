NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

COMMON_SRCS = ft_printf.c \
              ft_convert_unsigned_base.c \
              ft_write_integer.c \
              ft_write_text.c \
              ft_write_ptr.c

MANDATORY_SRCS = $(COMMON_SRCS) ft_process_conversion.c

BONUS_SRCS = $(COMMON_SRCS) $(wildcard ft_*_bonus.c)

ifeq ($(filter bonus,$(MAKECMDGOALS)),bonus)
	SRCS = $(BONUS_SRCS)
	MODE = bonus
else
	SRCS = $(MANDATORY_SRCS)
	MODE = mandatory
endif

OBJS = $(SRCS:.c=.o)

ALL_OBJS = $(MANDATORY_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

STAMP = .mode_$(MODE)

all: $(NAME)

bonus: $(NAME)

$(LIBFT): $(wildcard $(LIBFT_DIR)/*.c) $(LIBFT_DIR)/libft.h $(LIBFT_DIR)/Makefile
	$(MAKE) -C $(LIBFT_DIR)

$(STAMP):
	rm -f .mode_mandatory .mode_bonus
	touch $(STAMP)

$(NAME): $(OBJS) $(LIBFT) $(STAMP)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c ft_printf_bonus.h ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS)
	rm -f .mode_mandatory .mode_bonus
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re