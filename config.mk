SRC		=	src/main.cpp	\

CFLAGS	=	-O2 -Wall -Wextra -Iinclude/

LFLAGS	=	-O2

CC		=	g++

OBJ		=	$(patsubst %.cpp,%.o,$(SRC))

TARGET	=	yes
