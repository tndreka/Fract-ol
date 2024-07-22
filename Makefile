# # **************************************************************************** #
# #                                                                              #
# #                                                         :::      ::::::::    #
# #    Makefile                                           :+:      :+:    :+:    #
# #                                                     +:+ +:+         +:+      #
# #    By: tndreka <tndreka@student.42.fr>            +#+  +:+       +#+         #
# #                                                 +#+#+#+#+#+   +#+            #
# #    Created: 2024/07/21 18:47:07 by tndreka           #+#    #+#              #
# #    Updated: 2024/07/21 19:22:38 by tndreka          ###   ########.fr        #
# #                                                                              #
# # **************************************************************************** #

NAME    := fractol
CFLAGS  := -Wextra -Wall -Werror -Wunreachable-code -Ofast
LIBMLX  := ./MLX42
HEADERS := -I ./include -I $(LIBMLX)/include
LIBS    := $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
SRCS    := $(shell find ./src -iname "*.c")
OBJS    := ${SRCS:.c=.o}
all: libmlx $(NAME)
libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"
$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
clean:
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
fclean: clean
	@rm -rf $(NAME)
re: clean all
.PHONY: all, clean, fclean, re, libmlx