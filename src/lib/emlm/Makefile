# ----------------------------------------Name
NAME = libmlm.a

# ----------------------------------------Files
FILES_SRCS =	vec1.cpp \
				vec2.cpp \
				vec3.cpp \
				vec4.cpp \
				mat4.cpp \
				angles.cpp \
				dot.cpp \
				abs.cpp \
				cross.cpp \
				normalize.cpp \
				mat4_transform.cpp \
				mat4_projection.cpp \
				lookat.cpp \

FILES_OBJS = $(FILES_SRCS:.cpp=.o)

# ----------------------------------------Directories
DIR_SRCS = ./src/
DIR_OBJS = ./obj/

vpath %.cpp $(DIR_SRCS)

# ----------------------------------------Sources
SRCS = $(FILES_SRCS:%=$(DIR_SRCS)%)

# ----------------------------------------Objects
OBJS = $(FILES_OBJS:%=$(DIR_OBJS)%)

CC = c++
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -O3
# CFLAGS += -fsanitize=address -g

all:
	@$(MAKE) $(NAME) -j4
.PHONY: all

$(NAME): $(DIR_OBJS) $(OBJS)
	ar -crs $(NAME) $(OBJS)

$(DIR_OBJS)%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(DIR_OBJS):
	mkdir -p $@



# ----------------------------------------Cleaning
clean:
	rm -f $(OBJS)
.PHONY: clean

fclean: clean
	rm -f $(NAME)
.PHONY: fclean

re: fclean all
.PHONY: re

# ----------------------------------------Tests
test: $(NAME)
	$(CC) $(CFLAGS) tests/*.cpp $(NAME) -o test
	./test
.PHONY: test