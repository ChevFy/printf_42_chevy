

NAME        = libftprintf.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar rcs
RM          = rm -f

# Directories
SRC_DIR     = .
OBJ_DIR     = obj
LIBFT_DIR   = libft

# Source files
SRC_FILES   = ft_printf \
              ft_print_utils \
              ft_print_ptr \
              ft_print_unsigned \
              ft_print_hex

SRC         = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
OBJ         = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@echo "libftprintf.a created!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I. -I$(LIBFT_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)
	@echo "Object files cleaned."

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_DIR)/libft.a
	@echo "All cleaned."

re: fclean all

.PHONY: all clean fclean re
