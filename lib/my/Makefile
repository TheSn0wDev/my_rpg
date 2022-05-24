##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Compile mylibrary
##

CC		=	gcc
CFLAGS	=	-W -Wall -Wextra

SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)
TARGET	= libmy.a

all: $(OBJ) lib

lib:
	@ $(AR) rsc $(TARGET) $(OBJ)
	@ cp my.h ../../includes/
	@ echo "\033[1;32m[+]\t\033[1;34m$(TARGET)\033[0m"

clean:
	@ $(RM) $(OBJ)
	@ $(RM) *~
	@ $(RM) #*#

fclean: clean
	@ $(RM) $(LIB)
	@ $(RM) libmy.a
	@ $(RM) ../libmy.a
	@ $(RM) ../../includes/my.h

re: fclean all