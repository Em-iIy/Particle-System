# Created by: Emily (Em_iIy) Winnink
# Created on: 16/12/2024

# ----------------------------------------Name
NAME = particle-system

# ----------------------------------------Files
FILES_SRCS =	main.cpp \
				glad.cpp \
				delta_time_update.cpp \
				read_file.cpp \
				rand_vec3.cpp \
				split.cpp \
				Window.cpp \
				Key.cpp \
				Shader.cpp \
				ComputeShader.cpp \
				VAO.cpp \
				VBO.cpp \
				EBO.cpp \
				SSBO.cpp \
				bmp.cpp \
				textures.cpp \
				FrameBuffer.cpp \
				RenderBuffer.cpp \
				RenderText.cpp \
				Config.cpp \
				timer.cpp \
				App_init.cpp \
				App_input.cpp \
				App_loop.cpp \
				App_delete.cpp \

FILES_OBJS = $(FILES_SRCS:.cpp=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/
DIR_INC = ./inc/
DIR_EMLM = $(DIR_SRCS)lib/emlm/

vpath %.cpp	$(DIR_SRCS) \
			$(DIR_SRCS)lib/ \
			$(DIR_SRCS)lib/bmp/ \
			$(DIR_SRCS)utils/ \
			$(DIR_SRCS)utils/gl/ \

# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

# ----------------------------------------Libs
EMLM = $(DIR_EMLM)libmlm.a

# ----------------------------------------Flags
CC = c++
CFLAGS = -std=c++20
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -O3
# CFLAGS += -g
# CFLAGS += -g -fsanitize=address

UNAME = $(shell uname)

FREE_TYPE_FLAGS = -I/usr/include/freetype2 -I/usr/include/libpng16

# Linux flags
ifeq ($(UNAME), Linux)
	LFLAGS = -lglfw -ldl -lfreetype
endif
# Apple flags
ifeq ($(UNAME), Darwin)
	LFLAGS = -lglfw3 -framework Cocoa -framework OpenGL -framework -lfreetype IOKit
endif

INC =	-I$(DIR_INC) \
		-I$(DIR_SRCS) \
		-I$(DIR_SRCS)utils/ \
		-I$(DIR_SRCS)lib/ \

INC += $(FREE_TYPE_FLAGS)

all:
	$(MAKE) $(NAME) -j4
.PHONY: all

$(NAME): $(DIR_OBJS) $(OBJS) $(EMLM)
	$(CC) $(OBJS) -o $(NAME) $(EMLM) $(CFLAGS) $(LFLAGS) $(INC)

$(DIR_OBJS)%.o: %.cpp
	$(CC) -c $< -o $@ $(CFLAGS) $(INC)

$(DIR_OBJS):
	mkdir -p $@

$(EMLM):
	$(MAKE) -j4 -C $(DIR_EMLM)

clean:
	$(MAKE) -C $(DIR_EMLM) clean
	rm -f $(OBJS)
.PHONY: clean

fclean: clean
	$(MAKE) -C $(DIR_EMLM) fclean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re
