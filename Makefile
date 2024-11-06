# Variables
CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
SRCS = \
    ft_isalpha.c \
    ft_isdigit.c \
    ft_isalnum.c \
    ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

OBJS = $(SRCS:.c=.o)
NAME = libft.a

# Phony targets
.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Create the library
$(NAME): $(OBJS)
	$(AR) rcs $@ $^

# Compile source files into object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create the shared library (so target)
SO_NAME = libft.so
so: $(OBJS)
	# Recompile object files with -fPIC
	$(CC) $(CFLAGS) -fPIC $(PICFLAGS) -c $(SRCS)
	$(CC) -shared -o $(SO_NAME) $(OBJS)

# Clean object files
clean:
	rm -f $(OBJS)

# Clean object files and the library
fclean: clean
	rm -f $(NAME)

# Rebuild the library
re: fclean all
