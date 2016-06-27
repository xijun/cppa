#CXX=g++
#CXXFLAGS= -Wall -Wextra -pedantic -std=c++14
#SRC= 	main.cc
#SRC:= $(addprefix src/, $(SRC))
#OBJ=$(SRC:.cc=.o)

#all: $(OBJ)
#		${CXX} ${CXXFLAGS} $^ -o out

#clean:
#		rm -rf $(OBJ) out build

.PHONY: all
all:
	cd build; \
	make all; \
	cd ..

.PHONY: check
check:
	cd build; \
	make check; \
	cd ..

.PHONY: clean
clean:
	cd build; \
	make clean; \
	cd ..; \
	rm -rf build/
