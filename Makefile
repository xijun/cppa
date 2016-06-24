CXX=g++
CXXFLAGS= -Wall -Wextra -pedantic -std=c++14
SRC= 	main.cc
SRC:= $(addprefix src/, $(SRC))
OBJ=$(SRC:.cc=.o)

all: $(OBJ)
		${CXX} ${CXXFLAGS} $^ -o $@

clean:
		rm -rf $(OBJ)
