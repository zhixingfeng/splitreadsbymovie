CC = g++
INCLUDES = 
CXX_FLAGS = -pthread -std=c++11 -w -O3 -lz

SRC = $(wildcard *.cpp) 

OBJ = $(SRC:.cpp=.o)

all: mkbin igda rmobj
	
.PHONY: mkbin
mkbin:
	mkdir -p bin
	
igda: $(OBJ) 
	$(CC) -o bin/splitreadsbymovie $^ $(CXX_FLAGS)

%.o: %.cpp
	$(CC) $(INCLUDES) -c $< -o $@ $(CXX_FLAGS)

rmobj:
	rm -f $(OBJ)

.PHONY: clean
clean:
	rm -rf bin

